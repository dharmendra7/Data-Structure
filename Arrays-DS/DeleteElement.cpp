#include <iostream>
using namespace std;

int main()
{
    int A[6] = {1,2,3,4,5,6};
    int delete_element_index = 3;
    int length = 6;
    
    for(int i = delete_element_index; i<length-1; i++)
    {
        A[i] = A[i+1];
    }
    length--;
    
    for(int i=0; i<length; i++)
    {
        cout<<A[i]<<" ";
    }
    
    
    // return 0;
    
}