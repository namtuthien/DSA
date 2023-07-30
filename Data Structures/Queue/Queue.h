#include "Node.h"

class Queue
{
private:
    Node *head;
    Node *tail;

public:
    Queue();

    void enqueue(int);
    void dequeue();
    int front();
    int back();
    void print();

    ~Queue();
};