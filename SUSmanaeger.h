

#ifndef SUSMANAEGER_H
#define SUSMANAEGER_H
#include <bits/stdc++.h>
#include "SUS.h"
template <typename T>
class SUSManager {
private:
    SUS_board<T>* boardPtr;
    Player<T>* players[2];
public:
    SUSManager(SUS_board<T>*, Player<T>* playerPtr[2]);

    void run();
};

//--------------------------------------- IMPLEMENTATION

#include <iostream>
using namespace std;

template <typename T>
SUSManager<T>::SUSManager(SUS_board<T>* bPtr, Player<T>* playerPtr[2]) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

template <typename T>
void SUSManager<T>::run() {
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i : {0, 1}) {
            players[i]->getmove(x, y);
            while (!boardPtr->update_board(x, y, players[i]->getsymbol())) {
                players[i]->getmove(x, y);
            }
            boardPtr->display_board();
            if (boardPtr->is_win()) {
                cout << players[boardPtr->getwinnerindex()]->getname() << " wins\n";
                return;
            }
            if (boardPtr->is_draw()) {
                cout << "Draw!\n";
                return;
            }
        }
    }
}


#endif //SUSMANAEGER_H
