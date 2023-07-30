#pragma once
#include "Node.h"

class SinglyLinkedList
{
private:
    Node *head;

public:
    SinglyLinkedList();

    void insert_node(int);
    void delete_node(int);
    void update_node(int, int);
    void print();

    ~SinglyLinkedList();
};