#pragma once
#include "Node.h"

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList();

    void insert_node(int);
    void delete_node(int);
    void update_node(int, int);
    void print_from_head();
    void print_from_tail();

    ~DoublyLinkedList();
};