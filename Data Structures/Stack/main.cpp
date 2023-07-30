#include "Node.cpp"
#include "Stack.cpp"

int main()
{
    Stack *stack = new Stack;

    stack->push(2);
    stack->push(5);
    stack->push(3);
    stack->print();

    delete stack;
}