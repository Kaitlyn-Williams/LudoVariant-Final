#ifndef PATH_H
#define PATH_H

class Path {

private:
    struct Node {
        char element;
        Node *prev;
        Node *next;
    };
    Node *pathHead;
    Node *current;
    Node *pathTail;

public:
    Path();
    ~Path();
    Node *GetPathHead();
    Node *GetCurrentNode();
    Node *GetPathTail();
    Node *GetNextNode();
    Node *GetPrevNode();
    void AddNode(char data);
};

#endif