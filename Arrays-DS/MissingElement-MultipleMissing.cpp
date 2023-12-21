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
        
       
        void FindMissingUsingIndices()
        {
            int l = A[0];
            int h = A[length-1];
            int diff = l;
            
            for(int i=0; i<length; i++)
            {
                int new_diff = A[i] - i;
                if(new_diff != diff)
                {
                    while(diff<new_diff)
                    {
                        cout<<diff+i<<" ";
                        diff++;
                    }
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
    cout<<"Missing element Missing: ";
    arr.FindMissingUsingIndices();
}