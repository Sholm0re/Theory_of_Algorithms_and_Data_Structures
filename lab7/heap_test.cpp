#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printArr(int a[], int size, const char* msg) {
    cout << msg << ": ";
    for(int i = 0; i < size; i++) cout << a[i] << " ";
    cout << "\n";
}

void downHeap(int a[], int k, int size) {
    int child;
    int tmp = a[k];
    while (k < size / 2) {
        child = 2 * k + 1;
        if ((child < size - 1) && (a[child] < a[child + 1])) {
            child++;
        }
        if (tmp >= a[child]) {
            break;
        }
        a[k] = a[child];
        k = child;
    }
    a[k] = tmp;
}

int main() {
    srand(time(0));
    int N = 10;
    int a[10];

    for(int i = 0; i < N; i++) {
        a[i] = rand() % 81 - 40;
    }

    printArr(a, N, "Vychidnyi masyv");

    cout << "\n--- Pobudova piramidy ---\n";
    for (int i = N / 2 - 1; i >= 0; i--) {
        downHeap(a, i, N);
        cout << "Krok pobudovy (i=" << i << "): ";
        for(int j = 0; j < N; j++) cout << a[j] << " ";
        cout << "\n";
    }

    cout << "\n--- Surtuvannya ---\n";
    for (int i = N - 1; i > 0; i--) {
        int last = a[i];
        a[i] = a[0];
        a[0] = last;
        downHeap(a, 0, i);
        cout << "Krok sortuvannya (i=" << i << "): ";
        for(int j = 0; j < N; j++) cout << a[j] << " ";
        cout << "\n";
    }

    printArr(a, N, "\nVidkalybrovanyi masyv");
    return 0;
}