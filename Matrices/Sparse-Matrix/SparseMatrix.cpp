#include <iostream>
using namespace std;


class Element
{
    public:
        int i;
        int j;
        int x;
};

class Sparse
{
    private:
        int m;        // Number of rows
        int n;        // Number of columns
        int num;      // Nubmer of non-zero elements
        Element *ele; // Pointer to element array
        
    public:
        Sparse(int m, int n, int num)
        {
            this->m=m;
            this->n=n;
            this->num=num;
            ele = new Element[num];
        };
        
        void read();
        void display();
            
        ~Sparse()
        {
            delete[] ele;
        }

};

void Sparse::read()    
{
    cout<<"Enter the coordinates and none-zero element\n";
    
    for(int i=0; i<num; i++)
    {
        cin>>ele[i].i >> ele[i].j >> ele[i].x;
    }
}

void Sparse::display()
{
    int c = 0;
    cout<<"Sparse Matrix\n";
    for(int k=0; k<m; k++)
    {
        // cout<<ele[k].i << " " << ele[k].j <<" " << ele[k].x << endl;
        for(int l=0; l<n; l++)
        {
            if (ele[c].i == k && ele[c].j == l)
            {
                cout<<ele[c++].x << " ";
            }
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}

int main()
{
    Sparse s1(4, 4, 3);
    s1.read();
    s1.display();

    return 0;
}