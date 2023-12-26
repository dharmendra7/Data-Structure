#include <iostream>
using namespace std;


int main ()
{
    int i, j;
    char s[] = "Dhar@123";
    
    for (i = 0; s[i] != '\0'; i++)
    {}
    
    char reversed[i];
    i = i-1;
    
    for(j=0; i>=0; j++, i--)
      reversed[j] = s[i];
      
    cout<<"Reversed String is: "<<reversed;

}
