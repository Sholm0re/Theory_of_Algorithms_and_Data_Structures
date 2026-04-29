#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// 1. Piramidalne
void downHeap(int a[], int k, int size) {
    int child;
    int tmp = a[k];
    while (k < size / 2) {
        child = 2 * k + 1;
        if ((child < size - 1) && (a[child] < a[child + 1])) { child++; }
        if (tmp >= a[child]) { break; }
        a[k] = a[child];
        k = child;
    }
    a[k] = tmp;
}

void heapSort(int a[], int N) {
    for (int i = N / 2 - 1; i >= 0; i--) downHeap(a, i, N);
    for (int i = N - 1; i > 0; i--) {
        int last = a[i];
        a[i] = a[0];
        a[0] = last;
        downHeap(a, 0, i);
    }
}

// QuickSort
void quickSort(int a[], long N) {
    long i = 0, j = N;
    int temp, p;
    p = a[N >> 1];
    do {
        while (a[i] < p) i++;
        while (a[j] > p) j--;
        if (i <= j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0) quickSort(a, j);
    if (N > i) quickSort(a + i, N - i);
}

// 3. Zlyttya mergesort
void merge(int a[], long left, long split, long right) {
    long pos1 = left;
    long pos2 = split + 1;
    long pos3 = 0;
    int* temp = new int[right - left + 1];

    while (pos1 <= split && pos2 <= right) {
        if (a[pos1] < a[pos2]) { temp[pos3] = a[pos1]; pos3++; pos1++; }
        else { temp[pos3] = a[pos2]; pos3++; pos2++; }
    }
    while (pos1 <= split) { temp[pos3] = a[pos1]; pos3++; pos1++; }
    while (pos2 <= right) { temp[pos3] = a[pos2]; pos3++; pos2++; }
    for (pos3 = 0; pos3 < right - left + 1; pos3++) {
        a[left + pos3] = temp[pos3];
    }
    delete[] temp;
}

void mergeSort(int a[], long left, long right) {
    long split;
    if (left < right) {
        split = (left + right) / 2;
        mergeSort(a, left, split);
        mergeSort(a, split + 1, right);
        merge(a, left, split, right);
    }
}

// Test
void copyArray(int src[], int dest[], int size) {
    for(int i = 0; i < size; i++) dest[i] = src[i];
}

void test(int size) {
    int* orig = new int[size];
    int* a = new int[size];
    for(int i = 0; i < size; i++) orig[i] = rand() % 81 - 40;

    unsigned int t1, t2;

    copyArray(orig, a, size);
    t1 = clock();
    heapSort(a, size);
    t2 = clock();
    cout << "Rozmir " << size << ". Piramidalne: " << t2 - t1 << " ms\n";

    copyArray(orig, a, size);
    t1 = clock();
    quickSort(a, size - 1);
    t2 = clock();
    cout << "Rozmir " << size << ". Shvydke: " << t2 - t1 << " ms\n";

    copyArray(orig, a, size);
    t1 = clock();
    mergeSort(a, 0, size - 1);
    t2 = clock();
    cout << "Rozmir " << size << ". Zlyttyam: " << t2 - t1 << " ms\n\n";

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