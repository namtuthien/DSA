#include "Node.cpp"
#include "BinarySearchTree.cpp"

int main()
{
    BinarySearchTree *bst = new BinarySearchTree;
    bst->insert_node(2);
    bst->insert_node(5);
    bst->insert_node(3);
    bst->insert_node(1);
    bst->insert_node(4);
    bst->insert_node(7);
    bst->delete_node(3);
    bst->print();
    delete bst;
}