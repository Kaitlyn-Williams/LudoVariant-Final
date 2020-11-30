#include "Piece.h"

/* constructor */
Piece::Piece() {
    location = -1;
    finished = false;
    firstTurn = true;
}

/* returns the character displayed on the board for the piece */
char Piece::GetValue() {
    return value;
}

/* returns the current row value for the piece */
int Piece::GetLocation() {
    return location;
}

/* returns true if piece has reached the center of the board and false otherwise */
bool Piece::IsFinished() {
    return finished;
}

/* returns true if it is the first time this piece has been used and false otherwise */
bool Piece::IsFirstTurn() {
    return firstTurn;
}

/* updates the character displayed on the board for the piece */
void Piece::SetValue(char v) {
    value = v;
}

/* updates row value */
void Piece::SetLocation(int l) {
    location = l;
}

/* true if piece has reached end of path, false otherwise */
void Piece::SetFinishStatus(bool s) {
    finished = s;
}

/* true if it is the first turn that this piece has been used, false otherwise */
void Piece::SetFirstTurnStatus(bool s) {
    firstTurn = s;
}