#include <iostream>
using namespace std;


bool isSafe(int** board, int row, int col, int N) {

    for (int c = 0; c < col; c++) {
        if (board[row][c] == 1) return false;
    }


    for (int r = row, c = col; r >= 0 && c >= 0; r--, c--) {
        if (board[r][c] == 1) return false;
    }


    for (int r = row, c = col; r < N && c >= 0; r++, c--) {
        if (board[r][c] == 1) return false;
    }

    return true; 
}


bool solveNQueens(int** board, int col, int N) {

    if (col >= N) return true;

    for (int row = 0; row < N; row++) {

        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;

            if (solveNQueens(board, col + 1, N)) return true;


            board[row][col] = 0; 
        }
    }

    return false; 
}


void printSolution(int** board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl; 
    }
}

int main() {
    int N;
    cout << "Enter the number of queens ";
    cin >> N;

    int** board = new int*[N];
    for (int i = 0; i < N; i++) {
        board[i] = new int[N]();
    }

    if (solveNQueens(board, 0, N)) {
        printSolution(board, N);
    } else {
        cout << "No solution exists" << endl;
    }

    for (int i = 0; i < N; i++) {
        delete[] board[i];
    }
    delete[] board;

    return 0;
}
