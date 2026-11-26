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
        
        Poly add(Poly &p)
        {
            int i=0,j=0,k=0;
            
            Poly sum;
            sum.terms = new Term[n+p.n];
            
            while(i<n && j<p.n)
            {
                if(terms[i].exp == p.terms[j].exp)
                {
                    sum.terms[k].coeff = terms[i].coeff + p.terms[j].coeff;
                    sum.terms[k].exp = terms[i].exp;
                    i++;
                    j++;
                    k++;
                }
                else if(terms[i].exp < p.terms[j].exp)
                {
                    sum.terms[k++] = p.terms[j++];
                }
                else
                {
                    sum.terms[k++] = terms[i++];
                }
            }
            
            // Copy remaining terms from first polynomial
            while (i < n) {
                sum.terms[k++] = terms[i++];
            }
    
            // Copy remaining terms from second polynomial
            while (j < p.n) {
                sum.terms[k++] = p.terms[j++];
            }
    
            sum.n = k; // Set actual number of non-zero terms in result
            return sum;
            
            return sum;
        }
};

int main()
{
    Poly p1;
    cout<<"First polynomial:\n";
    p1.create();
    
    Poly p2;
    cout<<"Second polynomial:\n";
    p2.create();
    
    Poly p3 = p1.add(p2);
    cout << "Addition of First and Second Polynomial is: ";
    p3.display();
    
    
    // p.display();

    // int x;
    // cout << "Enter the value of x to evaluate the polynomial: ";
    // cin >> x;
    // int result = p.evaluate(x);
    // cout << "The value of the polynomial at x = " << x << " is: " << result << endl;

    return 0;
}