#ifndef _5X5_TIC_TAC_TOE_H
#define _5X5_TIC_TAC_TOE_H

#include "BoardGame_Classes.h"

template <typename T>
class TicTacToe_Board : public Board<T> {
public:
    TicTacToe_Board();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
    int count_three_in_a_row(T symbol);
    void check_scores();
    int score1, score2;
};

template <typename T>
class TicTacToe_Player : public Player<T> {
public:
    TicTacToe_Player(string name, T symbol);
    void getmove(int& x, int& y);
};

template <typename T>
class TicTacToe_Random_Player : public RandomPlayer<T> {
public:
    TicTacToe_Random_Player(string name,T symbol);
    void getmove(int& x, int& y);
};

//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;


int global_n_moves = 0;

// Constructor for TicTacToe_Board
template <typename T>
TicTacToe_Board<T>::TicTacToe_Board() {
    this->rows = this->columns = 5;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
    global_n_moves = 0;
    score1 = score2 = 0;
}

template <typename T>
bool TicTacToe_Board<T>::update_board(int x, int y, T mark) {
    if (global_n_moves == 25) {
        return true;
    }

    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0)) {
        this->n_moves++;
        global_n_moves++;
        this->board[x][y] = toupper(mark);
        check_scores();
        cout << "\nScores after move:\n";
        cout << "Player X: " << score1 << " | Player O: " << score2 << "\n";
        return true;
    }
    return false;
}

// Display the board and the pieces on it
template <typename T>
void TicTacToe_Board<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n----------------------------------------------";
    }
    cout << "\nScores:\n";
    cout << "Player X: " << score1 << " | Player O: " << score2 << "\n";
    cout << endl;
}


template <typename T>
int TicTacToe_Board<T>::count_three_in_a_row(T symbol) {
    int count = 0;

    // Check all horizontal, vertical, and diagonal lines
    // Horizontal lines
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j <= this->columns - 3; j++) {
            if (this->board[i][j] == symbol && this->board[i][j + 1] == symbol && this->board[i][j + 2] == symbol) {
                count++;
            }
        }
    }

    // Vertical lines
    for (int i = 0; i <= this->rows - 3; i++) {
        for (int j = 0; j < this->columns; j++) {
            if (this->board[i][j] == symbol && this->board[i + 1][j] == symbol && this->board[i + 2][j] == symbol) {
                count++;
            }
        }
    }

    // Diagonals (top-left to bottom-right)
    for (int i = 0; i <= this->rows - 3; i++) {
        for (int j = 0; j <= this->columns - 3; j++) {
            if (this->board[i][j] == symbol && this->board[i + 1][j + 1] == symbol && this->board[i + 2][j + 2] == symbol) {
                count++;
            }
        }
    }

    // Diagonals (top-right to bottom-left)
    for (int i = 0; i <= this->rows - 3; i++) {
        for (int j = 2; j < this->columns; j++) {
            if (this->board[i][j] == symbol && this->board[i + 1][j - 1] == symbol && this->board[i + 2][j - 2] == symbol) {
                count++;
            }
        }
    }

    return count;
}

// Check and update scores based on the current board state
template <typename T>
void TicTacToe_Board<T>::check_scores() {
    score1 = count_three_in_a_row('X');
    score2 = count_three_in_a_row('O');
}

// Check for a winner
template <typename T>
bool TicTacToe_Board<T>::is_win() {
    if (this->n_moves == 24) {
        check_scores();
        if (score2 > score1) { // Player O wins

            return true;
        } else if (score1 > score2) {
            this->n_moves++;
            global_n_moves++;
            return false;
        }
    } else if (this->n_moves == 25) {
        check_scores();
        if (score1 > score2) { // Player X wins
cout<<"Player X wins";
            return true;
        }

    }
    return false;
}

// draw condition
template <typename T>
bool TicTacToe_Board<T>::is_draw() {
    return (this->n_moves == 24 && score1 == score2);
}

template <typename T>
bool TicTacToe_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

//--------------------------------------

// Constructor for TicTacToe_Player
template <typename T>
TicTacToe_Player<T>::TicTacToe_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void TicTacToe_Player<T>::getmove(int& x, int& y) {
    if (global_n_moves == 25) {
        x = 0;
        y = 0;
        return;
    }
    cout << "\nPlease enter your move x and y (0 to 4) separated by spaces: ";
    cin >> x >> y;
}

// Constructor for TicTacToe_Random_Player
template <typename T>
TicTacToe_Random_Player<T>::TicTacToe_Random_Player(string name,T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 5;
    this->name = name;
    srand(static_cast<unsigned int>(time(0)));
}

template <typename T>
void TicTacToe_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;
    y = rand() % this->dimension;
}

#endif //_5X5_TIC_TAC_TOE_H