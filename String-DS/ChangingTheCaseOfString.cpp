#include <iostream>
using namespace std;

int main()
{
    char s[]= "DHARMENDRA";
    int i;
    for(i=0;s[i]!='\0';i++){
        s[i] = s[i]+32;
    }
    cout<<"Lowercase of string is: "<<s;
}

/* 
    - Below is the ASCII code of Alphabets:
        A -> 65         a -> 97         --->    97-65=32
        B -> 66         b -> 98         --->    98-66=32
            |
            |
        Z -> 90         z -> 122        --->    122-90=32

    - So the difference between lower case and upper case is 32
    - Therefor if you want to change into lowercase just add 32
    - Else subtract 32 to chnage into uppercase 
*/