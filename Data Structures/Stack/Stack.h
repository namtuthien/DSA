#include "Node.h"

class Stack
{
private:
    Node *top;

public:
    Stack();

    void push(int);
    void pop();
    int show();
    void print();

    ~Stack();
};