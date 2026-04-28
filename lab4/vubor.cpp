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
        int k = i;
        int x = a[i];
        for (int j = i + 1; j < SIZE; j++) {
            if (a[j] < x) {
                k = j;
                x = a[j];
            }
        }
        a[k] = a[i];
        a[i] = x;

        cout << i + 1 << "-y prohid: ";
        for (int m = 0; m < SIZE; m++) {
            if (m == i) cout << a[m] << "; ";
            else cout << a[m] << " ";
        }
        cout << "\n";
    }

    return 0;
}