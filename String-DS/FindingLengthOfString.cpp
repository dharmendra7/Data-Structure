#include <iostream>
using namespace std;

int main()
{
    char s[]= "dharmendra";
    int i;
    for(i=0;s[i]!='\0';i++){}
    cout<<"Length of string is: "<<i;
    cout<<s;
}