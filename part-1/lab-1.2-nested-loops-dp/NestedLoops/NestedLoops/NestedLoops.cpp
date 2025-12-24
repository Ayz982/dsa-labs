#include <iostream>
#include <cmath>

using namespace std;
/*
 * n                4^i - i
 * S = SUM  -----------------------
 * i=1        i
 *            PROD ( j + cos(j) )
 *            j=1
 */
double calculateSeriesSum(int n) {
    double S = 0.0;
    for (int i = 1; i <= n; i++) {
        double P = 1;
        for (int j = 1; j <= i; j++) {
            P *= j + cos(j);
        }
        S += (pow(4, i) - i) / P;
    }
    return S;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    if (n <= 0) {
        cerr << "Error: Invalid input. Please enter a positive integer.\n";
        return 1;
    }
    double result = calculateSeriesSum(n);
    cout << "S = " << result << "\n";
    return 0;
}