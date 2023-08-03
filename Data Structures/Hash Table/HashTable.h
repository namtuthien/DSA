#pragma once
#include "SinglyLinkedList.h"

class HashTable
{
private:
    SinglyLinkedList *bucket[100];
    int size;
    int _hash(int);

public:
    HashTable(int = 0);

    void insert_node(int);
    void delete_node(int);
    void print();

    ~HashTable();
};