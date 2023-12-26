#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void reverse(char name[])
{   
    int i, j;
    for(i=0; name[i]!='\0'; i++)
    {}
    --i;
    for(j=0; j<i; j++,i--)
    {
        swap(name[j], name[i]);
    }
    cout<<"Reversed String: "<<name;
    
}

int main()
{
    char s[]= "Dhar@123";
    reverse(s);
}