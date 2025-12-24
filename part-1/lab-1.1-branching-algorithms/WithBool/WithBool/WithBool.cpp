#include <iostream>
#include <fstream>
#include <optional>

using namespace std;

/*
 *
 * / 10*x^3 + 7*x/5 + 2 , if x in [-49, -10) U (0, 10]
 * y = <
 * \ -x + 9             , if x in (20, +inf)
 *
 */

optional <double> calculateVariantValue(int x) {
    double y;
    if ((x >= -49 && x < -10) || (x > 0 && x <= 10)) {
        // x º [-49, -10) U (0, 10]
        y = 10 * x * x * x + 7 * x / 5.0 + 2;
        return y;
    }
    else if (x > 20) {
        // x º(20, +inf)
        y = -x + 9;
        return y;
    }
    else {
        return nullopt;
    }

    return nullopt;
}

void printResult(int x, optional<double> y) {
    cout << "x = " << x << ", y = ";
    if (y.has_value()) cout << y.value();
    else cout << "[no value]";
    cout << "\n";
}

int main()
{
    int x;
    ifstream testFile("test.txt");
    if (!testFile.is_open()) {
        cout << "Error opening file test.txt!\n";
        return 1;
    }
    while (testFile >> x) {
        printResult(x, calculateVariantValue(x));
    }
    testFile.close();
    return 0;
}