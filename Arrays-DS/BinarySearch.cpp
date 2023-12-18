#include <iostream>
using namespace std;

struct Array{
    int A[14];
    int size;
    int lenght;
};


int BinarySearch(Array arr, int key)
{
    int l, h, mid;
    l = 0;
    h = arr.lenght-1;
    
    while(l<=h)
    {
        mid = (l+h)/2;
        if(key == arr.A[mid])
        {
            return mid;
        }
        else if(key < arr.A[mid])
        {
            h = mid -1;
        }
        else{
            l = mid +1;
        }
    }
    return -1;
}

int main() {
    Array arr = {{1,3,4,5,6,7,8,9,11,13,16,17,18,33}, 16, 15};
    int key = 44;
    cout<<BinarySearch(arr, key);

    return 0;
}