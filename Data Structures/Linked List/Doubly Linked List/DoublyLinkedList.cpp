#include <iostream>
#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}

void DoublyLinkedList::insert_node(int data)
{
    Node *new_node = new Node(data);

    if (this->head == nullptr)
    {
        this->head = new_node;
        this->tail = new_node;
        return;
    }

    this->tail->set_next(new_node);
    new_node->set_prev(this->tail);
    this->tail = new_node;
}

void DoublyLinkedList::delete_node(int data)
{
    if (this->head == nullptr)
        return;

    if (this->head->get_data() == data)
    {
        Node *temp = this->head;
        this->head = this->head->get_next();
        this->head->set_prev(nullptr);
        delete temp;
        return;
    }

    if (this->tail->get_data() == data)
    {
        Node *temp = this->tail;
        this->tail = this->tail->get_prev();
        this->tail->set_next(nullptr);
        delete temp;
        return;
    }

    for (Node *index = this->head->get_next(); index != this->tail; index = index->get_next())
    {
        if (index->get_data() == data)
        {
            Node *temp = index;
            index->get_prev()->set_next(index->get_next());
            index->get_next()->set_prev(index->get_prev());
            delete temp;
            return;
        }
    }
}

void DoublyLinkedList::update_node(int find, int replace)
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

void DoublyLinkedList::print_from_head()
{
    if (this->head == nullptr)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }

    std::cout << "nullptr <- head: ";
    for (Node *index = this->head; index != nullptr; index = index->get_next())
        std::cout << index->get_data() << " <--> ";
    std::cout << "\b\b\b\b\b:tail -> nullptr" << std::endl;
}

void DoublyLinkedList::print_from_tail()
{
    if (this->tail == nullptr)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }

    std::cout << "nullptr <- tail: ";
    for (Node *index = this->tail; index != nullptr; index = index->get_prev())
        std::cout << index->get_data() << " <--> ";
    std::cout << "\b\b\b\b\b:head -> nullptr" << std::endl;
}

DoublyLinkedList::~DoublyLinkedList()
{
    while (head != nullptr)
    {
        Node *temp = this->head;
        this->head = this->head->get_next();
        delete temp;
    }
}