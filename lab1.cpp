#include <iostream>
#include <cmath>

using namespace std;


double calculateVariant2(double x, int n) {
    double y = 0;

    if (x < 0) {
        
        double sum = 0;
        for (int i = 1; i <= n; i++) {
            double prod = 1;
            for (int j = 1; j <= n; j++) {
                prod *= 1.0 / (x - i - j);
            }
            sum += prod;
        }
        y = sum;
        cout << "Obchysleno dlya x < 0 (suma dobutkiv)" << endl;
    } else {
        
        double prod = 1;
        for (int i = 0; i <= n; i++) {
            prod *= (-x - i);
        }
        y = prod;
        cout << "Obchysleno dlya x >= 0 (dovhyi dobutok)" << endl;
    }
    return y;
}

int main() {
    double x;
    int n;

    cout << "Vvedit x: ";
    cin >> x;
    cout << "Vvedit n: ";
    cin >> n;

    double result = calculateVariant2(x, n);

    cout << "Rezultat y = " << result << endl;

    return 0;
}