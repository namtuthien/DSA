#pragma once
#include "Node.h"

class BinarySearchTree
{
private:
    Node *root;

    void _insert_node(Node *, Node *);
    Node *_delete_node(Node *, int);
    Node *_find_left_most(Node *);
    void _NLR(Node *);
    void _NRL(Node *);
    void _LNR(Node *);
    void _LRN(Node *);
    void _RNL(Node *);
    void _RLN(Node *);
    void _clear(Node *);

public:
    BinarySearchTree();

    void insert_node(int);
    void delete_node(int);
    void print();

    ~BinarySearchTree();
};