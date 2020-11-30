#include <iostream>
#include "Board.h"
#include "Piece.h"

using namespace std;

/* constructor - sets up initial board state*/
Board::Board() {
    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 15; j++) {
            if ((i == 0 || i == 14) && (j > 5 && j < 9)) //top and bottom ends
                { grid[i][j] = '0'; }
            else if ((j == 6 || j == 8) && ((i > 0 && i < 6) || (i > 8 && i < 14))) //top and bottom prongs
                { grid[i][j] = '0'; }
            else if ((j == 0 || j == 14) && (i > 5 && i < 9)) //left and right ends
                { grid[i][j] = '0'; }
            else if ((i == 6 || i == 8) && ((j > 0 && j < 6) || (j > 8 && j < 14))) 
                { if ((j == 1  && i == 6) || (j == 13 && i == 8)) { grid[i][j] = '*'; } //starting points
                  else { grid[i][j] = '0'; }} //left and right prongs
            else if (i == 7 && (j > 0 && j < 6)) //left inner portion
                { grid[i][j] = '>'; }
            else if (i == 7 && (j > 8 && j < 14)) //right inner portion
                { grid[i][j] = '<'; }
            else if (i == 7 && j == 7) //end point
                { grid[i][j] = 'X'; }
            else //blank space
                { grid[i][j] = ' '; }
        }
    }
    for(int i = 0; i < 63; i++) {
        path[i] = ' ';
    }
}

/* returns the current board state */
char* Board::GetBoard() {
    return *grid;
}

/* updates the current path with the new piece location and value */
bool Board::UpdateMap(Piece p, int prevLocation, char *path) {
    int location = p.GetLocation();
    if (path[location] == ' ' && this->path[location] == ' ') { //assign piece to its location in the path
        path[location] = p.GetValue();
        this->path[location] = p.GetValue();
        if (location != prevLocation) {
            path[prevLocation] = ' ';
            this->path[prevLocation] = ' ';
        }
        return true;
    } else if (prevLocation == 62 && path[location] != ' ') { //clear path if piece has made it to the end
        path[location] = ' ';
        this->path[location] = ' ';
        path[prevLocation] = ' ';
        this->path[prevLocation] = ' ';
        return true;
    }
    return false;
}

/* given the grid coordinates it returns the corresponding path index */
int Board::GetPathIndex(int r, int c){
    if (r == 0) {
        switch (c) {
            case 6: return 11; break;
            case 7: return 12; break;
            case 8: return 13; break;
        }
    }
    else if (r == 1) {
        switch (c) {
            case 6: return 10; break;
            case 8: return 14; break;
        }
    }
    else if (r == 2) {
        switch (c) {
            case 6: return 9; break;
            case 8: return 15; break;
        }
    }
    else if (r == 3) {
        switch (c) {
            case 6: return 8; break;
            case 8: return 16; break;
        }
    }
    else if (r == 4) {
        switch (c) {
            case 6: return 7; break;
            case 8: return 17; break;
        }
    }
    else if (r == 5) {
        switch (c) {
            case 6: return 6; break;
            case 8: return 18; break;
        }
    }
    else if(r == 6) {
        switch (c) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:  return c; break;
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14: return c + 10; break;
        }
    }
    else if(r == 7) {
        switch (c) {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:  return c + 51; break;
                case 7:  return 62; break;
                case 9:
                case 10:
                case 11:
                case 12:
                case 13: return 70 - c; break;
                case 14: return 25; break;
        }
        /*if(player == 1) {
            switch (c) {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:  return c + 50; break;
                case 7:  return 61; break;
                case 14: return 24; break;
            }
        }
        else if (player == 2) {
            switch (c) {
                case 0:  return 50; break;
                case 7:  return 61; break;
                case 9:
                case 10:
                case 11:
                case 12:
                case 13: return 69 - c; break;
                case 14: return 24; break;
            }
        }*/
    }
    else if(r == 8) {
        switch (c) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:  return 50 - c; break;
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14: return 40 - c; break;
        }
    }
    else if (r == 9) {
        switch (c) {
            case 6: return 44; break;
            case 8: return 32; break;
        }
    }
    else if (r == 10) {
        switch (c) {
            case 6: return 43; break;
            case 8: return 33; break;
        }
    }
    else if (r == 11) {
        switch (c) {
            case 6: return 42; break;
            case 8: return 34; break;
        }
    }
    else if (r == 12) {
        switch (c) {
            case 6: return 41; break;
            case 8: return 35; break;
        }
    }
    else if (r == 13) {
        switch (c) {
            case 6: return 40; break;
            case 8: return 36; break;
        }
    }
    else if (r == 14) {
        switch (c) {
            case 6: return 39; break;
            case 7: return 38; break;
            case 8: return 37; break;
        }
    }
    return -1;
}

/* Updates the board to match player movement*/
void Board::MapPath(char *path, int player){
    //if(path[i] != ' ') {
    //    grid[r][c] = path[i];
    //}
    //section 1
    grid[6][1] = path[0];
    grid[6][2] = path[1];
    grid[6][3] = path[2];
    grid[6][4] = path[3];
    grid[6][5] = path[4];
    //section 2
    grid[5][6] = path[5];
    grid[4][6] = path[6];
    grid[3][6] = path[7];
    grid[2][6] = path[8];
    grid[1][6] = path[9];
    //section 3
    grid[0][6] = path[10];
    grid[0][7] = path[11];
    grid[0][8] = path[12];
    //section 4
    grid[1][8] = path[13];
    grid[2][8] = path[14];
    grid[3][8] = path[15];
    grid[4][8] = path[16];
    grid[5][8] = path[17];
    //section 5
    grid[6][9] = path[18];
    grid[6][10] = path[19];
    grid[6][11] = path[20];
    grid[6][12] = path[21];
    grid[6][13] = path[22];
    //section 6
    grid[6][14] = path[23];
    grid[7][14] = path[24];
    grid[8][14] = path[25];
    //section 7
    grid[8][13] = path[26];
    grid[8][12] = path[27];
    grid[8][11] = path[28];
    grid[8][10] = path[29];
    grid[8][9] = path[30];
    //section 8
    grid[9][8] = path[31];
    grid[10][8] = path[32];
    grid[11][8] = path[33];
    grid[12][8] = path[34];
    grid[13][8] = path[35];
    //section 9
    grid[14][8] = path[36];
    grid[14][7] = path[37];
    grid[14][6] = path[38];
    //section 10
    grid[13][6] = path[39];
    grid[12][6] = path[40];
    grid[11][6] = path[41];
    grid[10][6] = path[42];
    grid[9][6] = path[43];
    //section 11
    grid[8][5] = path[44];
    grid[8][4] = path[45];
    grid[8][3] = path[46];
    grid[8][2] = path[47];
    grid[8][1] = path[48];
    //section 12
    grid[8][0] = path[49];
    grid[7][0] = path[50];
    //section 13
    if (player == 1) { //player 1 path to center
        grid[7][1] = path[51];
        grid[7][2] = path[52];
        grid[7][3] = path[53];
        grid[7][4] = path[54];
        grid[7][5] = path[55];
    }
    //section 14
    if (player == 2) { //player 2 path to center
        grid[7][13] = path[56];
        grid[7][12] = path[57];
        grid[7][11] = path[58];
        grid[7][10] = path[59];
        grid[7][9] = path[60];
    }
    //section 15
    grid[7][7] = path[61];
}

/* displays the current board state */
void Board::Print(char *path, int player) {
    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 15; j++) {
            // int index = GetPathIndex(i, j, player);
            // if(index > -1 && index < 62 && path[index] != ' ') {
            //     cout << path[index];
            // }
            int index = GetPathIndex(i, j);
            if (this->path[index] != ' ') {
                cout << this->path[index];
            }
            else {
                cout << grid[i][j];
            }
            cout << " ";
            if (j >= 14) { 
                cout << endl; 
            }
        }
    }
}