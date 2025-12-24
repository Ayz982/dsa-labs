#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

using namespace std;

double randomNum(double min, double max) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_real_distribution<double> distr(min, max);
    return distr(gen);
}

template <typename T>
void printElementVector(const T& container) {
    for (const auto& element : container) {
        cout << fixed << setprecision(3) << element << " | ";
    }
    cout << "\n";
}

int main()
{
    int a, b, n;
    cout << "Enter a, b, n: ";
    cin >> a >> b >> n;

    // 1. Array Y -> eneration of random real numbers
    vector<double> vectorY(n);
    for (int i = 0; i < n; i++) {
        vectorY.at(i) = randomNum(-100.0, 100.0);
    }
    cout << "Vector Y:\n";
    printElementVector(vectorY);

    /* 2. Array Z -> f :
    * zi = { yi - 10a,  yi \in [11, 33]
    * { yi + 5b,  yi \notin [11, 33]
    */
    vector<double> vectorZ(n);
    for (int i = 0; i < n; i++) {
        if (vectorY.at(i) >= 11 && vectorY.at(i) <= 33) {
            vectorZ.at(i) = vectorY.at(i) - 10 * a;
        }
        else {
            vectorZ.at(i) = vectorY.at(i) + 5 * b;
        }
    }
    cout << "Vector Z:\n";
    printElementVector(vectorZ);

    // 3. R -> g : min((-1) ^ i * a * zi))
    double resultingR = 0.0;
    cout << "Intermediate values:\n";
    cout << fixed << setprecision(3);
    for (int i = 0; i < n; i++) {
        double sign = ((i + 1) % 2 == 0) ? 1.0 : -1.0;
        double currentValue = sign * a * vectorZ.at(i);

        cout << currentValue << " | ";

        if (i == 0 || currentValue < resultingR) {
            resultingR = currentValue;
        }
    }
    cout << "\nResulting R = " << resultingR << "\n";
    return 0;
}