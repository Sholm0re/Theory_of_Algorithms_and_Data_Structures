#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void selectSort(int a[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int k = i;
        int x = a[i];
        for (int j = i + 1; j < size; j++) {
            if (a[j] < x) {
                k = j;
                x = a[j];
            }
        }
        a[k] = a[i];
        a[i] = x;
    }
}

void insertSort(int a[], int size) {
    for (int i = 1; i < size; i++) {
        int x = a[i];
        int j = i - 1;
        while (j >= 0 && x < a[j]) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}

void bubbleSort(int a[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = size - 1; j > i; j--) {
            if (a[j] < a[j - 1]) {
                int x = a[j - 1];
                a[j - 1] = a[j];
                a[j] = x;
            }
        }
    }
}

void shakerSort(int a[], int size) {
    int lb = 1, ub = size - 1;
    int k = size - 1;
    int x;
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
    } while (lb < ub);
}

void copyArray(int src[], int dest[], int size) {
    for(int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}

void test(int size) {
    int* orig = new int[size];
    int* a = new int[size];
    for(int i = 0; i < size; i++) orig[i] = rand() % 1000;

    unsigned int t1, t2;

    copyArray(orig, a, size);
    t1 = clock();
    selectSort(a, size);
    t2 = clock();
    cout << "Rozmir " << size << ". Vybirkoyu: " << t2 - t1 << " ms\n";

    copyArray(orig, a, size);
    t1 = clock();
    bubbleSort(a, size);
    t2 = clock();
    cout << "Rozmir " << size << ". Bulbaskoyu: " << t2 - t1 << " ms\n";

    copyArray(orig, a, size);
    t1 = clock();
    shakerSort(a, size);
    t2 = clock();
    cout << "Rozmir " << size << ". Shakerom: " << t2 - t1 << " ms\n";

    copyArray(orig, a, size);
    t1 = clock();
    insertSort(a, size);
    t2 = clock();
    cout << "Rozmir " << size << ". Vstavkoyu: " << t2 - t1 << " ms\n\n";

    delete[] orig;
    delete[] a;
}

int main() {
    srand(time(0));
    test(200);
    test(2000);
    test(20000);
    return 0;
}