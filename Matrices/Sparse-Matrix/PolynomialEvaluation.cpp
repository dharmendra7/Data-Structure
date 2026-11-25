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

        int evaluate(int x)
        {
            int result = 0;
            for(int i=0; i<n; i++)
            {
                // result += terms[i].coeff * pow(x, terms[i].exp);
                int power = 1;
                for(int j=0; j<terms[i].exp; j++)
                {
                    power *= x;
                }
                result += terms[i].coeff * power;
            }
            return result;
        }
};

int main()
{
    Poly p;
    p.create();
    p.display();

    int x;
    cout << "Enter the value of x to evaluate the polynomial: ";
    cin >> x;
    int result = p.evaluate(x);
    cout << "The value of the polynomial at x = " << x << " is: " << result << endl;

    return 0;
}