#include <iostream>
using namespace std;

void  result(double wt[],int num){
            
double total_wt;
for(int i=0;i<num;i++){  total_wt= total_wt + wt[i]; 
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
                cout<<"Shipment exceeds port capacity"<<endl<<endl;
              }
             else if (total_wt==max_capacity){
                cout<<"Exactly full"<<endl<<endl;
             }
             else cout<<"Shipment can be unloaded"<<endl<<endl;  


cout<<"BAR CHART OF WEIGHT OF CONTAINER  "<<endl;
        for(int i=0;i<num;i++){
            cout<<"wt of "<<(i+1)<<": ";
            
            for(int j=0;j<wt[i];j++){
                cout<<"*";
            }
            cout<<endl;
        }
    cout<<endl;
 double search_wt;
 bool found=false;
 cout<<"Search of container by wt(enter wt): ";cin>>search_wt;
 for(int i=0;i<num;i++){
            if(search_wt==wt[i] ) {cout<<(i+1)<<endl<<endl;found =true;} 
            else continue;
            }
if(!found){cout<<"No such container"<<endl<<endl;}
               }









int main(){
    
  int num;
  cout<<"No. of containers: "<<endl;
do {cin>>num;} while(num<1 || num>1000); // as 1<=n<=1000

double wt[num];

    for(int i=0;i<num;i++){
        cout<<"Enter weight of "<<(i+1)<<" container: ";cin>>wt[i];
    };
    cout<<endl<<endl;
    result(wt,num);

    cout<<"Sorting: "<<endl;
    for (int i= 0; i<num; i++) {
    for (int j = i + 1; j <num; j++) {
        if (wt[i] > wt[j]) {
            double temp = wt[i];
            wt[i] = wt[j];
            wt[j] = temp;
        }
        
    }
    
     cout<<wt[i]<<" ";
    
}
    cout<<endl;
int k;cout<<"Enter value of k for kth heaviest container: "; cin>>k;
cout<<wt[num-k];
   
  
    return 0;

}
 











