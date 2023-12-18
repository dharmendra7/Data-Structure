#include <iostream>
using namespace std;

struct Array{
    int A[14];
    int size;
    int lenght;
};

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void ReverseBySwap(Array *arr)
{
    int i, j;
    for(i = 0, j = arr->lenght-1; i<j; i++, j--)
    {
        swap(arr->A[i], arr->A[j]);
    }
}

void Display(Array arr)
{
    for(int i=0; i<arr.lenght; i++)
    {
        cout<<arr.A[i]<<" ";
    }
}

int main() {
    Array arr = {{1,3,4,5,6,7,8,9,11,13,16,17,18,33}, 15, 14};
    ReverseBySwap(&arr);
    Display(arr);
    return 0;
}