#include <iostream>
using namespace std;


void printBoard(char board[3][3]);
bool checkWin(char board[3][3], char player);
bool checkDraw(char board[3][3]);
bool isValidMove(char board[3][3], int row, int col);
void switchPlayer(char &currentPlayer);

int main() 
{
    char board[3][3] = { {' ', ' ', ' '},
                         {' ', ' ', ' '},
                         {' ', ' ', ' '} };
    char currentPlayer = 'X';
    bool gameOver = false;
    int row, col;

    cout << "Welcome to Tic-Tac-Toe!\n";
    cout << "Player 1 (X) - Player 2 (O)\n\n";

    while (!gameOver) 
    {
        // Print the board
        printBoard(board);

        // Get player move
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the move is valid
        while (!isValidMove(board, row, col)) 
        {
            cout << "Invalid move! Try again: ";
            cin >> row >> col;
        }

        // Make the move
        board[row][col] = currentPlayer;

        // Check for win
        if (checkWin(board, currentPlayer)) 
        {
            // Print the final board
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            gameOver = true;
        } else if (checkDraw(board)) 
        {
            // Print the final board
            printBoard(board);
            cout << "It's a draw!\n";
            gameOver = true;
        } else
        {
            // Switch to the other player
            switchPlayer(currentPlayer);
        }
    }

    // Ask if players want to play again
    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') 
    {
        // Reset the board
        for (int i = 0; i < 3; ++i) 
        {
            for (int j = 0; j < 3; ++j) 
            {
                board[i][j] = ' ';
            }
        }
        // Reset currentPlayer and gameOver flag
        currentPlayer = 'X';
        gameOver = false;
        main(); // Restart the game
    } else 
    {
        cout << "Thank you for playing Tic-Tac-Toe!\n";
    }

    return 0;
}

void printBoard(char board[3][3]) 
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) 
        {
            cout << board[i][j];
            if (j < 2) 
            {
                cout << " | ";
            }
        }
        cout << endl;
        if (i < 2) 
        {
            cout << "---------\n";
        }
    }
    cout << endl;
}

bool checkWin(char board[3][3], char player) 
{
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) 
        {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) 
    {
        return true;
    }

    return false;
}

bool checkDraw(char board[3][3]) 
{
    // Check if there are any empty spaces left
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) 
        {
            if (board[i][j] == ' ') 
            {
                return false;
            }
        }
    }
    // If no empty spaces left, it's a draw
    return true;
}

bool isValidMove(char board[3][3], int row, int col) 
{
    // Check if the chosen cell is within bounds and empty
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

void switchPlayer(char &currentPlayer) 
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}



