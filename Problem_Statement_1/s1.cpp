#include <iostream>
#include <string>
using namespace std;

int main(){
  int row,column,generation;
cin>>row;
cin>>column;
cin>>generation;


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


int initialpopulation=0;
for(int i=0;i<row;i++){
    for(int j=0;j<column;j++){
         if(grid[i][j]=='#'){initialpopulation++;}
    }
}

int peakpop=initialpopulation;
cout<<endl<<endl<<endl;

for(int g=0 ; g<generation; g++){

    for(int i=0;i<row;i++){
        for(int j=0; j<column ; j++){

             int count=0;

             for(int k=0;k<8;k++){
                int ndi=i+dr[k];
                int ndj=j+dc[k];
                      if( ndi>=0 && ndj>=0 && ndi<row && ndj<column && grid[ndi][ndj]=='#')
              {count++;}}
            
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

int pop=0;
for(int i=0;i<row;i++){
    for(int j=0;j<column;j++){
         if(grid[i][j]=='#'){pop++;}
    }
}
if(pop>peakpop){peakpop=pop;}
        }




int finalpopulation=0;
for(int i=0;i<row;i++){
    for(int j=0;j<column;j++){
         if(grid[i][j]=='#'){finalpopulation++;}
    }
}

cout<<"Initial Population: "<<initialpopulation<<endl;
cout<<"Final Population:"<<finalpopulation<<endl;
cout<<"Peak Population: "<<peakpop<<endl;

cout<<"Final Grid: "<<endl;
  for(int i=0;i<row;i++){
        for(int j=0; j<column ; j++){
            cout<<newgrid[i][j];
        }
        cout<<endl;
    }
    return 0;
}






