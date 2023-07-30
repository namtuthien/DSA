#include "Node.cpp"
#include "Queue.cpp"

int main()
{
    Queue *queue = new Queue;
    queue->enqueue(2);
    queue->enqueue(5);
    queue->enqueue(3);
    queue->print();
    delete queue;
}
