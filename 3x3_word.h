#ifndef INC_3X3_WORD_H
#define INC_3X3_WORD_H

#include "BoardGame_Classes.h"

template <typename T>
class Word_Board : public Board<T> {
public:
    Word_Board();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
};

template <typename T>
class Word_Player : public Player<T> {
public:
    Word_Player(string name,T symbol);
    void getmove(int &x, int &y);
};

template <typename T>
class Word_Random_Player : public RandomPlayer<T> {
public:
    Word_Random_Player(string name,T symbol);
    void getmove(int &x, int &y);
};

#include <iostream>
#include <iomanip>
#include <cctype>
#include <fstream>
#include <string>
#include <set>
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename T>
Word_Board<T>::Word_Board() {
    this->rows = this->columns = 3;
    this->board = new char *[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}

template <typename T>
bool Word_Board<T>::update_board(int x, int y, T mark) {
    if (x >= 0 && x < this->rows && y >= 0 && y < this->columns && (this->board[x][y] == 0 || mark == 0)) {
        if (mark == 0) {
            this->n_moves--;
            this->board[x][y] = 0;
        } else {
            this->n_moves++;
            this->board[x][y] = toupper(mark);
        }
        return true;
    }
    return false;
}

template <typename T>
void Word_Board<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

template <typename T>
bool Word_Board<T>::is_win() {
    set<string> dictionary;

    ifstream file("dic.txt");
    string line;
    while (getline(file, line)) {
        dictionary.insert(line);
    }
    file.close();

    string word;

    for (int i = 0; i < this->rows; i++) {
        word = "";
        for (int j = 0; j < this->columns; j++) {
            word += this->board[i][j];
        }
        if (dictionary.find(word) != dictionary.end()) {
            return true;
        }
    }

    for (int i = 0; i < this->columns; i++) {
        word = "";
        for (int j = 0; j < this->rows; j++) {
            word += this->board[j][i];
        }
        if (dictionary.find(word) != dictionary.end()) {
            return true;
        }
    }

    word = "";
    for (int i = 0; i < this->rows; i++) {
        word += this->board[i][i];
    }
    if (dictionary.find(word) != dictionary.end()) {
        return true;
    }

    word = "";
    for (int i = 0; i < this->rows; i++) {
        word += this->board[i][this->rows - i - 1];
    }
    if (dictionary.find(word) != dictionary.end()) {
        return true;
    }

    return false;
}

template <typename T>
bool Word_Board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool Word_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

template <typename T>
Word_Player<T>::Word_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void Word_Player<T>::getmove(int &x, int &y) {
    char Symbol;
    cout << "\nPlease enter your symbol (a single letter): ";
    cin >> Symbol;

    while (!isalpha(Symbol)) {
        cout << "Invalid symbol. Please enter a letter (a-z): ";
        cin >> Symbol;
    }

    Symbol = toupper(Symbol);
    this->symbol = Symbol;

    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
    cin >> x >> y;
}

template <typename T>
Word_Random_Player<T>::Word_Random_Player(string name,T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = name;
    srand(static_cast<unsigned int>(time(0)));
}

template <typename T>
void Word_Random_Player<T>::getmove(int &x, int &y) {
    char Symbol='A'+rand()%26;
    this->symbol = Symbol;
    x = rand() % 3;
    y = rand() % 3;
}

#endif // INC_3X3_WORD_H
