#include "Array.cpp"

int main()
{
    Array *arr = new Array;
    arr->input_auto();
    arr->print();
    arr->selection_sort();
    arr->print();
    arr->binary_search(3);
    delete arr;
}