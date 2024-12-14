#include<bits/stdc++.h>
using namespace std;

void printSudoku(int sudoku[][9]){
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"--------------------------------------------------------------------------------------"<<endl;
}

bool isSafe(int sudoku[9][9],int row, int col, int digit){

    //Vertically
    for(int i=0;i<=8;i++){
        if(sudoku[i][col] == digit){
            return false;
        }
    }

    //Horizontally
    for(int j=0;j<=8;j++){
        if(sudoku[row][j] == digit){
            return false;
        }
    }

    //In the 3x3 grid
    int startRow = (row/3) * 3;
    int startCol = (col/3) * 3;

    for(int i=startRow;i<=startRow + 2;i++){
        for(int j=startCol;j<=startCol + 2;j++){
            if(sudoku[i][j] == digit){
                return false;
            }
        }
    }

    return true;
}

bool sudokuSolver(int sudoku[9][9],int row,int col){
    if(row == 9){
        printSudoku(sudoku);  //sudoku solved
        return true;
    }

    int nextRow = row;
    int nextCol = col +1;
    if (col + 1 == 9)
    {
        nextRow = row + 1;
        nextCol = 0;
    }
    
    if(sudoku[row][col] != 0){
        return sudokuSolver(sudoku,nextRow,nextCol);
    }

    for (int digit = 1; digit <= 9; digit++)
    {
        if(isSafe(sudoku,row,col,digit)){
            sudoku[row][col] = digit;
            if(sudokuSolver(sudoku,nextRow,nextCol)){
                return true;
            }
            sudoku[row][col] = 0;
        }
    }
    
    return false;
}

int main(){
    cout<<"WELCOME TO SUDOKU SOLVER"<<endl;
    cout<<"Note:- enter the blank spaces with 0"<<endl;
    int sudoku[9][9];
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>sudoku[i][j];
        }
    }
    cout<<endl;
    cout<<"solved sudoku is"<<endl;
    sudokuSolver(sudoku,0,0);
    return 0;
}