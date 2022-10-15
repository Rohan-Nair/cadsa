#include <iostream>

using namespace std;

void swap(int &n1, int &n2);
void display(int *arr, int size);
void bubble_sort(int *arr, int start, int end);
void selection_sort(int *arr, int start, int end);
void insertion_sort(int *arr, int start, int end);
void merge_sort(int *arr, int start, int end);
void merge(int *arr, int start, int mid, int end);

int main()
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    bubble_sort(arr, 0, 6);
    display(arr, 7);
}

void bubble_sort(int *arr, int start, int end)
{
    for (int i = start; i < end; i++)
    {
        for (int j = start; j < end - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void display(int *arr, int size)
{
    cout << "\nArray is: \n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
}

void swap(int &n1, int &n2)
{
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

void selection_sort(int *arr, int start, int end)
{
    for (int i = start; i < end; i++)
    {
        int min_index = i;
        for (int j = i + 1; j <= end; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
}

void insertion_sort(int *arr, int start, int end)
{
    for (int i = start + 1; i <= end; i++)
    {
        int value = arr[i];
        int vacant = i;

        while (arr[vacant - 1] > value && vacant > 0)
        {
            arr[vacant] = arr[vacant - 1];
            vacant--;
        }
        arr[vacant] = value;
    }
}

void merge(int *arr, int start, int mid, int end)
{
    int size1 = mid - start + 1;
    int size2 = end - mid;

    int *arr1 = new int[size1];
    int *arr2 = new int[size2];

    for (int i = 0; i < size1; i++)
    {
        arr1[i] = arr[start + i];
    }
    for (int i = 0; i < size2; i++)
    {
        arr2[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = start;
    while (i < size1 && j < size2)
    {
        if (arr1[i] <= arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < size1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while (j < size2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }

    delete[] arr1;
    delete[] arr2;
}

void merge_sort(int *arr, int start, int end)
{
    int mid = (start + end) / 2;

    if (start >= end)
    {
        return;
    }

    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);

    merge(arr, start, mid, end);
}