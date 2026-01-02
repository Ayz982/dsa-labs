#include <iostream>
#include <cmath>

using namespace std;

double sumOnRecurrentDescent(int current, int n, double a_prev, double sum) {
    if (current > n)
        return sum;

    double a_curr = cos(a_prev) * sqrt(current) / 5.0;
    sum += a_curr;

    return sumOnRecurrentDescent(current + 1, n, a_curr, sum);
}

struct Result {
    double a;
    double sum;
};
Result sumOnRecurrentReturn(int n) {
    if (n == 0)
        return { 0.0, 0.0 };

    Result prev = sumOnRecurrentReturn(n - 1);

    double a_curr = cos(prev.a) * sqrt(n) / 5.0;
    double sum_curr = prev.sum + a_curr;

    return { a_curr, sum_curr };
}

double mixedRecursiveSum(int current, int n, double a_prev) {
    if (current > n)
        return 0.0;

    double a_curr = cos(a_prev) * sqrt(current) / 5.0;
    double rest = mixedRecursiveSum(current + 1, n, a_curr);

    return a_curr + rest;
}

int main()
{
    cout << "sumOnRecurrentDescent: " << sumOnRecurrentDescent(1, 5, 0, 0) << "\n";
    Result res = sumOnRecurrentReturn(5);
    cout << "sumOnRecurrentReturn: " << res.sum << "\n";
    cout << "mixedRecursiveSum: " << mixedRecursiveSum(1, 5, 0) << "\n";
    return 0;
}