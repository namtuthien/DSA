#include <iostream>
#include "HashTable.h"

HashTable::HashTable(int size)
{
    this->size = size;
    for (int i = 0; i < this->size; ++i)
        bucket[i] = nullptr;
}

int HashTable::_hash(int data) { return abs(data) % this->size; }

void HashTable::insert_node(int data)
{
    const int KEY = _hash(data);

    if (bucket[KEY] == nullptr)
        this->bucket[KEY] = new SinglyLinkedList;

    bucket[KEY]->insert_node(data);
}

void HashTable::delete_node(int data)
{
    const int KEY = _hash(data);
    bucket[KEY]->delete_node(data);
}

void HashTable::print()
{
    for (int i = 0; i < this->size; ++i)
    {
        std::cout << "Bucket[" << i << "]: ";

        if (bucket[i] == nullptr)
        {
            std::cout << "Empty" << std::endl;
            continue;
        }

        bucket[i]->print();
    }
}

HashTable::~HashTable()
{
    for (int i = 0; i < 100; ++i)
        delete bucket[i];
}