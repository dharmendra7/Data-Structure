#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};


struct Array* Merge(struct Array* arr1, struct Array* arr2)
{
    int i, j, k;
    i=j=k=0;
    struct Array* arr3 = new struct Array;
    
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for(;i<arr1->length;i++)
        arr3->A[k++] = arr1->A[i];
    for(;i<arr2->length;i++)
        arr3->A[k++] = arr2->A[i];
        
    arr3->length = arr1->length + arr2->length;
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
    struct Array arr2 = {{2,3,7,9,11},10,5};
    struct Array* arr3;
    arr3 = Merge(&arr1, &arr2);
    Display(*arr3);
    return 0;
}

// ###Explaination###

// 'struct' is user-defined data that allows you to group variables of different data types under a single name.

// Return Type: The return type of the Merge function is struct Array*, indicating that it returns a pointer to a structure of type Array.

// Dynamic Allocation: Inside the function, a new struct Array is dynamically allocated using new. This means memory is allocated on the heap, and the function returns a pointer to this dynamically allocated memory.

// Usage in main Function: In the main function, the returned pointer is stored in the arr3 variable, which is declared as a pointer to struct Array.
// struct Array* arr3;
// arr3 = Merge(&arr1, &arr2);

// Display Function: The Display function takes an argument of type struct Array, not a pointer. When calling Display(*arr3), the dereference operator (*) is used to pass the actual structure to the function.
// void Display(struct Array arr);
// This design allows the Merge function to create a new Array structure dynamically and return a pointer to it, which can be useful when dealing with functions that need to allocate memory for new structures or objects. Keep in mind that when using dynamic memory allocation, it's the responsibility of the caller to free the memory when it's no longer needed to avoid memory leaks. In this case, you would typically use delete to free the memory allocated by new.
