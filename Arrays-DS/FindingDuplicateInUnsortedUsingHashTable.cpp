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
            A = new int[sz];
        }
        
        void Append(int x)
        {
            if(length < size)
                A[length++] = x;
        }
        
        int max()
        {
            int maxi = A[0];
            for(int i=1; i<length; i++)
            {
                if(A[i]>maxi)
                {
                    maxi=A[i];
                }
            }
            return maxi;
        }
        
        int min()
        {
            int min = A[0];
            for(int i=1; i<length; i++)
            {
                if(A[i]<min)
                {
                    min=A[i];
                }
            }
            return min;
        }
       
        void FindDuplicateUsingHashTable()
        {
            int l = min();
            int h = max();
            Array *arr2 = new Array(h);
            
            for(int i=0; i<=h;i++)
                arr2->Append(0);
            for(int i=0; i<length; i++)
                arr2->A[A[i]]++;
            for(int i=l; i<=h; i++)
            {
                if(arr2->A[i]>1)
                    cout<<i<<" appering "<<arr2->A[i]<<" times.\n";
            }
        }
};

int main()
{
    int size;
    cout<<"Enter the size: ";
    cin>>size;
    
    Array arr(size);
    
    cout<<"Enter the elements: \n";
    for(int i=0; i<size; i++)
    {
        int x;
        cin>>x;
        arr.Append(x);
    }
    cout<<"Missing element Missing: ";
    arr.FindDuplicateUsingHashTable();
}