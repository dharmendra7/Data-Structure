#include <iostream>
using namespace std;

struct Array{
    int A[14];
    int size;
    int lenght;
};

int main() {
    Array arr = {{1,3,4,5,6,7,8,9,11,13,16,17,18,33}, 15, 14};
    int brr[14];
    int i, j;
    for(i  = arr.lenght -1, j = 0; i>=0; i--, j++)
    {
        brr[j] = arr.A[i];
    }
    
    for( i =0; i<arr.lenght; i++)
    {
        arr.A[i] = brr[i];
    }
    for( i =0; i<arr.lenght; i++)
    {
        cout<<arr.A[i]<<" ";
    }
    return 0;
}