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
            length;
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
       
        void FindaPairWithSum(int k)
        {
            int l = min();
            int h = max();
            Array *arr2 = new Array(h);
            
            for(int i=0; i<h;i++)
                arr2->Append(0);
            
            for(int i=0; i<=length; i++)
            {
                if(A[i] <= k && arr2->A[k - A[i]] != 0)
                     cout<<"pair ("<<A[i]<<", "<<k-A[i]<<")\n";
                else
                    arr2->A[A[i]]++;
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
    cout<<"Pairs are: \n";
    int k = 10;
    arr.FindaPairWithSum(k);
}