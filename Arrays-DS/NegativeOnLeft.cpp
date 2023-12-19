#include <iostream>
using namespace std;

struct Array{
    int A[16];
    int size;
    int length;
};

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Rearrange(Array *arr)
{
    int i = 0;
    int j = arr->length-1;
    while(i<j){
        while(arr->A[i]<0){i++;}
        while(arr->A[j]>=0){j--;}
        if(i<j)
        {
            swap(arr->A[i], arr->A[j]);
        }
    }
}

void Display(Array arr)
{
    for(int i=0; i<arr.length; i++)
    {
        cout<<arr.A[i]<<" ";
    }
}

int main() {
    Array arr = {{-1,3,4,5,6,7,8,-9,-11,13,-16,17}, 24, 12};
    Rearrange(&arr);
    Display(arr);
    return 0;
}   