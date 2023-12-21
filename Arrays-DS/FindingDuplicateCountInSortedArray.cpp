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
       
        void FindDuplicateElements()
        {
            for(int i=0; i<length-1; i++)
            {
                if(A[i]==A[i+1])
                {
                    int j = i+1;
                    while(A[i]==A[j]){j++;}
                    cout<<A[i]<<" is appering "<<j-i<<" times.\n";
                    i=j-1;
                }
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
    cout<<"Duplicate Elements are: ";
    arr.FindDuplicateElements();
}