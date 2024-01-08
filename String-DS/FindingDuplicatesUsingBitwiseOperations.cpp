#include <iostream>
using namespace std;

int main()
{
    char A[] = "finding";
    long int H=0, x=0;
    
    // cout<<"working";
    for(int i=0; A[i]!='\0'; i++)
    {
        x = 1;
        x = x << (A[i]-'a'); // Left Shifting
        
        if((x & H) > 0) // Masking
            cout<<A[i]<<" is duplicate.\n";
        
        else
            H = x | H; // merging
    }
}
