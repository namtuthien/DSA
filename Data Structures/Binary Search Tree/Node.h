#pragma once

class Node
{
private:
    int data;
    Node *left;
    Node *right;

public:
    Node(int = 0);

    int get_data();
    Node *get_left();
    Node *get_right();
    void set_data(int);
    void set_left(Node *);
    void set_right(Node *);

    ~Node();
};