#include <iostream>
#include <cstdlib>
#include <ctime>

#define SIZE 20

using namespace std;

int main() {
    srand(time(NULL));
    int a[SIZE];

    cout << "Vychidnyi masyv:\n";
    for (int i = 0; i < SIZE; i++) {
        a[i] = rand() % 81 - 40;
        cout << a[i] << " ";
    }
    cout << "\n\n";

    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = SIZE - 1; j > i; j--) {
            if (a[j] < a[j - 1]) {
                int x = a[j - 1];
                a[j - 1] = a[j];
                a[j] = x;
            }
        }

        cout << i + 1 << "-y prohid: ";
        for (int m = 0; m < SIZE; m++) {
            if (m == i) cout << a[m] << "; ";
            else cout << a[m] << " ";
        }
        cout << "\n";
    }

    return 0;
}