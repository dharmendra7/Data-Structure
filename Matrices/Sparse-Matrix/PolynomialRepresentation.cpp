/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

class Term
{
    public:
        int coeff;
        int exp;
};

class Poly
{
    int n;
    Term *terms; // dynamic array to store the collection of terms for the polynomial
    
    public:
        void create()
        {
            cout<<"Enter the number of non-zero elements\n";
            cin>>n;
            
            terms = new Term[n];
            
            cout<<"Enter the Coefficient & Exponent of each term\n";
            for(int i=0; i<n; i++)
            {
                cin>>terms[i].coeff >> terms[i].exp;
            }
        }
        
        void display()
        {
            for(int i=0; i<n; i++)
            {
                cout<<terms[i].coeff << "x^" << terms[i].exp;
                if(i != n-1)
                    cout<<" + ";
            }
            cout<<endl;
        }
};

int main()
{
    Poly p;
    p.create();
    p.display();

    return 0;
}