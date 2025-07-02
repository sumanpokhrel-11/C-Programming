// Declare a 2D array of characters (a char matrix) to store a simple grid, like a tic-tac-toe board. Initialize it with empty spaces.

#include <stdio.h>

#define ROW 3
#define COL 3
int main() {
    int val = 1;
    char matrix[ROW][COL];
    for(int i= 0; i<ROW; i++) {
        for(int j = 0; j<COL; j++) {
            printf(" %d ", val);
            val++;
        }
        printf("\n");
    }
    return 0;
}