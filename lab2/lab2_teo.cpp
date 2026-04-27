#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

double calc(double x, int n) {
    if (x < 0) {
        double s = 0;
        for (int i = 1; i <= n; i++) {
            double p = 1;
            for (int j = 1; j <= n; j++) {
                p *= 1.0 / (x - i - j);
            }
            s += p;
        }
        return s;
    } else {
        double p = 1;
        for (int i = 0; i <= n; i++) {
            p *= (-x - i);
        }
        return p;
    }
}

int main() {
    ifstream fin("in.txt");
    if (!fin.is_open()) {
        printf("Pomylka vidkryttya in.txt\n");
        return 1;
    }
    
    int r, c, n;
    fin >> r >> c;
    
    printf("Vvedit n: ");
    scanf("%d", &n);
    
    double** a = new double*[r];
    double** b = new double*[r];
    
    for (int i = 0; i < r; i++) {
        a[i] = new double[c];
        b[i] = new double[c];
        
        double* rowA = a[i];
        for (int j = 0; j < c; j++) {
            fin >> *(rowA + j);
        }
    }
    fin.close();
    
    ofstream fout("out.txt");
    printf("Rezultat:\n");
    
    for (int i = 0; i < r; i++) {
        double* rowA = a[i];
        double* rowB = b[i];
        
        for (int j = 0; j < c; j++) {
            *(rowB + j) = calc(*(rowA + j), n);
            printf("%10.2f ", *(rowB + j));
            fout << *(rowB + j) << " ";
        }
        printf("\n");
        fout << "\n";
    }
    fout.close();
    
    for (int i = 0; i < r; i++) {
        delete[] a[i];
        delete[] b[i];
    }
    delete[] a;
    delete[] b;
    
    return 0;
}