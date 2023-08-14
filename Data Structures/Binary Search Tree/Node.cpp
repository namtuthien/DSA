#include "Node.h"

Node::Node(int data)
{
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

int Node::get_data() { return this->data; }
Node *Node::get_left() { return this->left; }
Node *Node::get_right() { return this->right; }

void Node::set_data(int data) { this->data = data; }
void Node::set_left(Node *node) { this->left = node; }
void Node::set_right(Node *node) { this->right = node; }

Node::~Node()
{
    this->data = 0;
    this->left = nullptr;
    this->right = nullptr;
}