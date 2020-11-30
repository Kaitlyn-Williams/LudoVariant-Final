#ifndef REFEREE_H
#define REFEREE_H

class Referee {
private:
    int turn;
    bool gameOver;

public:
    Referee();
    int GetTurn();
    void NextTurn();
    void SetGameOver(bool g);
    bool GameOver();
};

#endif