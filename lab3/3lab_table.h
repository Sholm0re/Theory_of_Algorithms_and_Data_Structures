#ifndef TABLE_H
#define TABLE_H

typedef double (*FType)(double, int);

void printTable(double start, double end, double step, int n, FType f);

#endif