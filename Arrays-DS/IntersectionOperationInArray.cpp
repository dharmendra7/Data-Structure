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
        if(arr1->A[i]<arr2->A[j]) // If a<b then copy in c
            // arr3->A[k++] = arr1->A[i++];
            i++;
        else if(arr2->A[j]<arr1->A[i]) // If b<c then copy in c
            // arr3->A[k++] = arr2->A[j++];
            j++;
        else{                                // else (means a=b then copy one of single array element cause they both are same)
            arr3->A[k++] = arr1->A[i++];
            j++;           // Increasing both indexes. 
        }
    }
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
    arr3 = Intersection(&arr1, &arr2);
    Display(*arr3);
    return 0;
}


/*Intersection using class*/

#include <iostream>
using namespace std;

class Array{
    private:
        int *A;
        int size;
        int length;
        
    public:
        Array(int sz)
        {
            size = sz;
            length = 0;
            A = new int[size];
        }
        
        ~Array()
        {
            delete[] A;
        }
        
        void Append(int x)
        {
            if(length<size)
                A[length++] = x;
        }
        
        Array *Intersection(Array *arr2)
        {
            int i, j, k;
            i=j=k = 0;
            Array *arr3 = new Array(size);
            
            while(i<length && j<arr2->length)
            {
                if(A[i]<arr2->A[j])
                    i++;
                else if(arr2->A[j]<A[i])
                    j++;
                else
                {
                    arr3->A[k++] = A[i++];
                    j++;
                }
            }
            arr3->length = k;
            
            return arr3;
        }
        
        void Display()
        {
            for(int i=0; i<length; i++)
                cout<<A[i]<<" ";
        }
};


int main()
{
    int size1, size2;
    cout<<"Enter the size of array 1: ";
    cin>>size1;
    
    Array arr1(size1);
    cout<<"Enter the elements for array 1: \n";
    for(int i=0; i<size1; i++)
    {
        int x;
        cin>>x;
        arr1.Append(x);
    }
    
    cout<<"Enter the size of array 2: ";
    cin>>size2;
    
    Array arr2(size2);
    cout<<"Enter the elements for array 2: \n";
    for(int i=0; i<size2; i++)
    {
        int x;
        cin>>x;
        arr2.Append(x);
    }
    
    Array *arr3 = arr1.Intersection(&arr2);
    
    cout<<"Intersection: ";
    arr3->Display();
    
    delete arr3;
    return 0;
}