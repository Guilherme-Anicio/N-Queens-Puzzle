#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 8

bool isSafe(bool board[BOARD_SIZE][BOARD_SIZE], int row, int col) {

    //Check previous col
    for(int i = 0; i < row; i++) {
        if(board[i][col] == true){
            return false;
        }
    }

    //Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == true) {
            return false;
        }
    }

    //Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < BOARD_SIZE; i--, j++) {
        if (board[i][j] == true) {
            return false;
        }
    }

    return true;

}

void printResult(bool board[BOARD_SIZE][BOARD_SIZE]) {

    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++){
            if(board[i][j]){
                printf("Q ");
            } else{
                printf("- ");
            }
        }
        printf("\n");
    }

}

bool solveNQueensProblem(bool board[BOARD_SIZE][BOARD_SIZE], int row) {

    if(row == BOARD_SIZE) {
        printResult(board);
        return true;
    }

    for(int col = 0; col < BOARD_SIZE; col++) {

        if(isSafe(board, row, col)) {

            board[row][col] = true;

            if(solveNQueensProblem(board, row+1)) {
                return true;
            }

            //If path taken does not lead to a solution, remove the queen and go to the next column
            board[row][col] = false;
        }

    }

    return false;

}

void main() {

    bool board[BOARD_SIZE][BOARD_SIZE] = {false};

    bool result = solveNQueensProblem(board, 0);

    if(!result) {
        printf("This board has no solution.");
    }

}


