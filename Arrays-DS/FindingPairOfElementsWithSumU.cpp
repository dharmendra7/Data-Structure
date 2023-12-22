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
       
        void FindaPairWithSum(int k)
        {
            for(int i=0; i<length-1; i++)
            {
                for(int j=i+1; j<length; j++)
                {
                    if(A[i]+A[j]==k)
                    {
                        cout<<"Pair ("<<A[i]<<", "<<A[j]<<")\n";
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
    cout<<"Duplicate Elements are: ";
    int k = 10;
    arr.FindaPairWithSum(k);
}