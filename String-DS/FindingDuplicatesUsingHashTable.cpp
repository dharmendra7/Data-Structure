#include <iostream>
using namespace std;


int main ()
{
    int i, j;
    char a[] = "finding";
    int h[26];
    
    for(int i=0; i<26; i++)
        h[i] = 0;
    
    for(int i=0; a[i]!='\0'; i++)
        h[a[i]-97]+=1;
    
    for(int i=0; i<26; i++)
    {
        if(h[i]>1)
        {
            char temp = i+97;
            cout<<"Character "<<temp<<" is occur "<<h[i]<<" times.\n";
        }
    }
    
    
}
