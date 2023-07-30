#include <iostream>
#include "Queue.h"

Queue::Queue()
{
    this->head = nullptr;
    this->tail = nullptr;
}

void Queue::enqueue(int data)
{
    Node *new_node = new Node(data);

    if (this->head == nullptr)
    {
        this->head = new_node;
        this->tail = new_node;
        return;
    }

    this->tail->set_next(new_node);
    this->tail = new_node;
}

void Queue::dequeue()
{
    if (this->head == nullptr)
        return;

    Node *temp = this->head;
    this->head = temp->get_next();
    delete temp;
}

int Queue::front()
{
    if (this->head == nullptr)
        return 0;

    return this->head->get_data();
}

int Queue::back()
{
    if (this->tail == nullptr)
        return 0;

    return this->tail->get_data();
}

void Queue::print()
{
    std::cout << "Queue <- ";
    while (this->head != nullptr)
    {
        std::cout << front() << " <- ";
        dequeue();
    }
    std::cout << "\b\b\b\b -> nullptr" << std::endl;
}

Queue::~Queue()
{
    while (this->head != nullptr)
        dequeue();
}