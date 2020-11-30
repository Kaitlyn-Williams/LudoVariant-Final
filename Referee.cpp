#include "Referee.h"

/* constructor */
Referee::Referee() {
    turn = 1;
    gameOver = false;
}

 /* returns the current turn number */
int Referee::GetTurn() {
    return turn;
}

 /* advances the turn by one */
void Referee::NextTurn() {
    turn++;
}

/* true if game is over and false if game is still in progress */
void Referee::SetGameOver(bool g) {
    gameOver = g;
}
/* returns true if the game has ended */
bool Referee::GameOver() {
    return gameOver;
}