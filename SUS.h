
#ifndef SUS_H
#define SUS_H

#include "BoardGame_Classes.h"
#include <bits/stdc++.h>
using namespace std;


template<typename T>
class SUS_board:public Board<T>{
protected:
    int counter1;
    int  counter2;

public:

    SUS_board();
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    pair<int,int> check();
    bool is_win() ;
    bool is_draw();
    bool game_is_over();
    int getwinnerindex();
};


template <typename T>
class SUS_Player : public Player<T> {
public:
    SUS_Player (string name, T symbol);
    void getmove(int& x, int& y) ;

};


template <typename T>
class SUS_Random_Player : public RandomPlayer<T>{
public:
    SUS_Random_Player (string name,T symbol);
    void getmove(int &x, int &y) ;
};


///______________________________IMPLEMENTATION
bool player=true;
set<int> rows={0 , 1 , 2};
set<int> columns={0 , 1 , 2};
bool enter1=true;
bool enter2=true;
template<typename T>
SUS_board<T>::SUS_board() {

    this->rows = this->columns = 3;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
    this->counter1=0;
    this->counter2=0;
}



template <typename T>
bool SUS_board<T>::update_board(int x, int y, T mark) {

    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0|| mark == 0)) {
        if (mark == 0) {
            this->n_moves--; // Decrement move count when undoing a move
            this->board[x][y] = 0;
        } else {

            player=!player;//false
            this->n_moves++; // Increment move count for a new move//1
            this->board[x][y] = toupper(mark);


        }

        return true;
    }
    return false; // Invalid move
}



// Display the board
template <typename T>
void SUS_board<T>::display_board() {
    pair<int,int>p=check();

    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << "\n\n";
    cout<<"First Play counter: "<<p.first<<" "<<"Second Player counter: "<<p.second<<"\n\n";
}
template<typename T>
pair<int,int> SUS_board<T>::check() {

    for (int i = 0; i < this->rows; i++) {
        if (this->board[i][0] =='S'&& this->board[i][1]=='U' && this->board[i][2] =='S' &&
            rows.count(i)){

            if(player)
                counter2++;
            else
                counter1++;
            rows.erase(i);
        }
        if  (this->board[0][i] =='S'&& this->board[1][i]=='U' && this->board[2][i] == 'S' && columns.count(i)) {
            if(player)
                counter2++;
            else
                counter1++;

            columns.erase(i);
        }

    }



    // Check diagonals
    if(enter1){
        if (this->board[0][0] =='S' &&this->board[1][1]=='U' && this->board[2][2]=='S' ){
            if(player)
                counter2++;
            else
                counter1++;
            enter1= false;
        }}
    if(enter2){
        if (this->board[0][2] == 'S'&&this->board[1][1]=='U' &&  this->board[2][0] =='S') {
            if(player)
                counter2++;
            else
                counter1++;
            enter2= false;
        }}



    return {this->counter1,this->counter2};
}

template<typename T>
int SUS_board<T>::getwinnerindex() {
    if(this->counter1>this->counter2)
        return 0;
    else if(this->counter2>this->counter1)
        return 1;
}


template<typename T>
bool SUS_board<T>::is_win() {

    if(this->n_moves==9 && counter1!=counter2){

        return true;
    }

    return false;
}

template<typename T>
bool SUS_board<T>::is_draw() {


    return (this->n_moves == 9 && !is_win());


}



template <typename T>
bool SUS_board<T>::game_is_over() {
    return is_win() || is_draw();
}


template <typename T>
SUS_Player<T>::SUS_Player (string name, T symbol) : Player<T>(name, symbol) {

}

template <typename T>
void SUS_Player<T>::getmove(int& x, int& y) {

    cout << this->getname()<<",Please enter your move x and y (0 to 2) separated by spaces: ";
    //  cout<<"\n c1 is: "<<c1<<" c2 is: "<<c2;
    cin >> x >> y;

}

// Constructor for X_O_Random_Player
template <typename T>
SUS_Random_Player<T>::SUS_Random_Player(string name,T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = name;
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

template <typename T>
void SUS_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;  // Random number between 0 and 2
    y = rand() % this->dimension;
}






#endif //SUS_H
