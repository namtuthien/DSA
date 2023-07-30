#include "Node.h"

Node::Node(int data)
{
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
}

int Node::get_data() { return this->data; }
Node *Node::get_prev() { return this->prev; }
Node *Node::get_next() { return this->next; }

void Node::set_data(int data) { this->data = data; }
void Node::set_prev(Node *node) { this->prev = node; }
void Node::set_next(Node *node) { this->next = node; }

Node::~Node()
{
    this->data = 0;
    this->next = nullptr;
    this->prev = nullptr;
}