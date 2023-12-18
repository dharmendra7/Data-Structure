#include <iostream>
using namespace std;

struct Array{
    int A[14];
    int size;
    int lenght;
};

int sum(Array arr)
{
    int total = 0;
    for(int i = 0; i<arr.lenght; i++)
    {
        total += arr.A[i];
    }
    return total;
}

int max(Array arr)
{
    int maxi = arr.A[0];
    for(int i = 0; i<arr.lenght; i++)
    {
        if(maxi < arr.A[i])
        {
            maxi = arr.A[i];
        }
    }
    return maxi;
}

int min(Array arr)
{
    int mini = arr.A[0];
    for(int i = 0; i<arr.lenght; i++)
    {
        if(mini > arr.A[i])
        {
            mini = arr.A[i];
        }
    }
    return mini;
}

int get(int index, Array arr)
{
    if(index >=0 && index < arr.lenght)
    {
        return arr.A[index];
    }
}

int set(Array arr, int index, int x)
{
    if(index >=0 && index < arr.lenght)
    {
        arr.A[index] = x;
    }
}

int avg(Array arr)
{
    return sum(arr)/arr.lenght;
}
int main() {
    Array arr = {{1,3,4,5,6,7,8,9,11,13,16,17,18,33}, 16, 15};
    cout<<"Sum of elements : "<<sum(arr)<<endl;
    cout<<"Maximum of array : "<<max(arr)<<endl;
    cout<<"Minimum of array : "<<min(arr)<<endl;
    cout<<"Get element from array : "<<get(1,arr)<<endl;
    cout<<"Average of array : "<<avg(arr)<<endl;
    return 0;
}