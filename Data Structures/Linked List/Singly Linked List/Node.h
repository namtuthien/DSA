#pragma once

class Node
{
private:
    int data;
    Node *next;

public:
    Node(int = 0);

    int get_data();
    Node *get_next();
    void set_data(int);
    void set_next(Node *);

    ~Node();
};