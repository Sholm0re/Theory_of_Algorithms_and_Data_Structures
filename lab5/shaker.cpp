#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int a[10];
    
    cout << "Pochatkovyi masyv:\n";
    for (int i = 0; i < 10; i++) {
        a[i] = rand() % 81 - 40;
        cout << a[i] << " ";
    }
    cout << "\n\n";

    int lb = 1;
    int ub = 9;
    int k = 9;
    int x;
    int prohid = 1;

    do {
        for (int j = ub; j > 0; j--) {
            if (a[j - 1] > a[j]) {
                x = a[j - 1];
                a[j - 1] = a[j];
                a[j] = x;
                k = j;
            }
        }
        lb = k + 1;
        
        for (int j = 1; j <= ub; j++) {
            if (a[j - 1] > a[j]) {
                x = a[j - 1];
                a[j - 1] = a[j];
                a[j] = x;
                k = j;
            }
        }
        ub = k - 1;

        cout << prohid++ << "-y prohid: ";
        for (int i = 0; i < 10; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
        
    } while (lb < ub);

    return 0;
}