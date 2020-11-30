#ifndef PIECE_H
#define PIECE_H

class Piece {
private:
    char value;
    int location;
    bool finished;
    bool firstTurn;

public:
    Piece();
    char GetValue();
    int GetLocation();
    bool IsFinished();
    bool IsFirstTurn();
    void SetValue(char v);
    void SetLocation(int l);
    void SetFinishStatus(bool s);
    void SetFirstTurnStatus(bool s);
};

#endif