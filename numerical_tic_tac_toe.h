//
// Created by Abd-ElRahman on 03/12/2024.
//

#ifndef NUMERICAL_TIC_TAC_TOE_H
#define NUMERICAL_TIC_TAC_TOE_H
#include"BoardGame_Classes.h"
#include <bits/stdc++.h>


using namespace std;

template<typename T>
class numericalttt_board:public Board<T>{
public:
    numericalttt_board();
    bool isvalid(int x, int y,T symbol);
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();

};


template<typename T>
class numericalttt_player:public Player<T>{
public:
    numericalttt_player(string name , T symbol);
    void getmove(int& x, int& y) ;

};


template<typename T>
class numericalttt_random_player:public RandomPlayer<T>{
public:
    numericalttt_random_player(string name,T symbol);
    void getmove(int &x, int &y) ;
};




///----------------Implementation


bool moves = true;//if moves ==true first player will play if == false second player will play
set<int> s;//any number will played will added here
vector<int> oddNumbers = {1, 3, 5, 7, 9};
vector<int> evenNumbers = {2, 4, 6, 8};




template <typename T>
numericalttt_board<T>::numericalttt_board()  {
    this->rows = this->columns = 3;
    this->board = new T*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new T[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}


template <typename T>
bool numericalttt_board<T>::update_board(int x, int y, T mark) {
    // Only update if move is valid

    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0|| mark == 0)) {
        if (mark == 0){
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else
        {this->n_moves++;
            this->board[x][y]=mark;
            s.insert(mark);
            oddNumbers.erase(remove(oddNumbers.begin(),oddNumbers.end(),mark),oddNumbers.end());
            evenNumbers.erase(remove(evenNumbers.begin(),evenNumbers.end(),mark),evenNumbers.end());
            moves=!moves;
        }



    }

    else
        return false;

    return true;
}

// Display the board and the pieces on it
template <typename T>
void numericalttt_board<T>::display_board() {
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

//check for wining
template<typename T>
bool numericalttt_board<T>::is_win() {
    //check for rows and columns
    for (int i = 0; i < this->rows; ++i) {
        if((this->board[i][0]+this->board[i][1]+this->board[i][2]==15 &&(this->board[i][0]!=0 && this->board[i][1]!=0 && this->board[i][2]!=0))||(this->board[0][i]+this->board[1][i]+this->board[2][i]==15 &&(this->board[0][i]!=0 && this->board[1][i]!=0 && this->board[2][i]!=0)))
            return true;


    }

    if((this->board[0][0]+this->board[1][1]+this->board[2][2]==15 &&(this->board[0][0]!=0 &&this->board[1][1]!=0 && this->board[2][2]!=0))||(this->board[0][2]+this->board[1][1]+this->board[2][0]==15 &&(this->board[0][2]!=0 && this->board[1][1]!=0 && this->board[2][0]!=0))){
        return true;
    }
    return false;
}

template <typename T>
bool numericalttt_board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}


template <typename T>
bool numericalttt_board<T>::game_is_over() {
    return (is_win()||is_draw());
}
//players
template <typename T>
numericalttt_player<T>::numericalttt_player (string name, T symbol) : Player<T>(name, symbol) {

}

template <typename T>
void numericalttt_player<T>::getmove(int& x, int& y) {
    cout << this->getname() <<",please enter your move x and y (0 to 2) separated by spaces: ";
    cin >> x >> y;

    if(moves){
        cout << "\nPlease enter an odd number from available [ ";
        for(auto i : oddNumbers){
            cout<<i<<" ";
        }
        cout<<"] : "<<endl;
        int num;
        cin >> num;

        //validation
        while(num < 1 || num > 9 || num % 2 == 0 || s.count(num)){
            cout << "\nPlease enter an odd number from available [ ";
            for(auto i : oddNumbers){
                cout<<i<<" ";
            }
            cout<<"] : "<<endl;
            cin >> num;
        }

        this->symbol = num;
        // odd = !odd;
    }
    else{
        cout << "\nPlease enter an even number from available [ ";
        for(auto i : evenNumbers){
            cout<<i<<" ";
        }
        cout<<"] : "<<endl;
        int num;
        cin >> num;//2

        //validation
        while(num < 1 || num > 9 || num % 2 != 0 ||s.count(num)){
            cout << "\nPlease enter an even number from available [ ";
            for(auto i : evenNumbers){
                cout<<i<<" ";
            }
            cout<<"] : "<<endl;
            cin >> num;
        }
        // s.insert(num);//s={7,2,}
        this->symbol = num;//2
        // odd = !odd;//true
    }
}


//random
template<typename T>
numericalttt_random_player<T>::numericalttt_random_player(string name,T symbol):RandomPlayer<T>( symbol) {    this->dimension = 3;
    this->name = name;
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}



template <typename T>
void numericalttt_random_player<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;
    y = rand() % this->dimension;
    int num;
    if(moves){
        int index = rand() % 5; // size of oddNumbers = 5  //3  4
        //cout<<"index is :"<<index<<endl;
        num = oddNumbers[index];
        //  cout<<"the num odd is: "<<num<<endl;
        //validation
        while(s.count(num)){
            index = rand() % 5;
            // cout<<"index is :"<<index<<endl;
            num = oddNumbers[index];
            //  cout<<"the num odd is: "<<num<<endl;
        }
        this->symbol = num;//7  9
        // s.insert(num);//s={1,6,5,4,9,}
        // odd = !odd;//false
    }
    else {
        int index = rand() % 4; // size of evenNumbers = 4
        //cout<<"index is :"<<index<<endl;//2 4
        num = evenNumbers[index];//6 4
        // cout<<"the num even is: "<<num<<endl;
        //validation
        while(s.count(num)){
            index = rand() % 4;
            //cout<<"index is :"<<index<<endl;
            num = evenNumbers[index];
            //  cout<<"the num even is: "<<num<<endl;
        }
        this->symbol = num;
        //  s.insert(num);
        //  odd = !odd;
    }
}



#endif //NUMERICAL_TIC_TAC_TOE_H
