#include "BoardGame_Classes.h"
#include "SUS.h"
#include "MinMaxPlayer.h"
#include "connect_four.h"
#include "numerical_tic_tac_toe.h"
#include "SUSmanaeger.h"
#include "3x3Misere_Tic_Tac_Toe.h"
#include "3x3_word.h"
#include "3X3_ultimate.h"
#include "PyramidTicTacToe.h"
#include "5x5_Tic_Tac_Toe.h"
int pyramid(){
    int choice;
    Player<char>* players[2];
    PyramidTicTacToe<char>* B = new PyramidTicTacToe<char>();

    string playerXName, player2Name;
    cout << "Welcome to Pyramid Tic-Tac-Toe Game. :)\n";
    // Set up player 1
    cout << "Enter Player X name: ";
    cin >> playerXName;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch(choice) {
        case 1:
            players[0] = new PyramidPlayer<char>(playerXName, 'X');
            break;
        case 2:
            players[0] = new PyramidRandomPlayer<char>(playerXName,'X');
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return 1;
    }

    // Set up player 2
    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch(choice) {
        case 1:

            players[1] = new PyramidPlayer<char>(player2Name, 'O');
            break;
        case 2:
            players[1] = new PyramidRandomPlayer<char>(player2Name,'O');
            break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
            return 1;
    }


    GameManager<char> pyramid_game(B, players);
    pyramid_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
}
int connect4() {
    int choice;
    Player<char> *players[2];
    ConnectFourBoard<char> *B = new ConnectFourBoard<char>();
    string playerXName, player2Name;

    cout << "Welcome to FCAI Connect four Game. :)\n";

    // Set up player 1
    cout << "Enter First Player name (X): ";
    cin >> playerXName;
    cout << "Choose First Player type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    //cout << "3. Smart Computer (AI)\n";
    cin >> choice;

    switch (choice) {
        case 1:
            players[0] = new ConnectFourPlayer<char>(playerXName, 'X');
            break;
        case 2:
            players[0] = new ConnectFourRandomPlayer<char>(playerXName, 'X');
            break;

        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return 0;

    }

    // Set up player 2
    cout << "Enter Second Player name (O): ";
    cin >> player2Name;
    cout << "Choose Second Player type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch (choice) {
        case 1:
            players[1] = new ConnectFourPlayer<char>(player2Name, 'O');
            break;
        case 2:
            players[1] = new ConnectFourRandomPlayer<char>(player2Name, 'O');
            break;

        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
            return 0;

    }

    // Create the game manager and run the game
    GameManager<char> connect4_game(B, players);
    connect4_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
}
int tictactoe5X5(){
    int choice;
    Player<char>* players[2];
    TicTacToe_Board<char>* board = new TicTacToe_Board<char>();
    string playerXName, playerOName;

    cout << "Welcome to 5x5 Tic Tac Toe!\n";

    // Set up Player X
    cout << "Enter Player X's name: ";
    cin >> playerXName;
    cout << "Choose Player X's type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch (choice) {
        case 1:
            players[0] = new TicTacToe_Player<char>(playerXName, 'X');
            break;
        case 2:
            players[0] = new TicTacToe_Random_Player<char>(playerXName,'X');
            break;
        default:
            cout << "Invalid choice for Player X. Exiting the game.\n";
            delete board;
            return 1;
    }

    // Set up Player O
    cout << "Enter Player O's name: ";
    cin >> playerOName;
    cout << "Choose Player O's type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch (choice) {
        case 1:
            players[1] = new TicTacToe_Player<char>(playerOName, 'O');
            break;
        case 2:
            players[1] = new TicTacToe_Random_Player<char>(playerOName,'O');
            break;
        default:
            cout << "Invalid choice for Player O. Exiting the game.\n";
            delete players[0];
            delete board;
            return 1;
    }

    // Game Manager
    GameManager<char> game(board, players);
    game.run();

    // Clean up
    delete board;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
}
int SUS(){
    int choice;
    Player<char>* players[2];
    SUS_board<char>* B = new SUS_board<char>();
    string playerXName, player2Name;

    cout << "Welcome to FCAI SUS Game. :)\n";

    // Set up player 1
    cout << "Enter First Player name (S): ";
    cin >> playerXName;
    cout << "Choose First Player type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch(choice) {
        case 1:
            players[0] = new SUS_Player<char>(playerXName, 'S');
            break;
        case 2:
            players[0] = new SUS_Random_Player<char>(playerXName,'S');
            break;

        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return 1;
    }

    // Set up player 2
    cout << "Enter Second Player name (U): ";
    cin >> player2Name;
    cout << "Choose Second Player type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";

    cin >> choice;

    switch(choice) {
        case 1:
            players[1] = new SUS_Player<char>(player2Name, 'U');
            break;
        case 2:
            players[1] = new SUS_Random_Player<char>(player2Name,'U');
            break;

        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
            return 1;
    }

    // Create the game manager and run the game
    SUSManager<char> SUS_game(B, players);
    SUS_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }

}


int numerical(){
    int n;
    int choice;
    Player<int>* players[2];
    numericalttt_board<int>* B = new numericalttt_board<int>();
    string playerXName, player2Name;

    cout << "Welcome to FCAI numerical tic tac toe Game. :)\n";

    // Set up player 1
    cout << "First player will play odd numbers\nEnter First Player name: ";
    cin >> playerXName;
    cout << "Choose First Player type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch (choice) {
        case 1:
            // cout<<"Enter even number: "<<endl;
//cin>>n;
            players[0] = new numericalttt_player<int>(playerXName,n );
            break;
        case 2:
            players[0] = new numericalttt_random_player<int>(playerXName,n);
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return 1;
    }

    // Set up player 2
    cout << "Second player will play even numbers\nEnter Second Player name: ";
    cin >> player2Name;
    cout << "Choose Second Player type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin>>choice;
    switch (choice) {
        case 1:
            // cout<<"enter odd number: "<<endl;
            //cin>>n;
            players[1] = new numericalttt_player<int>(player2Name, n);
            break;
        case 2:
            players[1] = new numericalttt_random_player<int>(player2Name,n);
            break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
            return 1;
    }

    // Create the game manager and run the game

    GameManager<int> numurical_game(B, players);
    numurical_game.run();
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }

}

int inverse_tic_tac(){
    int choice;
    Player<char>* players[2];
    Misere_Tic_Tac_Toe_Board<char>* B = new Misere_Tic_Tac_Toe_Board<char>();
    string player1Name, player2Name;

    cout << "Welcome to FCAI Misere Tic-Tac-Toe Game. :)\n";

    // Set up player 1
    cout << "Enter Player 1 name: ";
    cin >> player1Name;
    cout << "Choose Player 1 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch (choice) {
        case 1:
            players[0] = new Misere_Tic_Tac_Toe_Player<char>(player1Name, 'X');
            break;
        case 2:
            players[0] = new Misere_Tic_Tac_Toe_Random_Player<char>(player1Name,'X');
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return 1;
    }

    // Set up player 2
    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch (choice) {
        case 1:
            players[1] = new Misere_Tic_Tac_Toe_Player<char>(player2Name, 'O');
            break;
        case 2:
            players[1] = new Misere_Tic_Tac_Toe_Random_Player<char>(player2Name,'O');
            break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
            return 1;
    }

    // Swap the names of the players X and O
    swap(player1Name, player2Name);  // Swap names of player X and player O

    // Now update the player objects with the swapped names
    if (dynamic_cast<Misere_Tic_Tac_Toe_Player<char>*>(players[0])) {
        players[0] = new Misere_Tic_Tac_Toe_Player<char>(player1Name, 'X');
    } else if (dynamic_cast<Misere_Tic_Tac_Toe_Random_Player<char>*>(players[0])) {
        players[0] = new Misere_Tic_Tac_Toe_Random_Player<char>(player1Name,'X');
    }

    if (dynamic_cast<Misere_Tic_Tac_Toe_Player<char>*>(players[1])) {
        players[1] = new Misere_Tic_Tac_Toe_Player<char>(player2Name, 'O');
    } else if (dynamic_cast<Misere_Tic_Tac_Toe_Random_Player<char>*>(players[1])) {
        players[1] = new Misere_Tic_Tac_Toe_Random_Player<char>(player2Name,'O');
    }

    // Create the game manager and run the game
    GameManager<char> misere_ttt_game(B, players);
    misere_ttt_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }

}


int word(){
    int choice;
    Player<char>* players[2];
    Word_Board<char>* B = new Word_Board<char>();
    string player1Name, player2Name;


    cout << "Welcome to FCAI Word Tic-Tac-Toe Game. :)\n";

    // Set up player 1
    cout << "Enter Player 1 name: ";
    cin >> player1Name;
    cout << "Choose Player 1 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch (choice) {
        case 1:
            players[0] = new Word_Player<char>(player1Name, ' ');
            break;
        case 2:
            players[0] = new Word_Random_Player<char>(player1Name,' ');
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return 1;
    }

    // Set up player 2
    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch (choice) {
        case 1:
            players[1] = new Word_Player<char>(player2Name, ' ');
            break;
        case 2:
            players[1] = new Word_Random_Player<char>(player2Name,' ');
            break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
            return 1;
    }






    GameManager<char> word_game(B, players);
    word_game.run();

    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }

}
int ultimate(){
    int choice;
    UltimateTicTacToeBoard<char>* board = new UltimateTicTacToeBoard<char>();
    Player<char>* players[2];
    string playerXName, playerName_2;

    cout << "Welcome to Ultimate Tic-Tac-Toe!" << endl;


    // Set up player 1
    cout << "Enter Player 1 name: ";
    cin >> playerXName;
    cout << "Choose Player 1 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch(choice) {
        case 1:
            players[0] = new UltimateTicTacToePlayer<char>(playerXName, 'X');
            break;
        case 2:
            players[0] = new UltimateTicTacToeRandomPlayer<char>(playerXName,'X');
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return 1;
    }

    // Set up player 2
    cout << "Enter Player 2 name: ";
    cin >> playerName_2;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch(choice) {
        case 1:
            players[1] = new UltimateTicTacToePlayer<char>(playerName_2, 'O');
            break;
        case 2:
            players[1] = new UltimateTicTacToeRandomPlayer<char>(playerName_2,'O');
            break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
            return 1;
    }



    GameManager<char>ultimate(board,players);
    ultimate.run();

    delete board;
    delete players[0];
    delete players[1];

}

int main() {
    cout<<"Hello in FCAI GAMES which game need: \n";
    input:
    cout<<"1- Pyramic Tic-Tac-Toe\n2- Four-in-a-row\n3- 5 x 5 Tic Tac Toe\n4-Word Tic Tac Toe\n5- Numerical Tic-Tac-Toe\n6-Misere Tic Tac Toe\n8_Ultimate Tic Tac Toe\n9-SUS\n";
    int n;cin>>n;
        switch (n) {
            case 1:
                pyramid();
                break;
            case 2:
                connect4();
                break;
            case 3:
               tictactoe5X5();
                break;
            case 4:
                word();
                break;
            case 5:
                numerical();
                break;
            case 6:
                inverse_tic_tac();
                break;
            case 8:
                ultimate();
                break;
            case 9:
                SUS();
                break;
            default:
                cout<<"Enter a valid number";
                break;

        }



    cout<<"Did you need to continue? (Y/N)";
    char p;cin>>p;

    if(toupper(p)=='Y')

        goto input;


    else if(toupper(p)=='N')
        cout<<"goodbye\n";


    else
        cout<<"Invalid choice exit...\n";

        return 0;
}