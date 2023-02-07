#include <iostream>
using namespace std;
void merge(int*, int, int, int);
void mergeSort(int* array, int small, int big)
{
    int mid;
    if (small < big) {
       
        mid = (small+ big) / 2;
        mergeSort(array, small, mid);
        mergeSort(array, mid + 1, big);
       
        merge(array, small, big, mid);
    }
}

void merge(int* array, int small, int big, int mid)
{
    int x, y, z, c[50];
    x = small;
    z = small;
    y = mid + 1;
    while (x <= mid && y <= big) {
        if (array[x] < array[y]) {
            c[z] = array[x];
            z++;
            x++;
        }
        else {
            c[z] = array[y];
            z++;
            y++;
        }
    }
    while (x <= mid) {
        c[z] = array[x];
        z++;
        x++;
    }
    while (y <= big) {
        c[z] = array[y];
        z++;
        y++;
    }
    for (x = small; x < z; x++) {
        array[x] = c[x];
    }
}

int main()
{
    int array[50], element;
    cout << "how many elements you want to sorted:";
    cin >> element;
    cout << "Enter " << element << " elements to be sorted:";
    for (int x = 0; x < element; x++) {
        cin >> array[x];
    }
    mergeSort(array, 0, element - 1);
    cout << "Sorted array" << endl;
    for (int x = 0; x < element; x++)
    {
        cout << array[x] <<endl;
    }
}