#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};


struct Array* Union(struct Array* arr1, struct Array* arr2)
{
    int i, j, k;
    i=j=k=0;
    struct Array* arr3 = new struct Array;
    
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j]) // If a<b then copy in c
            arr3->A[k++] = arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i]) // If b<c then copy in c
            arr3->A[k++] = arr2->A[j++];
        else{                                // else (means a=b then copy one of single array element cause they both are same)
            arr3->A[k++] = arr1->A[i++];
            j++;           // Increasing both indexes. 
        }
    }
    for(;i<arr1->length;i++)
        arr3->A[k++] = arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++] = arr2->A[j];
        
    arr3->length = k; // we cant take lenth as (arr1->length + arr2->length;) so length is value of k
    arr3->size = 10;
    
    return arr3;
}

void Display(struct Array arr)
{
    for(int i=0; i<arr.length; i++)
        cout<<arr.A[i]<<" ";
}

int main()
{
    struct Array arr1 = {{1,4,5,6,8},10,5};
    struct Array arr2 = {{2,4,7,9,11},10,5};
    struct Array* arr3;
    arr3 = Union(&arr1, &arr2);
    Display(*arr3);
    return 0;
}