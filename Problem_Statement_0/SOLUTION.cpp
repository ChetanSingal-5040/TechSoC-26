#include <iostream>
using namespace std;


void  result(double wt[],int num){
            
           

            double total_wt;
            for(int i=0;i<num;i++){
                total_wt= total_wt + wt[i]; 
            }
              cout<<"Total  Shipment   weight: "<<total_wt<<endl;
              cout<<"Average container weight: "<<total_wt/num<<endl;

            double max_wt=wt[0];
            double min_wt=wt[0];
            
             for(int j=0;j<num;j++){
                if(wt[j]>max_wt){
                     max_wt=wt[j];
                }
               
             }

             for( int k=0;k<num;k++){
                      if (wt[k]<min_wt){
                        min_wt=wt[k];
                         }
                }
             
               cout<<"Lightest container:"<<min_wt<<endl;  
               cout<<"Heaviest container:"<<max_wt<<endl;

               
                 int max_capacity;
                 cout<<"Port capacity: ";cin>>max_capacity;



             if(total_wt>200){

           cout<<"Classification: heavy"<<endl;
             }
             else cout<<"Classification : light"<<endl;



             if(total_wt>max_capacity){
                cout<<"Shipment exceeds port capacity"<<endl;
              }
             else if (total_wt==max_capacity){
                cout<<"Exactly full"<<endl;
             }
             else cout<<"Shipment can be unloaded"<<endl;  
    
             
             
        }

int main(){
    
 
  int num;
  

    cout<<"No. of containers: "<<endl;
    do {cin>>num;} while(num<1 || num>1000);

    double wt[num];

    for(int i=0;i<num;i++){
        cout<<"Enter weight of "<<(i+1)<<" container: ";cin>>wt[i];
    };
    cout<<endl<<endl;
    result(wt,num);

  
    return 0;

}
 