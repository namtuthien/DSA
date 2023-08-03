#include <iostream>
#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList()
{
    this->head = nullptr;
}

void SinglyLinkedList::insert_node(int data)
{
    Node *new_node = new Node(data);

    if (this->head == nullptr)
    {
        this->head = new_node;
        return;
    }

    for (Node *index = this->head; index != nullptr; index = index->get_next())
        if (index->get_next() == nullptr)
        {
            index->set_next(new_node);
            return;
        }
}

void SinglyLinkedList::delete_node(int data)
{
    if (this->head == nullptr)
        return;

    if (this->head->get_data() == data)
    {
        Node *temp = this->head;
        this->head = this->head->get_next();
        delete temp;
        return;
    }

    for (Node *index = this->head; index->get_next() != nullptr; index = index->get_next())
    {
        if (index->get_next()->get_data() == data)
        {
            Node *temp = index->get_next();
            index->set_next(temp->get_next());
            delete temp;
            return;
        }
    }
}

void SinglyLinkedList::update_node(int find, int replace)
{
    if (this->head == nullptr)
        return;

    for (Node *index = this->head; index != nullptr; index = index->get_next())
        if (index->get_data() == find)
        {
            index->set_data(replace);
            return;
        }
}

void SinglyLinkedList::print()
{
    if (this->head == nullptr)
    {
        std::cout << "Empty" << std::endl;
        return;
    }

    for (Node *index = this->head; index != nullptr; index = index->get_next())
        std::cout << index->get_data() << " -> ";
    std::cout << "nullptr" << std::endl;
}

SinglyLinkedList::~SinglyLinkedList()
{
    while (head != nullptr)
    {
        Node *temp = this->head;
        this->head = this->head->get_next();
        delete temp;
    }
}