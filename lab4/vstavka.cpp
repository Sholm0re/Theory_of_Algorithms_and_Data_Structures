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

    for (int i = 1; i < SIZE; i++) {
        int x = a[i];
        int j = i - 1;
        while (j >= 0 && x < a[j]) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;

        cout << i << "-y prohid: ";
        for (int m = 0; m < SIZE; m++) {
            if (m == i) cout << a[m] << "; ";
            else cout << a[m] << " ";
        }
        cout << "\n";
    }

    return 0;
}