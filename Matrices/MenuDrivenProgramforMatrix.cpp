#include <iostream>
using namespace std;

class Diagonal {
private:
    int *a, n;

public:
    Diagonal(int n) {
        this->n = n;

        // A diagonal matrix needs only n elements
        a = new int[n];
    }

    ~Diagonal() {
        delete[] a;
    }

    void create() {
        int x;

        cout << "Enter the matrix elements:\n";

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {

                cin >> x;

                if (i == j) {
                    a[i - 1] = x;
                }
            }
        }
    }

    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {

                if (i == j) {
                    cout << a[i - 1] << " ";
                }
                else {
                    cout << "0 ";
                }
            }

            cout << endl;
        }
    }
};

int main() {
    int n, choice;

    cout << "Enter the dimension: ";
    cin >> n;

    Diagonal d(n);

    do {
        cout << "\n\n===== MATRIX MENU =====\n";
        cout << "1. Create Matrix\n";
        cout << "2. Display Matrix\n";
        cout << "3. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            d.create();
            break;

        case 2:
            d.display();
            break;

        case 3:
            cout << "Exiting...";
            break;

        default:
            cout << "Invalid choice!";
        }

    } while (choice != 3);

    return 0;
}
