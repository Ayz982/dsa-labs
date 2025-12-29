#include <iostream>
#include <vector>
#include <random>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

int randomNum(int min, int max) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<int> distr(min, max);

    return distr(gen);
}

template <typename T>
int binarySearch(const T& container, int target) {
    int index = -1;
    int L = 0;
    int R = static_cast<int>(size(container)) - 1;
    while (L <= R) {
        index = L + (R - L) / 2;
        if (target == container[index]) {
            break;
        }
        else {
            if (target > container[index]) {
                L = index + 1;
            }
            else {
                R = index - 1;
            }
        }
    }
    if (L <= R || target == container[index]) {
        return index;
    }
    return -1;
}

int main()
{
    ifstream fileTest("test.txt");
    if (!fileTest.is_open()) {
        cerr << "Error opening file test.txt!\n";
        return 1;
    }

    int numTests;
    fileTest >> numTests;
    for (int t = 0; t < numTests; t++) {
        int target, rows, cols;
        fileTest >> target >> rows >> cols;
        vector<vector<int>> matrix(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                fileTest >> matrix.at(i).at(j);
            }
        }
        cout << "--- Test #" << t + 1 << " (Target: " << target << ") ---\n";
        for (int i = 0; i < rows; i++) {
            int res = binarySearch(matrix.at(i), target);
            cout << "Row " << i << ": " << (res != -1 ? to_string(res) : "Not found") << "\n";
        }
    }

    return 0;
}