#include "play.h"
#include <iostream>
using namespace std;

string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
int player = 1;
int position = 0;

void Introduction() {
    cout << "Press [Enter] to begin: ";
    cin.ignore();
    cout << "\n";

    cout << "-----------------------------\n";
    cout << "Welcome to my TicTacToe game!\n";
    cout << "-----------------------------\n\n";

    cout << "Player 1) X\n";
    cout << "Player 2) O\n\n";

    cout << "Here's the 3 x 3 grid:\n\n";

    cout << "     |     |      \n";
    cout << "  1  |  2  |  3   \n";
    cout << "_____|_____|_____ \n";
    cout << "     |     |      \n";
    cout << "  4  |  5  |  6   \n";
    cout << "_____|_____|_____ \n";
    cout << "     |     |      \n";
    cout << "  7  |  8  |  9   \n";
    cout << "     |     |      \n\n";
}

void PlayingTheGame() {
    while ( !IsWinner() && !FilledUp()) {

        SetPosition();

        UpdateBoard();

        ChangePlayer();

        Draw();
    }
}

void SetPosition() {
    cout << "Player " << player << "'s Turn (Enter 1-9): ";

    while (!(cin >> position)) {
        cout << "Player " << player << ", please enter a valid number between 1 and 9: ";
        cin.clear();
        cin.ignore();

    }
    cout << "\n";

    while (board[position-1] != " ") {
        cout << "Oops, there's already something in that position!\n\n";

        cout << "Player " << player << "'s Turn (Enter 1-9): ";
        cin >> position;

        cout << "\n";
    }
}

void UpdateBoard() {
    if (player % 2 == 1) {
        board[position - 1] = "X";
    }
    else {
        board[position - 1] = "O";
    }
}

void ChangePlayer() {
    if (player == 1) {
        player++;
    }
    else {
        player--;
    }
}

void Draw() {
    cout << "     |     |      \n";
    cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
    cout << "_____|_____|_____ \n";
    cout << "     |     |      \n";
    cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
    cout << "_____|_____|_____ \n";
    cout << "     |     |      \n";
    cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
    cout << "     |     |      \n";
    cout << "\n";
}

bool IsWinner() {
    bool winner = false;
    // Checks rows
    if ((board[0] == board[1]) && (board[1] == board[2]) && board[0] != " ") {
        winner = true;
    } else if ((board[3] == board[4]) && (board[3] == board[5]) && board[3] != " ") {
        winner = true;
    } else if ((board[6] == board[7]) && (board[6] == board[8]) && board[6] != " ") {
        winner = true;
    }
    // Checks columns
    else if ((board[0] == board[3]) && (board[0] == board[6]) && board[0] != " ") {
        winner = true;
    } else if ((board[1] == board[4]) && (board[1] == board[7]) && board[1] != " ") {
        winner = true;
    } else if ((board[2] == board[5]) && (board[2] == board[8]) && board[2] != " ") {
        winner = true;
    } // Checks diagonals
    else if ((board[0] == board[4]) && (board[0] == board[8]) && board[0] != " ") {
        winner = true;
    }
    else if ((board[2] == board[4]) && (board[2] == board[6]) && board[2] != " ") {
        winner = true;
    }

    return winner;
}

bool FilledUp() {
    bool filled = true;
    for (int i = 0; i < 9; i++) {
        if (board[i] == " ") {
            filled = false;
        }
    }
    return filled;
}

void EndGame() {
    if (IsWinner()) {
        cout << "There's a winner!\n";
    }
    else if (FilledUp()) {
        cout << "There's a tie!\n";
    }
}