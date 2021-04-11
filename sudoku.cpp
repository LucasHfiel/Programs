#include <iostream>
#define N 9

using namespace std;

int grid[N][N] = {
    //Input grid, 0's are empty spots
    {0, 0, 0, 2, 0, 0, 0, 0, 0},
    {0, 4, 9, 0, 0, 7, 5, 0, 0},
    {8, 0, 3, 5, 0, 0, 0, 0, 0},
    {0, 2, 0, 0, 5, 0, 0, 0, 0},
    {9, 7, 0, 8, 0, 6, 0, 3, 4},
    {0, 0, 0, 0, 4, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 5, 7, 0, 6},
    {0, 0, 7, 3, 0, 0, 1, 4, 0},
    {0, 0, 0, 0, 0, 9, 0, 0, 0}
};

bool isInColumn(int column, int number){
    for(int row = 0; row < N; row++){
        if(grid[row][column] == number){
            return true;
        }
    }
    return false;
}

bool isInRow(int row, int number){
    for(int column = 0; column < N; column++){
        if(grid[row][column] == number){
            return true;
        }
    }
    return false;
}

bool isInBox(int boxRow, int boxColumn, int number){
    for(int row = 0; row < 3; row++){
        for(int column = 0; column < 3; column++){
            if(grid[row+boxRow][column+boxColumn] == number){
                return true;
            }
        }
    }
    return false;
}

void printGrid(){
    for(int row = 0; row < N; row++){
        for(int column = 0; column < N; column++){
            if(column == 3 || column == 6){
                cout << "   ";
            }
            cout << grid[row][column] << " ";
        }
        if(row == 2 || row == 5){
            cout << endl;
            for(int i = 0; i < N; i++){
                cout << "   ";
            }
        }
        cout << endl;
    }
}

bool isEmptySpace(int &row, int &column){
    for(row = 0; row < N; row++){
        for(column = 0; column < N; column++){
            if(grid[row][column] == 0){
                return true;
            }
        }
    }
    return false;
}

bool isValid(int row, int column, int number){
    return !isInRow(row, number) && !isInColumn(column, number) && !isInBox((row - row % 3), (column - column % 3), number);
}

bool solve(){
    int row, column;
    if(!isEmptySpace(row, column)){
        return true; //all spots filled
    }
    for(int number = 1; number <= 9; number++){
        if(isValid(row, column, number)){
            grid[row][column] = number;
            if(solve() == true){
                return true; //Backtracking
            }
            grid[row][column] = 0;
        }
    }
    return false;
}

int main(){
    if(solve() == true){
        printGrid();
    }
    else{
        cout << "Unsolvable" << "\n";
    }
}
