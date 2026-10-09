#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Class representing a Bender
class Bender {
public:
    string name;
    string element;
    int hp;
    int maxhp;
    int attack;
    int defence;
    int speed;
    vector<pair<string, int>> moves;

    Bender(string name, string element, int hp, int attack, int defence, int speed, vector<pair<string, int>> moves)
        : name(name), element(element), hp(hp), maxhp(hp), attack(attack), defence(defence), speed(speed), moves(moves) {}

    bool is_fainted() const {
        return hp <= 0;
    }
};

// Class to manage the Duel system
class Duel {
private:
    Bender bender1;
    Bender bender2;
    int total_turns;
    int total_crit_hits;
    int total_super_effective_hits;

    // Helper method to determine type multiplier and relationship label
    pair<double, string> get_type_multiplier(const string& attacker_elem, const string& defender_elem) {
        if ((attacker_elem == "Water" && defender_elem == "Fire") ||
            (attacker_elem == "Fire" && defender_elem == "Air") ||
            (attacker_elem == "Air" && defender_elem == "Earth") ||
            (attacker_elem == "Earth" && defender_elem == "Water")) {
            return {2.0, "Super Effective"};
        } 
        else if ((defender_elem == "Water" && attacker_elem == "Fire") ||
                 (defender_elem == "Fire" && attacker_elem == "Air") ||
                 (defender_elem == "Air" && attacker_elem == "Earth") ||
                 (defender_elem == "Earth" && attacker_elem == "Water")) {
            return {0.5, "Weak"};
        }
        return {1.0, "Neutral"};
    }

    // Execute an attack turn from attacker to target
    void execute_attack(Bender& attacker, Bender& target, int move_index) {
        string move_name = attacker.moves[move_index].first;
        int move_power = attacker.moves[move_index].second;

        cout << attacker.name << " used " << move_name << "!" << endl;

        if (move_power == 0) {
            cout << target.name << " took 0 damage!" << endl;
            cout << target.name << " HP: " << target.hp << "/" << target.maxhp << endl << endl;
            return;
        }

        // 1. Base Damage Calculation
        double base_damage = (double)(attacker.attack * move_power) / target.defence;

        // 2. Type Advantage Calculation
        auto [type_mult, relationship] = get_type_multiplier(attacker.element, target.element);
        
        if (relationship == "Super Effective") {
            cout << "Super Effective! (" << attacker.element << " is strong against " << target.element << ")" << endl;
            total_super_effective_hits++;
        } else if (relationship == "Weak") {
            cout << "Not very effective... (" << attacker.element << " is weak against " << target.element << ")" << endl;
        }

        // 3. Critical Hit Calculation (10% chance)
        bool is_critical = ((double)rand() / RAND_MAX) < 0.10;
        double crit_mult = is_critical ? 2.0 : 1.0;
        
        if (is_critical) {
            cout << "Critical Hit!" << endl;
            total_crit_hits++;
        }

        // 4. Final Damage Formula
        double raw_final = base_damage * type_mult * crit_mult;
        int final_damage = max(1, (int)round(raw_final));

        target.hp = max(0, target.hp - final_damage);

        cout << target.name << " took " << final_damage << " damage!" << endl;
        cout << target.name << " HP: " << target.hp << "/" << target.maxhp << endl << endl;
    }

public:
    Duel(Bender b1, Bender b2) 
        : bender1(b1), bender2(b2), total_turns(0), total_crit_hits(0), total_super_effective_hits(0) {}

    void start_duel() {
        cout << "=== DUEL BEGINS! ===" << endl;
        cout << bender1.name << " (" << bender1.element << ", HP: " << bender1.hp << "/" << bender1.maxhp << ") VS "
             << bender2.name << " (" << bender2.element << ", HP: " << bender2.hp << "/" << bender2.maxhp << ")" << endl << endl;

        // Determine speed order
        Bender* first;
        Bender* second;
        bool is_speed_tie = false;

        if (bender1.speed > bender2.speed) {
            first = &bender1;
            second = &bender2;
        } else if (bender2.speed > bender1.speed) {
            first = &bender2;
            second = &bender1;
        } else {
            is_speed_tie = true;
            if (rand() % 2 == 0) {
                first = &bender1;
                second = &bender2;
            } else {
                first = &bender2;
                second = &bender1;
            }
        }

        Bender* attacker = first;
        Bender* defender = second;

        while (!bender1.is_fainted() && !bender2.is_fainted()) {
            total_turns++;
            cout << "Turn " << total_turns << ": ";

            if (total_turns == 1) {
                if (is_speed_tie) {
                    cout << "Speed tie! " << attacker->name << " goes first! (Speed: " << attacker->speed << " vs " << defender->speed << ")" << endl;
                } else {
                    cout << attacker->name << " goes first! (Speed: " << attacker->speed << " vs " << defender->speed << ")" << endl;
                }
            } else {
                cout << attacker->name << " goes first!" << endl;
            }

            // Pick move (Auto mode defaults to standard attack logic/moves[0] or random)
            int move_choice = 0; 
            execute_attack(*attacker, *defender, move_choice);

            if (defender->is_fainted()) {
                cout << defender->name << " fainted!" << endl;
                cout << "🏆 " << attacker->name << " wins the duel!" << endl << endl;
                break;
            }

            // Swap attacker and defender for the remaining turn sequence
            swap(attacker, defender);
        }

        // Output summary stats
        Bender* winner = bender1.is_fainted() ? &bender2 : &bender1;
        cout << "Duel Summary:" << endl;
        cout << "- Winner: " << winner->name << endl;
        cout << "- Turns: " << total_turns << endl;
        cout << "- Critical Hits: " << total_crit_hits << endl;
        cout << "- Super Effective Hits: " << total_super_effective_hits << endl;
    }
};

int main() {
    // Seed random generator
    srand(time(0));

    // Example Test Case: Kael vs Mira
    Bender kael("Kael", "Fire", 100, 58, 38, 88,
                 {{"Ember Slash", 40}, {"Quick Jab", 30}, {"Focus", 0}, {"Flame Surge", 70}});

    Bender mira("Mira", "Water", 92, 50, 45, 60,
                 {{"Water Whip", 35}, {"Tide Push", 25}, {"Mist Veil", 0}, {"Tidal Wave", 60}});

    Duel duel(kael, mira);
    duel.start_duel();

    return 0;
}