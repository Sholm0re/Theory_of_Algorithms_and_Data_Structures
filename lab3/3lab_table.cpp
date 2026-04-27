#include <iostream>
#include <cstdio>
#include "3lab_table.h"

using namespace std;

void printTable(double start, double end, double step, int n, FType f) {
    printf("----------------------\n");
    printf("|      X |         Y |\n");
    printf("----------------------\n");
    for (double x = start; x <= end; x += step) {
        printf("| %6.2f | %9.4f |\n", x, f(x, n));
    }
    printf("----------------------\n");
}