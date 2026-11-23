// #include <iostream>
// using namespace std;


// class Element
// {
//     public:
//         int i;
//         int j;
//         int x;
// };

// class Sparse
// {
//     private:
//         int m;        // Number of rows
//         int n;        // Number of columns
//         int num;      // Nubmer of non-zero elements
//         Element *ele; // Pointer to element array
        
//     public:
//         Sparse(int m, int n, int num)
//         {
//             this->m=m;
//             this->n=n;
//             this->num=num;
//             ele = new Element[num];
//         };
        
//         Sparse(int m, int n, int num, int staticData[][4]) {
//             this->m = m;
//             this->n = n;
//             this->num = num;
//             ele = new Element[this->num]; // Change 'ele' if your pointer has a different name
        
//             for (int i = 0; i < num; i++) {
//                 ele[i].i = staticData[i][0]; // row
//                 ele[i].j = staticData[i][1]; // col
//                 ele[i].x = staticData[i][2]; // value
//             }
//         }
        
//         void read();
//         void display();
//         void add(Sparse &s);
            
//         ~Sparse()
//         {
//             delete[] ele;
//         }

// };

// void Sparse::read()    
// {
//     cout<<"Enter the coordinates and none-zero element\n";
    
//     for(int i=0; i<num; i++)
//     {
//         cin>>ele[i].i >> ele[i].j >> ele[i].x;
//     }
// }

// void Sparse::display()
// {
//     int c = 0;
//     cout<<"Sparse Matrix\n";
//     for(int k=0; k<m; k++)
//     {
//         // cout<<ele[k].i << " " << ele[k].j <<" " << ele[k].x << endl;
//         for(int l=0; l<n; l++)
//         {
//             if (ele[c].i == k && ele[c].j == l)
//             {
//                 cout<<ele[c++].x << " ";
//             }
//             else
//                 cout<<"0 ";
//         }
//         cout<<endl;
//     }
// }

// Sparse Sparse::add(Sparse &s)
// {
//     if(m != s.m || n != s.n)
//     {
//         cout<<"Addition not possible";
//         return;
//     }
    
//     int i=0, j=0, k=0;
//     Element *sum = new Element[num + s.num];
    
//     while(i<num && j<s.num)
//     {
//         if(ele[i].i == s.ele[i].j && ele[i].j == s.ele[i].j)
//         {
//             int value = ele[i].x + s.ele[j].x;
            
//             if(value!=0)
//             {
//                 sum[k].i = ele[i].i;
//                 sum[k].j = ele[i].j;
//                 sum[k].x = value;
//                 k++;
//             }
//             i++;
//             j++;
//         }
        
//         else if(ele[i].i < s.ele[j].i || (ele[i].i == s.ele[j].i && ele[i].j < s.ele[j].j))
//         {
//             sum[k] = ele[i];
//             i++;
//             k++;
//         }
//         else
//         {
//             sum[k] = s.ele[j];
//             k++;
//             j++;
//         }
//     }
    
//     // Copy any remaining elements from s1 (you were missing this loop!)
//     while (i < num) {
//         sum[k++] = ele[i++];
//     }
    
//     // Copy any remaining elements from s2
//     while (j < s.num) {
//         sum[k++] = s.ele[j++];
//     }
    
//     cout<< "Result of addition"<<endl;
//     cout << "Row\tColumn\tValue\n";

//     for(int p = 0; p < k; p++)
//     {
//         cout << sum[p].i << "\t"
//              << sum[p].j << "\t"
//              << sum[p].x << endl;
//     }

//     cout << "Total non-zero elements: " << k;

//     sum.num = k; // Update exact count of non-zero elements
//     return sum;
// }

// int main()
// {
//     Sparse s1(4, 4, 3);
    
//     int s2_values[4][4] = {
//         {0, 1, 5},
//         {1, 2, 8},
//         {3, 0, 10}
//     };

//     // Initialize s2 with static values
//     Sparse s2(4, 4, 3, s2_values);
    
//     cout << "\nMatrix 1:\n";
//     s1.display();

//     cout << "\nMatrix 2:\n";
//     s2.display();

//     Sparse s3 = s1.add(s2);
//     cout << "\nResult Matrix (s1 + s2):\n";
//     s3.display();
    

//     return 0;
// }


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
        int num;      // Number of non-zero elements
        Element *ele; // Pointer to element array
        
    public:
        Sparse(int m, int n, int num)
        {
            this->m = m;
            this->n = n;
            this->num = num;
            ele = new Element[num];
        }
        
        Sparse(int m, int n, int num, int staticData[][3])
        {
            this->m = m;
            this->n = n;
            this->num = num;
            ele = new Element[this->num];
        
            for (int i = 0; i < num; i++) {
                ele[i].i = staticData[i][0]; // row
                ele[i].j = staticData[i][1]; // col
                ele[i].x = staticData[i][2]; // value
            }
        }

        // Copy constructor (prevents crash when returning Sparse from add)
        Sparse(const Sparse &s)
        {
            m = s.m;
            n = s.n;
            num = s.num;
            ele = new Element[num];
            for (int i = 0; i < num; i++) {
                ele[i] = s.ele[i];
            }
        }
        
        void read();
        void display();
        Sparse add(Sparse &s); // Now returns a Sparse object
            
        ~Sparse()
        {
            delete[] ele;
        }
};

void Sparse::read()    
{
    cout << "Enter the coordinates and non-zero elements:\n";
    for (int i = 0; i < num; i++)
    {
        cin >> ele[i].i >> ele[i].j >> ele[i].x;
    }
}

void Sparse::display()
{
    int c = 0;
    for (int k = 0; k < m; k++)
    {
        for (int l = 0; l < n; l++)
        {
            if (c < num && ele[c].i == k && ele[c].j == l)
                cout << ele[c++].x << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

Sparse Sparse::add(Sparse &s)
{
    if (m != s.m || n != s.n)
    {
        cout << "Addition not possible\n";
        return Sparse(0, 0, 0);
    }
    
    int i = 0, j = 0, k = 0;
    Sparse sum(m, n, num + s.num); // Create result Sparse object
    
    while (i < num && j < s.num)
    {
        if (ele[i].i == s.ele[j].i && ele[i].j == s.ele[j].j)
        {
            int value = ele[i].x + s.ele[j].x;
            if (value != 0)
            {
                sum.ele[k].i = ele[i].i;
                sum.ele[k].j = ele[i].j;
                sum.ele[k].x = value;
                k++;
            }
            i++;
            j++;
        }
        else if (ele[i].i < s.ele[j].i || (ele[i].i == s.ele[j].i && ele[i].j < s.ele[j].j))
        {
            sum.ele[k++] = ele[i++];
        }
        else
        {
            sum.ele[k++] = s.ele[j++];
        }
    }
    
    while (i < num) {
        sum.ele[k++] = ele[i++];
    }
    
    while (j < s.num) {
        sum.ele[k++] = s.ele[j++];
    }
    
    sum.num = k; // Update exact count of non-zero elements
    return sum;
}

int main()
{
    Sparse s1(4, 4, 3);
    
    int s2_values[3][3] = {
        {0, 1, 5},
        {1, 2, 8},
        {3, 0, 10}
    };

    Sparse s2(4, 4, 3, s2_values);
    
    s1.read();

    cout << "\nMatrix 1:\n";
    s1.display();

    cout << "\nMatrix 2:\n";
    s2.display();

    Sparse s3 = s1.add(s2);
    cout << "\nResult Matrix (s1 + s2):\n";
    s3.display();

    return 0;
}