#include<bits/stdc++.h>
using namespace std;
int grid[9][9];
//Function declarations
bool solve_grid();      //main function that does the solving
bool vacant(int &row, int &col); //finds a vacant row and col
bool trial(int row, int col, int num); //chks if the number is correct


//Functions definition
bool solve_grid(){
    int row=0, col=0;
    if(!vacant(row, col)) return true;

    for(int num=1; num<=9; num++){
        if(trial(row, col, num)){
            grid[row][col]=num;
            if(solve_grid())
                return true; //If it fits go deep
            grid[row][col]=0;
        }
    }
    return false; //If nothinbg among 1 to 9 fits
}

bool trial(int row, int col, int num){
    //flag=true;
    for(int i=0; i<9; i++){
        if(grid[i][col]==num)return false;
    }
    for(int i=0; i<9; i++){
        if(grid[row][i]==num)return false;
    }
    int st_row=row-row%3, st_col=col-col%3;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(grid[i+st_row][j+st_col]==num){
                return false;
            }
        }
    }
    return true;
}

bool vacant(int &row, int &col){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(grid[i][j]==0){
                row=i;
                col=j;
                return true; //Still vacant left
            }
        }
    }
    return false; //Solved
}

int main(){
    ios_base(0);
    cin.tie(0);cout.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    //9x9 grid with blanks as 0


    //Input from user
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin>>grid[i][j];
        }
    }

    if(!solve_grid()){
        cout<<"Cannot be solved!";
        return 0;
    }

    //Output from user
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }

   return 0;
}
