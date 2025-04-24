#include <stdio.h>
#include <conio.h>

int N;  // Number of queens

// Function to print the board
void print(int board[10][10]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (board[i][j])
                printf("Q ");
            else
                printf("- ");
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if it's safe to place a queen
int isSafe(int board[10][10], int row, int col) {
    int i, j;

    // Check column above
    for (i = 0; i < row; i++)
        if (board[i][col])
            return 0;

    // Check upper-left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    // Check upper-right diagonal
    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return 0;

    return 1;
}

// Recursive function to solve the N-Queen problem
int solve(int board[10][10], int row) {
    int col;
    int found = 0;

    if (row >= N) {
        print(board);
        return 1;
    }

    for (col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            found = solve(board, row + 1) || found;
            board[row][col] = 0;  // backtrack
        }
    }
    return found;
}

// Function to initialize the board and solve
void solveNQ() {
    int board[10][10];
    int i, j;

    // Initialize the board with 0
    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++)
            board[i][j] = 0;

    if (!solve(board, 0))
        printf("No solution exists\n");
}

int main() {
    // clrscr();  // Turbo C specific
    printf("Enter the number of queens: ");
    scanf("%d", &N);

    if (N > 10) {
        printf("N should be <= 10 for this program.\n");
    } else {
        solveNQ();
    }

    getch();  // Turbo C specific
    return 0;
}
