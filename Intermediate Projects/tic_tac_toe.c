#include <stdio.h>
#include <stdlib.h>

void board_game(char board[3][3])
{
    printf("\nCurent Board: \n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void initialize_board(char board[3][3]) {
    char num = '1';
    for (int i = 0; i<3; i++) {
        for (int j = 0; j< 3; j++) {
            board[i][j] = num++;
        }
    }
}

char winner(char board[3][3]) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == 'X') return 'X';
            if (board[i][0] == 'O') return 'O';
        }
    }
    
    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            if (board[0][j] == 'X') return 'X';
            if (board[0][j] == 'O') return 'O';
        }
    }
    
    // Check diagonal (top-left to bottom-right)
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'X') return 'X';
        if (board[0][0] == 'O') return 'O';
    }
    
    // Check diagonal (top-right to bottom-left)
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == 'X') return 'X';
        if (board[0][2] == 'O') return 'O';
    }
    
    // Check for tie (board full)
    int full = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                full = 0;
                break;
            }
        }
        if (!full) break;
    }
    
    if (full) return 'T'; // Tie
    return 'N'; // No winner yet
}

int main()
{
    char board[3][3];
    initialize_board(board);
    board_game(board);

    int position;
    int row, col;
    char result;
    
    do {
        // Player 1 (X)
        printf("Enter the position of X from player 1 in the board [1-9]: ");
        scanf("%d", &position);
        
        if (position >= 1 && position <= 9) {
            row = (position - 1) / 3;
            col = (position - 1) % 3;
            
            // Check if position is already taken
            if (board[row][col] != 'X' && board[row][col] != 'O') {
                board[row][col] = 'X';
                board_game(board);
                
                result = winner(board);
                if (result != 'N') break;
                
                // Player 2 (O)
                printf("Enter the position of O from player 2 in the board [1-9]: ");
                scanf("%d", &position);
                
                if (position >= 1 && position <= 9) {
                    row = (position - 1) / 3;
                    col = (position - 1) % 3;
                    
                    if (board[row][col] != 'X' && board[row][col] != 'O') {
                        board[row][col] = 'O';
                        board_game(board);
                    } else {
                        printf("Position already taken! Try again.\n");
                        continue;
                    }
                } else {
                    printf("Invalid position! Try again.\n");
                    continue;
                }
            } else {
                printf("Position already taken! Try again.\n");
                continue;
            }
        } else {
            printf("Invalid position! Try again.\n");
            continue;
        }
        
        result = winner(board);
    } while(result == 'N');
    
    // Print result
    if (result == 'X') {
        printf("Player 1 (X) wins!\n");
    } else if (result == 'O') {
        printf("Player 2 (O) wins!\n");
    } else if (result == 'T') {
        printf("It's a tie!\n");
    }
    
    return 0;
}