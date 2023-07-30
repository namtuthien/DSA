#include "Node.cpp"
#include "SinglyLinkedList.cpp"

int main()
{
    SinglyLinkedList list;
    list.insert_node(3);
    list.insert_node(2);
    list.insert_node(5);
    list.delete_node(5);
    list.print();
}