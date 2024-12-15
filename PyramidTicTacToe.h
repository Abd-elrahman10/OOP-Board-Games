#ifndef _PYRAMID_TICTACTOE_H
#define _PYRAMID_TICTACTOE_H

#include "BoardGame_Classes.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <cctype>

using namespace std;

template <typename T>
class PyramidTicTacToe : public Board<T> {
public:
    PyramidTicTacToe();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
};


template <typename T>
class PyramidPlayer : public Player<T> {
public:
    PyramidPlayer(string name, T symbol);
    void getmove(int& x, int& y);
};

template <typename T>
class PyramidRandomPlayer : public RandomPlayer<T> {
public:
    PyramidRandomPlayer(string name,T symbol);
    void getmove(int& x, int& y);
};

//--------------------------------------- IMPLEMENTATION

template <typename T>
PyramidTicTacToe<T>::PyramidTicTacToe() {
    this->rows = 3;
    this->board = new T*[this->rows];
    this->n_moves = 0;

    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new T[2 * i + 1];
        for (int j = 0; j < 2 * i + 1; j++) {
            this->board[i][j] = 0;
        }
    }
}

template <typename T>
bool PyramidTicTacToe<T>::update_board(int x, int y, T symbol) {
    if (x >= 0 && x < this->rows && y >= 0 && y < 2 * x + 1 && this->board[x][y] == 0) {
        this->board[x][y] = symbol;
        this->n_moves++;
        return true;
    }
    return false;
}

template <typename T>
void PyramidTicTacToe<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << string((this->rows - i - 1) * 4, ' ');

        for (int j = 0; j < 2 * i + 1; j++) {
            cout << "|(" << i << "," << j << ") ";
            if (this->board[i][j] != 0) {
                cout << this->board[i][j];
            }
            cout << "| ";
        }
        cout << endl;
    }

    cout << string(4 * this->rows, '-') << endl;
}


template <typename T>
bool PyramidTicTacToe<T>::is_win() {

    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (j + 2 < i + 3 &&
                this->board[i][j] != 0 &&
                this->board[i][j] == this->board[i][j + 1] &&
                this->board[i][j] == this->board[i][j + 2]) {

                return true;
            }
        }
    }


    for (int i = 0; i < this->rows - 2; i++) {
        for (int j = 0; j < i + 3; j++) {
            if (this->board[i][j] != 0 &&
                this->board[i][j] == this->board[i + 1][j] &&
                this->board[i][j] == this->board[i + 2][j]) {

                return true;
            }
        }
    }


    for (int i = 0; i < this->rows - 2; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (this->board[i][j] != 0 &&
                this->board[i][j] == this->board[i + 1][j + 1] &&
                this->board[i][j] == this->board[i + 2][j + 2]) {

                return true;
            }
            if (j + 2 < i + 3 &&
                this->board[i][j + 2] != 0 &&
                this->board[i][j + 2] == this->board[i + 1][j + 1] &&
                this->board[i][j + 2] == this->board[i + 2][j]) {

                return true;
            }
        }
    }

    return false;
}

template <typename T>
bool PyramidTicTacToe<T>::is_draw() {
if(this->n_moves==9 && !this->is_win()){
    return true;
}

    return false;
}

template <typename T>
bool PyramidTicTacToe<T>::game_is_over() {
    return is_win() || is_draw();
}


template <typename T>
PyramidPlayer<T>::PyramidPlayer(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void PyramidPlayer<T>::getmove(int& x, int& y) {
    cout << "\n" << this->name << ", enter your move (row and column): ";
    cin >> x >> y;
}


template <typename T>
PyramidRandomPlayer<T>::PyramidRandomPlayer(string name,T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = name;
    srand(static_cast<unsigned int>(time(0)));
}

template <typename T>
void PyramidRandomPlayer<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;
    y = rand() % (2 * x + 1);
}

#endif //_PYRAMID_TICTACTOE_H
