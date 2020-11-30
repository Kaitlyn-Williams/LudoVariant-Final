#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"
#include "Piece.h"

class Player {
private:
    Board *board;
    char path[63];
    Piece pieces[6];
    int startLocation;
    int score;
    int playerNumber;

public:
    Player();
    Board* GetBoard();
    Piece* GetPieces();
    int GetScore();
    int GetStartingLocation();
    int GetPlayerNumber();
    char* GetPath();
    void SetBoard(Board *b);
    void SetPlayerNumber(int n);
    void SetPieces(char *p);
    void UpdatePiece(Piece p, int i);
    void SetScore(int s);
    void SetStartLocation(int l);
    void Move(Piece *p, int distance);
};

#endif