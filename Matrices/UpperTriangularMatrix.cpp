#include <iostream>
using namespace std;

class UpperTriangular {
    private: 
        int n;
        int* A;
    public:
        UpperTriangular(int n) {
            this->n = n;
            A = new int[n * (n - 1) / 2];
        };

        void set(int i, int j, int x) {
            if (i <= j) {
                A[n * (n + 1) / 2 - (n - i) * ((n - i) + 1) / 2 + j - i] = x;
            }
        };

        int get(int i, int j) {
            if (i <= j) {
                return A[n * (n + 1) / 2 - (n - i) * ((n - i) + 1) / 2 + j - i];
            } else {
                return 0;
            }
        };

        void display() {
            for (int i = 1; i <= n; i++){
                for (int j = 1; j <= n; j++) {
                    if (i <= j) {
                        cout << A[n * (n + 1) / 2 - (n - i) * ((n - i) + 1) / 2 + j - i] << " ";
                    } else {
                        cout << "0 ";
                    }
                }
                cout << endl;
            }
        }

        ~UpperTriangular() {
            delete[] A;
        };
};

int main() {

    int n;
    cout << "Upper Triangular Matrix:" << endl;
    cout << "Enter the dimension of the matrix: ";
    cin >> n;

    UpperTriangular d(n);

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