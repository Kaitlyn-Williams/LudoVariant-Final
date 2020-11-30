#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"

class Board {
private:
    char grid[15][15];
    char path[63];

public:
    Board();
    char* GetBoard();
    void MapPath(char *path, int p);
    int  GetPathIndex(int r, int c);
    bool UpdateMap(Piece p, int prevLocation, char *path);
    void Print(char *path, int player);
};

#endif