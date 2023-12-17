#include <iostream>
using namespace std;

int main()
{
    int A[6] = {1,2,3,4,5,6};
    int key = 3;
    int length = 6;
    
    for(int i = 0; i<length; i++)
    {
        if(A[i] == key)
        {
            // cout<<"working";
            // cout<<i;
            return i;
        }
    }
    return -1;
    
}


// Improving the Linear Search:
// There are two options 
// i) Transpostion
// ii) Move to Head/Front


//########### i) Transpostion ###############3
#include <iostream>
using namespace std;


void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int A[6] = {1,2,3,4,5,6};
    int key = 3;
    int length = 6;
    
    for(int i = 0; i<length; i++)
    {
        if(A[i] == key)
        {
            swap(&A[i], &A[i-1]);
        }
    }
    for(int i = 0; i < length; i++)
    {
        cout<<A[i]<<" ";
    }
    
}


// #############i) Move to Head#################

#include <iostream>
using namespace std;


void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int A[6] = {1,2,3,4,5,6};
    int key = 3;
    int length = 6;
    
    for(int i = 0; i<length; i++)
    {
        if(A[i] == key)
        {
            swap(&A[i], &A[0]);
        }
    }
    for(int i = 0; i < length; i++)
    {
        cout<<A[i]<<" ";
    }
    
}
