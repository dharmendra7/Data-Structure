#include <iostream>
using namespace std;

class LowerTriangular {
    private: 
        int n;
        int* A;
    public:
        LowerTriangular(int n) {
            this->n = n;
            A = new int[n * (n - 1) / 2];
        };

        void set(int i, int j, int x) {
            if (i >= j) {
                A[i * (i - 1) / 2 + j - 1] = x;
            }
        };

        int get(int i, int j) {
            if (i >= j) {
                return A[i * (i - 1) / 2 + j - 1];
            } else {
                return 0;
            }
        };

        void display() {
            for (int i = 1; i <= n; i++){
                for (int j = 1; j <= n; j++) {
                    if (i >= j) {
                        cout << A[i * (i - 1) / 2 + j - 1] << " ";
                    } else {
                        cout << "0 ";
                    }
                }
                cout << endl;
            }
        }

        ~LowerTriangular() {
            delete[] A;
        };
};

int main() {

    int n;
    cout << "Lower Triangular Matrix:" << endl;
    cout << "Enter the dimension of the matrix: ";
    cin >> n;

    LowerTriangular d(n);

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 1; i <=n ; i++){
        for (int j = 1; j <= n; j++) {
                int x;
                cin >> x;
                d.set(i, j, x);
            }
    }
    
    d.display();

    return 0;
}