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


/*Using class*/

#include <iostream>
using namespace std;

class Array
{
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
        if (length < size)
            A[length++] = x;
    }

    Array *Difference(Array *arr2)
    {
        int i, j, k;
        i = j = k = 0;

        Array *arr3 = new Array(size);

        while (i < length && j < arr2->length)
        {
            if (A[i] < arr2->A[j])
                arr3->Append(A[i++]);
            else if (arr2->A[j] < A[i])
                j++;
            else
            {
                i++;
                j++;
            }
        }

        for (; i < length; i++)
            arr3->Append(A[i]);

        return arr3;
    }

    void Display()
    {
        for (int i = 0; i < length; i++)
            cout << A[i] << " ";
    }
};

int main()
{
    int size1, size2;

    cout << "Enter the size of Array 1: ";
    cin >> size1;
    Array arr1(size1);

    cout << "Enter elements for Array 1:\n";
    for (int i = 0; i < size1; i++)
    {
        int x;
        cin >> x;
        arr1.Append(x);
    }

    cout << "Enter the size of Array 2: ";
    cin >> size2;
    Array arr2(size2);

    cout << "Enter elements for Array 2:\n";
    for (int i = 0; i < size2; i++)
    {
        int x;
        cin >> x;
        arr2.Append(x);
    }

    Array *arr3 = arr1.Difference(&arr2);

    cout << "Difference: ";
    arr3->Display();

    delete arr3;

    return 0;
}
