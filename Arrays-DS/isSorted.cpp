#include <iostream>
using namespace std;

struct Array{
    int A[16];
    int size;
    int length;
};

int isSorted(Array arr)
{
    for(int i=0; i<arr.length-1; i++)
    {
        if(arr.A[i]>arr.A[i+1])
        {
            return 0;
        }
    }
    return 1;
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
    cout<<isSorted(arr);
    // Display(arr);
    return 0;
}   