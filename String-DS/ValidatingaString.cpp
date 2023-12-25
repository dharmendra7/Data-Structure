#include <iostream>
using namespace std;

int Valid(char *name)
{
    int i;    for(i=0; name[i]!='\0';i++)
    {
    if(!(name[i]>=65 && name[i]<=90) &&
        !(name[i]>=97 && name[i]<=122) &&
        !(name[i]>=48 && name[i]<=57))
            return 0;
    }
    return 1;
}

int main()
{
    char *s= "Dhar@123";
    
    if(Valid(s))
        cout<<"String is valid!!!";
    else
        cout<<"String is invalid!!!";
    
}