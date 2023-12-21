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
        
       
        int Sum()
        {
            int sum = 0;
            for(int i = 0; i<size; i++)
                sum = sum + A[i];
            return sum;
        }
        
        int FindMissing()
        {
            int n = A[length-1];
            int n_number_sum = n*(n+1)/2;
            int difference = n_number_sum - Sum();
            
            if(difference != 0)
            {
                int missing_element = difference;
                return missing_element;
            }
            return -1;
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
    cout<<"Missing element Missing: "<<arr.FindMissing();
}