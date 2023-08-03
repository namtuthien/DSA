#include "Node.cpp"
#include "SinglyLinkedList.cpp"
#include "HashTable.cpp"

int main()
{
    HashTable *hash_table = new HashTable(6);
    hash_table->insert_node(2);
    hash_table->insert_node(5);
    hash_table->insert_node(3);
    hash_table->insert_node(9);
    hash_table->insert_node(11);
    hash_table->insert_node(12);
    hash_table->insert_node(13);
    hash_table->print();
    delete hash_table;
}