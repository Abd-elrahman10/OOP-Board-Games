#ifndef _ULTIMATETICTACTOE_CLASSES_H
#define _ULTIMATETICTACTOE_CLASSES_H

#include "BoardGame_Classes.h"

template <typename T>
class UltimateTicTacToeBoard : public Board<T> {
private:
    T smallBoards[3][3][3][3];
    int smallBoardMoves[3][3];

public:
    UltimateTicTacToeBoard();
    bool update_board(int x, int y, T symbol) override;
    void display_board() override;
    bool is_win() override;
    bool is_draw() override;
    bool game_is_over() override;
    bool is_small_board_win(int smallX, int smallY, T symbol);
};

template <typename T>
class UltimateTicTacToePlayer : public Player<T> {
public:
    UltimateTicTacToePlayer(std::string name, T symbol);
    void getmove(int& x, int& y) override;
};

template <typename T>
class UltimateTicTacToeRandomPlayer : public RandomPlayer<T> {
public:
    UltimateTicTacToeRandomPlayer(string name,T symbol);
    void getmove(int& x, int& y) override;
};

#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
UltimateTicTacToeBoard<T>::UltimateTicTacToeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            smallBoardMoves[i][j] = 0;
            for (int x = 0; x < 3; x++) {
                for (int y = 0; y < 3; y++) {
                    smallBoards[i][j][x][y] = 0;
                }
            }
        }
    }
    this->rows = this->columns = 3;
    this->board = new T*[3];
    for (int i = 0; i < 3; i++) {
        this->board[i] = new T[3];
        for (int j = 0; j < 3; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}

template <typename T>
bool UltimateTicTacToeBoard<T>::update_board(int x, int y, T symbol) {
    int smallX = x / 3, smallY = y / 3;
    int localX = x % 3, localY = y % 3;

    if (this->board[smallX][smallY] == 0) {
        if (smallBoards[smallX][smallY][localX][localY] == 0) {
            smallBoards[smallX][smallY][localX][localY] = symbol;
            smallBoardMoves[smallX][smallY]++;

            if (is_small_board_win(smallX, smallY, symbol)) {
                this->board[smallX][smallY] = symbol;
            } else if (smallBoardMoves[smallX][smallY] == 9) {
                this->board[smallX][smallY] = '-';
            }

            this->n_moves++;
            return true;
        }
    }
    return false;
}

template <typename T>
bool UltimateTicTacToeBoard<T>::is_small_board_win(int smallX, int smallY, T symbol) {
    for (int i = 0; i < 3; i++) {
        if (smallBoards[smallX][smallY][i][0] == symbol &&
            smallBoards[smallX][smallY][i][1] == symbol &&
            smallBoards[smallX][smallY][i][2] == symbol) {
            return true;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (smallBoards[smallX][smallY][0][i] == symbol &&
            smallBoards[smallX][smallY][1][i] == symbol &&
            smallBoards[smallX][smallY][2][i] == symbol) {
            return true;
        }
    }

    if (smallBoards[smallX][smallY][0][0] == symbol &&
        smallBoards[smallX][smallY][1][1] == symbol &&
        smallBoards[smallX][smallY][2][2] == symbol) {
        return true;
    }
    if (smallBoards[smallX][smallY][0][2] == symbol &&
        smallBoards[smallX][smallY][1][1] == symbol &&
        smallBoards[smallX][smallY][2][0] == symbol) {
        return true;
    }

    return false;
}

template <typename T>
void UltimateTicTacToeBoard<T>::display_board() {
    cout << endl;
    cout << "    0   1    2     3    4    5     6    7    8" << endl;
    for (int i = 0; i < 3; i++) {
        for (int row = 0; row < 3; row++) {
            cout  << i * 3 + row << " : ";
            for (int j = 0; j < 3; j++) {
                for (int col = 0; col < 3; col++) {

                    T cell = smallBoards[i][j][row][col];
                    cout << (cell == 0 ? ' ' : cell);
                    if (col < 2) cout << " | ";
                }
                if (j < 2) cout << "  |||  ";
            }

            cout << endl;
        }
        if (i < 2) cout << string(39, '-') << endl;
    }
    cout << "Main Board:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char cell = this->board[i][j] == 0 ? ' ' : this->board[i][j];
            cout << " " << cell << " ";
            if (j < 2) {
                cout << "|";
            }
        }
        cout << endl;

        if (i < 2) {
            cout << "-----------" << endl;
        }
    }
    cout << endl;
}


template <typename T>
bool UltimateTicTacToeBoard<T>::is_win() {
    for (int i = 0; i < 3; i++) {
        if ((this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && this->board[i][0] != 0) ||
            (this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i] && this->board[0][i] != 0)) {
            return true;
        }
    }
    if ((this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != 0) ||
        (this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[0][2] != 0)) {
        return true;
    }
    return false;
}

template <typename T>
bool UltimateTicTacToeBoard<T>::is_draw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (this->board[i][j] == 0) {
                return false;
            }
        }
    }
    return !is_win();
}

template <typename T>
bool UltimateTicTacToeBoard<T>::game_is_over() {
    return is_win() || is_draw();
}

template <typename T>
UltimateTicTacToePlayer<T>::UltimateTicTacToePlayer(std::string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void UltimateTicTacToePlayer<T>::getmove(int& x, int& y) {
    cout << '\n'<<this->getname()<<",Please enter your move (x and y, 0 to 8): ";
    cin >> x >> y;
    while (x < 0 || x > 8 || y < 0 || y > 8) {
        cout << "Invalid move. Coordinates must be between 0 and 8. Try again: ";
        cin >> x >> y;
    }
}

template <typename T>
UltimateTicTacToeRandomPlayer<T>::UltimateTicTacToeRandomPlayer(string name,T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 9;
    this->name = name;
    srand(static_cast<unsigned int>(time(0)));
}

template <typename T>
void UltimateTicTacToeRandomPlayer<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;
    y = rand() % this->dimension;
}

#endif //_ULTIMATETICTACTOE_CLASSES_H