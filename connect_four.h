#ifndef _CONNECT_FOUR_H
#define _CONNECT_FOUR_H

#include "BoardGame_Classes.h"
#include <bits/stdc++.h>

template <typename T>
class ConnectFourBoard : public Board<T> {
public:
    ConnectFourBoard();
    bool update_board(int x, int y, T symbol);
    void display_board();//done
    bool is_win();//done
    bool is_draw();//done
    bool game_is_over();//done
};

template <typename T>
class ConnectFourPlayer : public Player<T> {
public:
    ConnectFourPlayer(string name, T symbol);
    void getmove(int&x ,int& y);


};

template <typename T>
class ConnectFourRandomPlayer : public RandomPlayer<T> {
public:
    ConnectFourRandomPlayer(string name,T symbol);
    void getmove(int& x, int& y);


};

#endif //_CONNECT_FOUR_H


///--------------------------------------- IMPLEMENTATION


using namespace std;

// Constructor for ConnectFourBoard
template <typename T>
ConnectFourBoard<T>::ConnectFourBoard() {
    this->rows = 6;  // Standard Connect Four rows
    this->columns = 7;  // Standard Connect Four columns
    this->board = new T*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new T[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;  // Initialize the board to be empty
        }
    }
    this->n_moves = 0;
}

template <typename T>
bool ConnectFourBoard<T>::update_board(int x, int y, T symbol) {
    // Check if the move is valid (within bounds and the cell is empty)
    for (int i = 5; i >= 0;) {//5


        if (y >= 0 && y < this->columns && this->board[i][y] == 0) {
            this->board[i][y] = symbol;
            this->n_moves++;
            return true;
            break;
        }
        else
            i--;

    }
    return false;
}
template <typename T>
void ConnectFourBoard<T>::display_board() {
    cout<<endl;
    cout<< "  0"<<"  "<<" 1"<<"  "<<" 2"<<"  "<<" 3"<<"  "<<" 4"<<"  "<<" 5"<<"  "<<" 6"<<endl;
    for (int i = 0; i < this->rows; i++) {
        cout << "| ";
        for (int j = 0; j < this->columns; j++) {
            cout << this->board[i][j] << " | ";
        }
        cout << "\n-----------------------------\n";
    }
    cout<<endl;
}

template <typename T>
bool ConnectFourBoard<T>::is_win() {
    // Check for horizontal, vertical, and diagonal wins
    // Horizontal check
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->columns - 3; j++) {
            if (this->board[i][j] != 0 &&
                this->board[i][j] == this->board[i][j + 1] &&
                this->board[i][j] == this->board[i][j + 2] &&
                this->board[i][j] == this->board[i][j + 3]) {
                return true;
            }
        }
    }

    // Vertical check
    for (int i = 0; i < this->rows - 3; i++) {
        for (int j = 0; j < this->columns; j++) {
            if (this->board[i][j] != 0 &&
                this->board[i][j] == this->board[i + 1][j] &&
                this->board[i][j] == this->board[i + 2][j] &&
                this->board[i][j] == this->board[i + 3][j]) {
                return true;
            }
        }
    }

    // Diagonal (downward) check
    for (int i = 0; i < this->rows - 3; i++) {
        for (int j = 0; j < this->columns - 3; j++) {
            if (this->board[i][j] != 0 &&
                this->board[i][j] == this->board[i + 1][j + 1] &&
                this->board[i][j] == this->board[i + 2][j + 2] &&
                this->board[i][j] == this->board[i + 3][j + 3]) {
                return true;
            }
        }
    }

    // Diagonal (upward) check
    for (int i = 3; i < this->rows; i++) {
        for (int j = 0; j < this->columns - 3; j++) {
            if (this->board[i][j] != 0 &&
                this->board[i][j] == this->board[i - 1][j + 1] &&
                this->board[i][j] == this->board[i - 2][j + 2] &&
                this->board[i][j] == this->board[i - 3][j + 3]) {
                return true;
            }
        }
    }

    return false;
}

template <typename T>
bool ConnectFourBoard<T>::is_draw() {
    return (this->n_moves == this->rows * this->columns && !is_win());
}

template <typename T>
bool ConnectFourBoard<T>::game_is_over() {
    return is_win() || is_draw();
}

//--------------------------------------

// Constructor for ConnectFourPlayer
template <typename T>
ConnectFourPlayer<T>::ConnectFourPlayer(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void ConnectFourPlayer<T>::getmove( int& x, int& y) {
    cout << endl<<this->getname()<<" " <<"symbol("<<this->getsymbol()<<")"<<" ,please enter your move (column 0 to 6): ";
    cin >> y;

    // Find the first available row in the selected column

}

// Constructor for ConnectFourRandomPlayer
template <typename T>
ConnectFourRandomPlayer<T>::ConnectFourRandomPlayer(string name, T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 7;  // Columns in Connect Four
    this->name = name;
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

template <typename T>
void ConnectFourRandomPlayer<T>::getmove(int& x,int& y) {
    y = rand() % this->dimension;  // Random column selection (0 to 6)

    // Find the first available row in the selected column

}
