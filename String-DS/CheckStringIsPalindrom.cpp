#include <iostream>
using namespace std;

int main ()
{
    int i, j;
    char s[] = "madam2";
    
    for (i = 0; s[i] != '\0'; i++)
    {}
    i = i-1;
    for(j=0; j<i; j++, i--)
    {
        if(s[j]!=s[i])
        {
            cout<<"String is not palindrome\n";
            break;
        }
    }
    cout<<s[i]<<" <- s[i] "<<s[j]<<" <- s[j]";
    if(s[i]==s[j])
        cout<<"String is palindrome\n";
}
