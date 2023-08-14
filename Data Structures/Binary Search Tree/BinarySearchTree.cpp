#include <iostream>
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
    this->root = nullptr;
}

void BinarySearchTree::insert_node(int data)
{
    Node *new_node = new Node(data);
    if (this->root == nullptr)
    {
        this->root = new_node;
        return;
    }

    _insert_node(this->root, new_node);
}

void BinarySearchTree::_insert_node(Node *current_node, Node *new_node)
{
    if (new_node->get_data() < current_node->get_data())
    {
        if (current_node->get_left() == nullptr)
        {
            current_node->set_left(new_node);
            return;
        }

        this->_insert_node(current_node->get_left(), new_node);
        return;
    }

    if (new_node->get_data() > current_node->get_data())
    {
        if (current_node->get_right() == nullptr)
        {
            current_node->set_right(new_node);
            return;
        }

        this->_insert_node(current_node->get_right(), new_node);
        return;
    }
}

void BinarySearchTree::delete_node(int data)
{
    if (this->root == nullptr)
        return;

    _delete_node(this->root, data);
}

Node *BinarySearchTree::_find_left_most(Node *current_node)
{
    while (current_node->get_left() != nullptr)
        current_node = current_node->get_left();

    return current_node;
}

Node *BinarySearchTree::_delete_node(Node *current_node, int data)
{
    if (current_node == nullptr)
        return nullptr;
    else if (data < current_node->get_data())
        current_node->set_left(_delete_node(current_node->get_left(), data));
    else if (data > current_node->get_data())
        current_node->set_right(_delete_node(current_node->get_right(), data));
    else if (current_node->get_left() != nullptr && current_node->get_right() != nullptr)
    {
        Node *temp = _find_left_most(current_node->get_right());
        current_node->set_data(temp->get_data());
        current_node->set_right(_delete_node(current_node->get_right(), current_node->get_data()));
    }
    else
    {
        Node *temp = current_node;
        if (current_node->get_left() == nullptr)
            current_node = current_node->get_right();
        else if (current_node->get_right() == nullptr)
            current_node = current_node->get_left();
        delete temp;
    }

    return current_node;
}

void BinarySearchTree::print()
{
    if (this->root == nullptr)
    {
        std::cout << "Empty" << std::endl;
        return;
    }

    int choice;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "1. Node - Left - Right (NLR)" << std::endl;
    std::cout << "2. Node - Right - Left (NRL)" << std::endl;
    std::cout << "3. Left - Node - Right (LNR)" << std::endl;
    std::cout << "4. Left - Right - Node (LRN)" << std::endl;
    std::cout << "5. Right - Node - Left (RNL)" << std::endl;
    std::cout << "6. Right - Left - Node (RLN)" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Your choice: ";
    std::cin >> choice;

    if (choice == 1)
        _NLR(this->root);
    else if (choice == 2)
        _NRL(this->root);
    else if (choice == 3)
        _LNR(this->root);
    else if (choice == 4)
        _LRN(this->root);
    else if (choice == 5)
        _RNL(this->root);
    else if (choice == 6)
        _RLN(this->root);
    std::cout << std::endl;
}

void BinarySearchTree::_NLR(Node *current_node)
{
    if (current_node != nullptr)
    {
        std::cout << current_node->get_data() << " ";
        _NLR(current_node->get_left());
        _NLR(current_node->get_right());
    }
}

void BinarySearchTree::_NRL(Node *current_node)
{
    if (current_node != nullptr)
    {
        std::cout << current_node->get_data() << " ";
        _NRL(current_node->get_right());
        _NRL(current_node->get_left());
    }
}

void BinarySearchTree::_LNR(Node *current_node)
{
    if (current_node != nullptr)
    {
        _LNR(current_node->get_left());
        std::cout << current_node->get_data() << " ";
        _LNR(current_node->get_right());
    }
}

void BinarySearchTree::_LRN(Node *current_node)
{
    if (current_node != nullptr)
    {
        _LRN(current_node->get_left());
        _LRN(current_node->get_right());
        std::cout << current_node->get_data() << " ";
    }
}

void BinarySearchTree::_RNL(Node *current_node)
{
    if (current_node != nullptr)
    {
        _NLR(current_node->get_right());
        std::cout << current_node->get_data() << " ";
        _NLR(current_node->get_left());
    }
}

void BinarySearchTree::_RLN(Node *current_node)
{
    if (current_node != nullptr)
    {
        _RLN(current_node->get_right());
        _RLN(current_node->get_left());
        std::cout << current_node->get_data() << " ";
    }
}

void BinarySearchTree::_clear(Node *current_node)
{
    if (current_node != nullptr)
    {
        _clear(current_node->get_left());
        _clear(current_node->get_right());
        delete current_node;
    }
}

BinarySearchTree::~BinarySearchTree()
{
    if (this->root == nullptr)
        return;

    _clear(this->root);
}
