#pragma once

class Array
{
private:
    int arr[100];
    int length;

    int _hoare_partition(int, int);
    void _hoare_quick_sort(int, int);

    int _lomuto_partition(int, int);
    void _lomuto_quick_sort(int, int);

    void _merge(int, int, int, int);
    void _merge_sort(int, int);

    void _heapify(int, int);

public:
    Array(int = 0, int = 0);

    void input();
    void input_auto(int = 10, int = 30, int = -10, int = 20);
    void print();

    void interchange_sort();
    void selection_sort();
    void insertion_sort();
    void bubble_sort();
    void shaker_sort();

    void hoare_quick_sort();
    void lomuto_quick_Sort();
    void merge_sort();
    void heap_sort();

    void linear_search(int);
    void binary_search(int);
    void intepolation_search(int);

    ~Array();
};