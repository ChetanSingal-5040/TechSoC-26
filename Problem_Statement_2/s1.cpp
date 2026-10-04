#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Bender{
public:
       string name;
       string element;
       int hp,attack,defence,speed,maxhp;
       
       vector<pair<string,int>> moves;

         
       Bender(string name,string element, int hp,int attack,int defence,int speed,vector<pair<string,int>> moves)
       : name(name),element(element),hp(hp),maxhp(hp),attack(attack),defence(defence),speed(speed),moves(moves){}

    

       string display_stats(){
        string ans= name + '(' + element + ')' + " - HP: "+ to_string(hp) +"/" +to_string(maxhp)+
                   ", Attack: "+to_string(attack)+", Defence: "+ to_string(defence)+", Speed: "+to_string(speed)+
                   "\nMoves: ";
              for(auto i:moves){
                ans+= i.first+"("+ to_string(i.second)+"), ";
              }     
            return ans;
       }

       void attack_on(Bender& defender,int index){
            int damage= round((attack*moves[index].second) / (double)defender.defence) ;
            cout<<name<<" used "<<moves[index].first<<"! "<<endl;
            cout<<defender.name<<" took "<< damage <<" damage! "<<endl<<endl;
           if(defender.hp-damage>0) defender.hp -=damage;
           else defender.hp=0;
       }
    
      string  faint_stats(){
        if(hp==0) return "True";
        else return "False";

      }
     
};
 

int main(){
 /*   Bender Kael("Kael", "Fire", 100, 58, 38, 88,{{"Ember Slash", 40}, {"Quick Jab", 30}, {"Focus", 0}, {"Flame Surge", 70}});
    Bender Mira("Mira", "Water", 92, 50, 45, 60, {{"Water Whip", 35}, {"Tide Push", 25}, {"Mist Veil", 0}, {"Tidal Wave", 60}});
           
   cout<< Kael.display_stats()<<endl<<endl;
   cout<< Mira.display_stats()<<endl<<endl;

    Kael.attack_on(Mira,0);
    cout<<Mira.display_stats()<<endl<<endl;

   cout<<"Mira Fainted: "<<Mira.faint_stats()<<endl;  */


   Bender zephyr("Zephyr", "Air", 28, 12, 50, 95,{{"Gust", 0}, {"Wind Slap", 18}, {"Tumble", 12}, {"Cyclone", 22}});
   Bender Doran("Doran", "Earth", 145, 80, 75, 40,{{"Boulder Throw", 75}, {"Rock Fist", 42}, {"Tremor", 48}, {"Mountain Crush", 85}}) ;
                   
   cout<<zephyr.display_stats()<<endl<<endl;
   cout<<Doran.display_stats()<<endl<<endl;

   Doran.attack_on(zephyr, 0);
   cout<<zephyr.display_stats()<<endl<<endl;

   cout<<"zephyr fainted: "<<zephyr.faint_stats()<<endl;

    return 0;
}
