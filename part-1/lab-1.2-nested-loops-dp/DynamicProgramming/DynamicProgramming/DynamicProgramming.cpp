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
    double S = 0.0, P = 1;
    for (int i = 1; i <= n; i++) {
        P *= i + cos(i);
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