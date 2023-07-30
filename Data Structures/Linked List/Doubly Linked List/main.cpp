#include "Node.cpp"
#include "DoublyLinkedList.cpp"

int main()
{
    DoublyLinkedList *list = new DoublyLinkedList;
    list->insert_node(2);
    list->insert_node(5);
    list->insert_node(3);
    list->print_from_head();
    list->print_from_tail();
    delete list;
}