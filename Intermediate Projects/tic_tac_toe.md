## Tic Tac Toe Game Logic

### 1. Initialize the Game Board

- Create a 3x3 2D array (e.g., `char board[3][3]`).
- Fill all cells with a neutral character (such as a space `' '` or numbers `'1'` through `'9'` to represent empty, selectable cells).

### 2. Display the Board

- Implement a function to print the current state of the 3x3 game board to the console.
- Clearly indicate which cells are empty and which contain `'X'` or `'O'`.
- Call this function repeatedly after each move.

### 3. Player Turns and Input

- Establish two players (e.g., Player 1 uses `'X'`, Player 2 uses `'O'`).
- Use a loop for game turns that continues until there is a winner or a draw.
- For each turn:
    - Prompt the current player to enter their move (e.g., a number from 1 to 9 corresponding to a cell).
    - **Validate the input:**
        - Ensure the input is a valid number (1-9).
        - Check if the chosen cell is empty.
        - If invalid or taken, reprompt until a valid, empty cell is chosen.
    - Update the board with the current player's mark (`'X'` or `'O'`).

### 4. Check for Game End Condition

- After each valid move, check if the game has ended:
    - **Winning Condition:**
        - Check all rows, columns, and both diagonals for three identical marks.
        - If found, declare the current player as the winner and end the game.
    - **Draw Condition:**
        - If all cells are filled and no winner, declare a draw and end the game.

### 5. Switch Players

- If the game hasn't ended, switch to the other player for the next turn.

### 6. Game Over

- Once a win or draw condition is met:
    - Display the final board.
    - Announce the result (winner or draw).
