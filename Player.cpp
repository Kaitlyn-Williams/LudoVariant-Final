#include "Player.h"

/* constructor */
Player::Player() {
    score = 0;
    for(int i = 0; i < 63; i++) {
        path[i] = ' ';
        /*if(i == 0 || i == 26) { path[i] = '*'; }
        if((i > 0 && i < 26) || (i > 26 && i < 51)) { path[i] = '0'; }
        if(i > 50 && i < 56) { path[i] = '>'; }
        if(i > 55 && i < 61) { path[i] = '<'; }
        if(i == 61) { path[i] = 'X'; }*/
    }
}

/* returns current board state */
Board* Player::GetBoard() {
    return board;
}

/* returns the current piece values & locations */
Piece* Player::GetPieces() {
    return pieces;
}

/* returns the player's current score */
int Player::GetScore() {
    return score;
}

/* returns the player's starting position */
int Player::GetStartingLocation() {
    return startLocation;
}

/* returns the player's number */
int Player::GetPlayerNumber() {
    return playerNumber;
}

/* returns the current path the player's pieces are on */
char* Player::GetPath(){
    return path;
}

/* specifies the board the player is using */
void Player::SetBoard(Board *b) {
    board = b;
}

/* identifies the order in which the player joined the game */
void Player::SetPlayerNumber(int n) {
    playerNumber = n;
}

/* specifies the set of pieces the player is using */
void Player::SetPieces(char *p) {
    for(int i = 0; i < 6; i++) {
        pieces[i].SetValue(p[i]);
    }
}

/* updates the specified piece */
void Player::UpdatePiece(Piece p, int i) {
    pieces[i].SetFinishStatus(p.IsFinished());
    pieces[i].SetValue(p.GetValue());
    pieces[i].SetLocation(p.GetLocation());
    pieces[i].SetFirstTurnStatus(p.IsFirstTurn());
}

/* sets/updates the player's score */
void Player::SetScore(int s) {
    score = s;
}

/* sets the player's starting location on the board */
void Player::SetStartLocation(int l) {
    startLocation = l;
}

/* moves the specified piece by the distance given */
void Player::Move(Piece *p, int distance) {
    int prevLocation = p->GetLocation();
    int nextLocation = p->GetLocation() + 1;
    bool spaceTaken = false;

    if(p->IsFirstTurn()) {
        nextLocation = prevLocation;
        p->SetFirstTurnStatus(false);
    }

    if(nextLocation > 62) {
        nextLocation = 62;
        p->SetFinishStatus(true);
    }

    for(int i = distance; i > 0; i--) {
        if(path[nextLocation] != ' ') {
            spaceTaken = true;
            break;
        }
        if (playerNumber == 1 && nextLocation >= 57) {
            nextLocation = 62;
        }
        else if(playerNumber == 2 && nextLocation == 26) {
            nextLocation = 57;
        }
        else if(playerNumber == 2 && nextLocation == 52) {
            nextLocation = 0;
        }
        if(nextLocation >= 62) {
            p->SetLocation(62);
            p->SetFinishStatus(true);
            break;
        }

        p->SetLocation(nextLocation);
        nextLocation++;
    }
    if (!spaceTaken) {
        board->UpdateMap(*p, prevLocation, path);
    }
}
