#include <iostream>
using namespace std;

int main()
{
    int A[6] = {1,2,3,4,5,6};
    int inserted_element = 10;
    int inserted_element_index = 3;
    int length = 6;
    
    for(int i = length; i>inserted_element_index; i--)
    {
        A[i] = A[i-1];
    }
    A[inserted_element_index] = inserted_element;
    length++;
    
    for(int i = 0; i<length; i++)
    {
        cout<<A[i];
    }
    // return 0;
    
}