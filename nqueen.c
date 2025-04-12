#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define N 8

int board[N]; 

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}


bool solveNQ(int row) {
    if (row == N) { 
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%s ", board[i] == j ? "Q" : ".");
            }
            printf("\n");
        }
        printf("\n");
        return true;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            if (solveNQ(row + 1)) return true;
        }
    }

    return false;
}

int main() {
    if (!solveNQ(0)) {
        printf("Solution does not exist\n");
    }
    return 0;
}
