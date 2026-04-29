#include <iostream>
#include <cstring>

using namespace std;

struct Pass {
    int code;
    char surname[30];
    int items;
    double weight;
};

void printArr(Pass arr[], int n) {
    cout << "--------------------------------------------------\n";
    cout << "Kod | Prizvyshche    | Rechey | Vaha\n";
    cout << "--------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i].code << " | ";
        int len = strlen(arr[i].surname);
        cout << arr[i].surname;
        for (int j = 0; j < 14 - len; j++) cout << " ";
        cout << "| " << arr[i].items << "      | " << arr[i].weight << "\n";
    }
    cout << "--------------------------------------------------\n\n";
}

int main() {
    int n = 10;
    // Normalni halytski prizvyshcha
    Pass orig[10] = {
        {105, "Halytskyi", 2, 15.5},
        {102, "Lozynskyi", 1, 5.0},
        {108, "Batiuk", 3, 20.0},
        {101, "Zalizniak", 2, 12.5},
        {109, "Bilas", 1, 8.0},
        {103, "Fedyna", 4, 25.5},
        {107, "Tsiupa", 2, 14.0},
        {104, "Hrytsak", 1, 7.5},
        {110, "Bandurka", 3, 18.0},
        {106, "Klym", 2, 10.0}
    };

    Pass work[10];

    while (true) {
        cout << "0 - Poperedniy poryadok\n";
        cout << "1 - Sortuvannya za kodom (Bulbashka)\n";
        cout << "2 - Sortuvannya za vahoyu (Vybir)\n";
        cout << "3 - Vyhid\n";
        cout << "Vybir: ";
        
        int ch;
        cin >> ch;

        if (ch == 3) break;

        for (int i = 0; i < n; i++) work[i] = orig[i];

        if (ch == 0) {
            printArr(work, n);
        } 
        else if (ch == 1) {
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                    if (work[j].code > work[j + 1].code) {
                        Pass t = work[j];
                        work[j] = work[j + 1];
                        work[j + 1] = t;
                    }
                }
            }
            printArr(work, n);
        } 
        else if (ch == 2) {
            for (int i = 0; i < n - 1; i++) {
                int k = i;
                for (int j = i + 1; j < n; j++) {
                    if (work[j].weight < work[k].weight) {
                        k = j;
                    }
                }
                Pass t = work[i];
                work[i] = work[k];
                work[k] = t;
            }
            printArr(work, n);
        }
    }

    return 0;
}