#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cmath>
#include "3lab_table.h"

using namespace std;

double f1(double x, int n) {
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

double f2(double x, int n) {
    return sin(x) * n;
}

int main() {
    double start, end, step;
    int n;

    printf("Vvedit start, end, step: ");
    scanf("%lf %lf %lf", &start, &end, &step);

    printf("Vvedit n: ");
    scanf("%d", &n);

    printf("\nTablytsia dlya indyvidualnoyi funktsiyi:\n");
    printTable(start, end, step, n, f1);

    printf("\nTablytsia dlya funktsiyi sin(x) * n:\n");
    printTable(start, end, step, n, f2);

    return 0;
}