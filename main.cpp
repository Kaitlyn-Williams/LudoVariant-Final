#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include "Board.h"
#include "Piece.h"
#include "Player.h"
#include "Referee.h"

using namespace std;

int Roll();
bool validPiece(char selectedPiece, Piece *pieces);

int main() {
    //initialize
    srand(time(NULL));
    Board board = Board();
    Referee referee = Referee();
    Player p1 = Player();
    Player p2 = Player();
    p1.SetPlayerNumber(1);
    p2.SetPlayerNumber(2);
    p1.SetBoard(&board);
    p2.SetBoard(&board);
    char pcs1[6] = {'1', '2', '3', '4', '5', '6'};
    char pcs2[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
    p1.SetPieces(pcs1);
    p2.SetPieces(pcs2);
    p1.SetStartLocation(1);
    p2.SetStartLocation(27);
    Player *currentPlayer = &p1;
    int roll = 0;

    do {
        //clear screen
        system("CLS");

        //set current player based on turn (even = player 2, odd = player 1)
        if (referee.GetTurn() % 2 == 0) {
            currentPlayer = &p2;
        } else {
            currentPlayer = &p1;
        }

        //display current board state
        currentPlayer->GetBoard()->Print(currentPlayer->GetPath(), currentPlayer->GetPlayerNumber());

        //update roll
        roll = Roll();
        
        //display other info
        cout << endl;
        cout << "Your roll is: " << roll << endl << endl;
        cout << "Player 1 score: " << p1.GetScore() << endl;
        cout << "Player 2 score: " << p2.GetScore() << endl;

        Piece *pieces = NULL;
        pieces = currentPlayer->GetPieces();

        //prompt user for input & check if valid input
        char selectedPiece;
        do {
            cout << endl;
            for(int i = 0; i < 6; i++) {
                if (!pieces[i].IsFinished()) {
                    cout << pieces[i].GetValue();
                    if (i < 5) { cout << ", "; }
                }
            }
            cout << endl;
            cout << "Choose any of the above Pieces: ";
            cin >> selectedPiece;
        } while (!validPiece(selectedPiece, currentPlayer->GetPieces()));

        //update variable to selected piece
        Piece *currentPiece;
        for(int i = 0; i < 6; i++) {
            if (selectedPiece == pieces[i].GetValue()) {
                currentPiece = &pieces[i];
                if (currentPiece->IsFirstTurn()) {
                    currentPiece->SetLocation(currentPlayer->GetStartingLocation());
                    roll = 0;
                }
                break;
            }
        }

        //advance selected piece
        currentPlayer->Move(currentPiece, roll);

        //update score & game status
        referee.NextTurn();
        if(currentPiece->IsFinished()) {
            currentPlayer->SetScore(currentPlayer->GetScore() + 1); 
            board.UpdateMap(*currentPiece, 62, currentPlayer->GetPath());
        }
        if(currentPlayer->GetScore() == 6) {
            referee.SetGameOver(true);
            //clear screen
            system("CLS");
            //winning message
            cout << endl << endl;
            cout << "You've won!!!" << endl;
            cout << "Congratulations Player " << currentPlayer->GetPlayerNumber() << "!";
        }

    } while (!referee.GameOver()); //if all of one player's pieces reach the end then game is over - exit

    return 0;
}

/* returns a random number between 1 and 6 */
int Roll() {
    return rand() % 6 + 1;
}

/* returns true if piece matches one in the player's set that hasn't reached the end of the board and false otherwise */
bool validPiece(char selectedPiece, Piece *pieces) {
    for(int i = 0; i < 6; i++) {
        if(selectedPiece == pieces[i].GetValue() && !pieces[i].IsFinished()) {
            return true;
        }
    }
    return false;
}
