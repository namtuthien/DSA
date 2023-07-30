#include <iostream>
#include "Stack.h"

Stack::Stack()
{
    this->top = nullptr;
}

void Stack::push(int data)
{
    Node *new_node = new Node(data);

    if (this->top == nullptr)
    {
        this->top = new_node;
        return;
    }

    new_node->set_next(this->top);
    this->top = new_node;
}

void Stack::pop()
{
    if (this->top == nullptr)
        return;

    Node *temp = this->top;
    this->top = temp->get_next();
    delete temp;
}

int Stack::show()
{
    if (this->top == nullptr)
        return 0;

    return this->top->get_data();
}

void Stack::print()
{
    std::cout << "Stack <- ";
    while (top != nullptr)
    {
        std::cout << show() << " | ";
        pop();
    }
}

Stack::~Stack()
{
    while (top != nullptr)
        pop();
}