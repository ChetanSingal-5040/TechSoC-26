#include <iostream>
#include <string>
using namespace std;

int main(){
    cout<<"Classify"<<endl;
  int row,column;
cin>>row;
cin>>column;

string input;

char grid[row][column];
char newgrid[row][column];

int dr[8]={-1,-1,-1,0,0,1,1,1};
int dc[8]={-1,0,1,-1,1,0,-1,1};


for(int i=0;i<row;i++){
    cin>>input;
    for(int j=0;j<column;j++){
        grid[i][j]=input[j];
    }
}  

for(int g=0 ; g<10; g++){

    for(int i=0;i<row;i++){
        for(int j=0; j<column ; j++){

             int count=0;
             for(int k=0;k<8;k++){
               int ndi=(i+dr[k]+row)%row;
               int ndj=(j+dc[k]+column)%column;
                         if( grid[ndi][ndj]=='#') {count++;}}
  
                   
  if(grid[i][j]=='#'){
                if(count>3 || count<2){
                    newgrid[i][j]='.';
                }
                else newgrid[i][j]='#'; }
  if(grid[i][j]=='.'){
                if(count==3){newgrid[i][j]='#';}
                else newgrid[i][j]='.';}                   
  
    }}

           for(int i=0;i<row;i++){
        for(int j=0; j<column ; j++){
            grid[i][j]=newgrid[i][j];

        }}


}



cout<<"Classification: "<<
return 0;
        }









