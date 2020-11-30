#include "Path.h"

using namespace std;

/* constructor */
Path::Path() {

}

/* destructor */
Path::~Path() {
    delete pathHead;
    delete current;
    delete pathTail;
}

/* returns the beginning node of the circular linked list */
Path::Node* Path::GetPathHead() {
    return pathHead;
}

/* returns the current node of the circular linked list */
Path::Node* Path::GetCurrentNode() {
    return current;
}

/* returns the end node of the circular linked list */
Path::Node* Path::GetCurrentNode() {
    return pathTail;
}

/* returns the next node in the circular linked list */
Path::Node *Path::GetNextNode() {
    return current->next;
}

/* returns the previous node in the circular linked list */
Path::Node *Path::GetPrevNode() {
    return current->prev;
}

/* inserts a node at the "end" of the circular linked list */
void Path::AddNode(char data) {
    Node *newNode = new Node();
    newNode->element = data;
    if(pathHead == nullptr) {
        pathHead = newNode;
    } else {

    }
}