#include <iostream>
using namespace std;

struct Array{
    int A[16];
    int size;
    int length;
};

void InsertElementInSortedArray(Array *arr, int element)
{
    int i = arr->length -1;
    while(i>=0 && element<arr->A[i])
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = element;
    arr->length++;
}

void Display(Array arr)
{
    for(int i=0; i<arr.length; i++)
    {
        cout<<arr.A[i]<<" ";
    }
}

int main() {
    Array arr = {{1,3,4,5,6,7,8,9,11,13,16,17}, 24, 12};
    InsertElementInSortedArray(&arr, 2);
    Display(arr);
    return 0;
}   