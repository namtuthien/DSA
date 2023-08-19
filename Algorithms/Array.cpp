#include <iostream>
#include <ctime>
#include "Array.h"

Array::Array(int length, int default_value)
{
    this->length = length;
    for (int i = 0; i < this->length; ++i)
        arr[i] = default_value;
}

void Array::input()
{
    std::cout << "Enter length of array: ";
    std::cin >> this->length;
    for (int i = 0; i < this->length; ++i)
    {
        std::cout << "arr[" << i << "] = ";
        std::cin >> arr[i];
    }
}

void Array::input_auto(int min_range_length, int max_range_length, int min_range_data, int max_range_data)
{
    srand(time(nullptr));
    std::cout << "Creating array with length [" << min_range_length << ", " << max_range_length << "] and data [" << min_range_data << ", " << max_range_data << "]." << std::endl;
    this->length = min_range_length + rand() % (max_range_length - min_range_length + 1);
    for (int i = 0; i < this->length; ++i)
        arr[i] = min_range_data + rand() % (max_range_data - min_range_data + 1);
    std::cout << "Done!!!" << std::endl;
}

void Array::print()
{
    std::cout << "Array:" << std::endl;
    for (int i = 0; i < this->length; ++i)
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
}

void Array::interchange_sort()
{
    for (int i = 0; i < this->length - 1; i++)
        for (int j = i + 1; j < this->length; j++)
            if (arr[i] > arr[j])
                std::swap(arr[i], arr[j]);
}

void Array::selection_sort()
{
    for (int i = 0; i < this->length - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < this->length; j++)
            if (arr[j] < arr[min_index])
                min_index = j;

        std::swap(arr[i], arr[min_index]);
    }
}

void Array::insertion_sort()
{
    for (int i = 1; i < this->length; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

void Array::bubble_sort()
{

    for (int i = 0; i < this->length - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < this->length - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }

        if (swapped == false)
            break;
    }
}

void Array::shaker_sort()
{
    int i = 0;
    int j = this->length - 1;

    while (i < j)
    {
        int swapped = false;
        for (int k = i + 1; k < j; k++)
            if (arr[k] < arr[k - 1])
            {
                std::swap(arr[k], arr[k - 1]);
                swapped = true;
            }

        if (swapped == false)
            break;

        swapped = false;
        for (int k = j - 1; k > i; k--)
            if (arr[k] < arr[k - 1])
            {
                std::swap(arr[k], arr[k - 1]);
                swapped = true;
            }

        i++;
        j--;
    }
}

int Array::_hoare_partition(int left, int right)
{
    int pivot = arr[left];
    int l = left - 1;
    int r = right + 1;

    while (true)
    {
        do
        {
            l++;
        } while (arr[l] < pivot);

        do
        {
            r--;
        } while (arr[r] > pivot);

        if (l < r)
            std::swap(arr[l], arr[r]);
        else
            return r;
    }
}

void Array::_hoare_quick_sort(int left, int right)
{
    if (left < right)
    {
        int pivot = _hoare_partition(left, right);
        _hoare_quick_sort(left, pivot);
        _hoare_quick_sort(pivot + 1, right);
    }
}

void Array::hoare_quick_sort()
{
    _hoare_quick_sort(0, this->length - 1);
}

int Array::_lomuto_partition(int left, int right)
{
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; ++j)
        if (arr[j] < pivot)
        {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    ++i;
    std::swap(arr[i], arr[right]);

    return i;
}

void Array::_lomuto_quick_sort(int left, int right)
{
    if (left < right)
    {
        int pivot = _lomuto_partition(left, right);
        _lomuto_quick_sort(left, pivot - 1);
        _lomuto_quick_sort(pivot + 1, right);
    }
}

void Array::lomuto_quick_Sort()
{
    _lomuto_quick_sort(0, this->length - 1);
}

void Array::_merge(int left_left, int left_right, int right_left, int right_right)
{
    int length = right_right - left_left + 1;
    int temp[length];
    int left = left_left;
    int right = right_left;
    for (int i = 0; i < length; ++i)
    {
        if (left > left_right)
            temp[i] = arr[right++];
        else if (right > right_right)
            temp[i] = arr[left++];
        else if (arr[left] <= arr[right])
            temp[i] = arr[left++];
        else
            temp[i] = arr[right++];
    }

    for (int i = 0; i < length; ++i)
        arr[left_left++] = temp[i];
}

void Array::_merge_sort(int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        _merge_sort(left, mid);
        _merge_sort(mid + 1, right);
        _merge(left, mid, mid + 1, right);
    }
}

void Array::merge_sort()
{
    _merge_sort(0, this->length - 1);
}

void Array::_heapify(int i, int n)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);
        _heapify(largest, n);
    }
}

void Array::heap_sort()
{
    for (int i = this->length / 2 - 1; i >= 0; --i)
        _heapify(i, this->length);

    for (int i = this->length - 1; i >= 0; --i)
    {
        std::swap(arr[i], arr[0]);
        _heapify(0, i);
    }
}

void Array::linear_search(int find)
{
    for (int i = 0; i < this->length; i++)
        if (arr[i] == find)
        {
            std::cout << find << " is in arr[" << i << "]." << std::endl;
            return;
        }
    std::cout << find << " is not found." << std::endl;
}

void Array::intepolation_search(int find)
{
    int left = 0;
    int right = this->length - 1;

    while (left <= right)
    {
        int mid = left + (right - left) * (find - arr[left]) / (arr[right] - arr[left]);
        if (find == arr[mid])
        {
            std::cout << find << " is in arr[" << mid << "]." << std::endl;
            return;
        }

        if (find < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    std::cout << find << " is not found." << std::endl;
}

// cach 2
// void Array::intepolation_search(int find)
// {
//     int left = 0;
//     int right = this->length - 1;

//     while (left <= right && find >= arr[left] && find <= arr[right])
//     {
//         if (left == right)
//         {
//             if (arr[left] == find)
//             {
//                 std::cout << find << " is in arr[" << left << "]." << std::endl;
//                 return;
//             }
//             std::cout << find << " is not found." << std::endl;
//         }

//         int pos = left + (((double)(right - left) /
//                            (arr[right] - arr[left])) *
//                           (find - arr[left]));

//         if (arr[pos] == find)
//         {
//             std::cout << find << " is in arr[" << pos << "]." << std::endl;
//             return;
//         }

//         if (arr[pos] < find)
//             left = pos + 1;
//         else
//             right = pos - 1;
//     }
//     std::cout << find << " is not found." << std::endl;
// }

void Array::binary_search(int find)
{
    int left = 0;
    int right = this->length - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (find == arr[mid])
        {
            std::cout << find << " is in arr[" << mid << "]." << std::endl;
            return;
        }

        if (find < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    std::cout << find << " is not found." << std::endl;
}

Array::~Array()
{
    for (int i = 0; i < this->length; ++i)
        arr[i] = 0;
    this->length = 0;
}