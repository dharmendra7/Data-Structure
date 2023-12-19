/*
    - Difference means we want all the elements which are not in B
    - So subtraact the common elements between A and B.
    - Take only elements which are A not in B.
*/

#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};


struct Array* Intersection(struct Array* arr1, struct Array* arr2)
{
    int i, j, k;
    i=j=k=0;
    struct Array* arr3 = new struct Array;
    
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i])
            j++;
        else{ 
            i++;
            j++;
        }
    }
    arr3->length = k;
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
    struct Array arr1 = {{3,4,5,6,10},10,5};
    struct Array arr2 = {{2,4,5,7,12},10,5};
    struct Array* arr3;
    arr3 = Intersection(&arr1, &arr2);
    Display(*arr3);
    return 0;
}