#include <iostream>

using namespace std;

class Dyn_array
{
private:
    int *arr;
    int size;

public:
    Dyn_array(int s)
    {
        arr = new int[s];
        for (int i = 0; i < s; i++)
        {
            arr[i] = 0;
        }
        size = s;
        cout << "Array created of size " << s << "\n";
    }

    void get_elements()
    {
        cout << "Enter elements of array:\n";
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
    }

    void display()
    {
        cout << "The array is: \n";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << "\n";
        }
    }

    void del_ele(int index)
    {
        if (index > size - 1 || index < 0)
        {
            cout << "Out of bounds\n";
            return;
        }
        int *arr1 = new int[size - 1];
        int j = 0;
        for (int i = 0; i < size; i++)
        {
            if (i != index)
            {
                arr1[j] = arr[i];
                j++;
            }
        }
        delete[] arr;
        arr = arr1;
        arr1 = NULL;
        size--;
    }

    int get_size()
    {
        return size;
    }

    void insert(int index, int value)
    {
        if (index > size - 1 || index < 0)
        {
            cout << "Out of bounds\n";
            return;
        }
        int *arr1 = new int[size + 1];
        int j = 0;
        for (int i = 0; i < size + 1; i++)
        {
            if (i == index)
            {
                arr1[i] = value;
                i++;
            }
            arr1[i] = arr[j];
            j++;
        }
        size++;
        delete[] arr;
        arr = arr1;
        arr1 = NULL;
    }

    int linear_search(int value)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == value)
            {
                return i;
            }
        }
        cout << "Element not found\n";
    }

    void binary_search(int value)
    {
        int start = 0;
        int end = size - 1;
        int mid = 0;
        while (start <= end)
        {
            mid = (start + end) / 2;
            if (value < arr[mid])
            {
                end = mid - 1;
            }
            else if (value > arr[mid])
            {
                start = mid + 1;
            }
            else
            {
                cout << "Element found at index: " << mid;
                return;
            }
        }
        cout << "Element not found";
        return;
    }
};