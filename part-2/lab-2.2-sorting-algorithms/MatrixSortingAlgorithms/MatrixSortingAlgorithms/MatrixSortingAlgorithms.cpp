#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

template <typename T>
void insertionSortLinearLeft(vector<T>& row) {
    int n = static_cast<int>(row.size());
    for (int i = 1; i < n; i++) {
        auto B = row.at(i);
        int j = 0;
        while (B > row.at(j)) {
            j = j + 1;
        }
        for (int k = i - 1; k >= j; k--) {
            row.at(k + 1) = row.at(k);
        }
        row.at(j) = B;
    }
}

template <typename T>
void insertionSortLinearRight(vector<T>& row) {
    int n = static_cast<int>(row.size());
    for (int i = 1; i < n; i++) {
        auto B = row.at(i);
        int j = i;
        while (j > 0 && B < row.at(j - 1)) {
            row.at(j) = row.at(j - 1);
            j = j - 1;
        }
        row.at(j) = B;
    }
}

template <typename T>
void insertionSortWithSentinel(vector<T>& row) {
    int n = static_cast<int>(row.size());
    for (int i = 2; i < n; i++) {
        row.at(0) = row.at(i);
        int j = i;
        while (row.at(0) < row.at(j - 1)) {
            row.at(j) = row.at(j - 1);
            j = j - 1;
        }
        row.at(j) = row.at(0);
    }
}

template <typename T>
void insertionSortBinarySearch(vector<T>& row) {
    int n = static_cast<int>(row.size());
    for (int i = 1; i < n; i++) {
        auto B = row.at(i);
        int L = 0, R = i;
        while (L < R) {
            int j = (L + R) / 2;
            if (B >= row.at(j)) {
                L = j + 1;
            }
            else {
                R = j;
            }
        }
        for (int k = i - 1; k >= R; k--) {
            row.at(k + 1) = row.at(k);
        }
        row.at(R) = B;
    }
}

template <typename T>
void selectionSortValueAndIndex(vector<T>& row) {
    int n = static_cast<int>(row.size());
    for (int s = 0; s < n - 1; s++) {
        auto min = row.at(s);
        int indexMin = s;
        for (int i = s + 1; i < n; i++) {
            if (row.at(i) < min) {
                min = row.at(i);
                indexMin = i;
            }
        }
        row.at(indexMin) = row.at(s);
        row.at(s) = min;
    }
}

template <typename T>
void selectionSortOnlyIndex(vector<T>& row) {
    int n = static_cast<int>(row.size());
    for (int s = 0; s < n - 1; s++) {
        int indexMin = s;
        for (int i = s + 1; i < n; i++) {
            if (row.at(i) < row.at(indexMin)) {
                indexMin = i;
            }
        }
        auto B = row.at(indexMin);
        row.at(indexMin) = row.at(s);
        row.at(s) = B;
    }
}

template <typename T>
void selectionSortValueAndIndexOptimized(vector<T>& row) {
    int n = static_cast<int>(row.size());
    for (int s = 0; s < n - 1; s++) {
        auto min = row.at(s);
        int indexMin = s;
        for (int i = s + 1; i < n; i++) {
            if (row.at(i) < min) {
                min = row.at(i);
                indexMin = i;
            }
        }
        if (s != indexMin) {
            row.at(indexMin) = row.at(s);
            row.at(s) = min;
        }
    }
}

template <typename T>
void selectionSortOnlyIndexOptimized(vector<T>& row) {
    int n = static_cast<int>(row.size());
    for (int s = 0; s < n - 1; s++) {
        int indexMin = s;
        for (int i = s + 1; i < n; i++) {
            if (row.at(i) < row.at(indexMin)) {
                indexMin = i;
            }
        }
        if (s != indexMin) {
            auto B = row.at(indexMin);
            row.at(indexMin) = row.at(s);
            row.at(s) = B;
        }
    }
}

template <typename T>
void bubbleSortBasic(vector<T>& row) {
    int n = static_cast<int>(row.size());
    for (int R = n - 1; R > 0; R--) {
        for (int i = 0; i < R; i++) {
            if (row.at(i) > row.at(i + 1)) {
                auto B = row.at(i);
                row.at(i) = row.at(i + 1);
                row.at(i + 1) = B;
            }
        }
    }
}

template <typename T>
void bubbleSortWithFlag(vector<T>& row) {
    int n = static_cast<int>(row.size());
    int R = n - 1;
    bool f = true;
    while (f == true) {
        f = false;
        for (int i = 0; i < R; i++) {
            if (row.at(i) > row.at(i + 1)) {
                auto B = row.at(i);
                row.at(i) = row.at(i + 1);
                row.at(i + 1) = B;
                f = true;
            }
        }
        R = R - 1;
    }
}

template <typename T>
void bubbleSortLastSwap(vector<T>& row) {
    int n = static_cast<int>(row.size());
    int R = n - 1;
    while (R > 0) {
        int k = 0;
        for (int i = 0; i < R; i++) {
            if (row.at(i) > row.at(i + 1)) {
                auto B = row.at(i);
                row.at(i) = row.at(i + 1);
                row.at(i + 1) = B;
                k = i;
            }
        }
        R = k;
    }
}

template <typename T>
void shakerSort(vector<T>& row) {
    int n = static_cast<int>(row.size());
    int L = 0, R = n - 1, k = 0;
    while (L < R) {
        for (int i = L; i < R; i++) {
            if (row.at(i) > row.at(i + 1)) {
                auto B = row.at(i);
                row.at(i) = row.at(i + 1);
                row.at(i + 1) = B;
                k = i;
            }
        }
        R = k;

        for (int i = R - 1; i >= L; i--) {
            if (row.at(i) > row.at(i + 1)) {
                auto B = row.at(i);
                row.at(i) = row.at(i + 1);
                row.at(i + 1) = B;
                k = i;
            }
        }
        L = k + 1;
    }
}

template <typename T>
void shellSort(vector<T>& row) {
    int n = static_cast<int>(row.size());
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            T temp = row[i];
            int j;
            for (j = i; j >= gap && row[j - gap] > temp; j -= gap) {
                row[j] = row[j - gap];
            }
            row[j] = temp;
        }
    }
}

template <typename T>
void printElement(vector<T>& row) {
    for (const auto& num : row) {
        cout << num << " ";
    }
    cout << "\n";
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
        int rows, cols;
        fileTest >> rows >> cols;
        vector<vector<int>> matrix(rows, vector<int>(cols));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                fileTest >> matrix.at(i).at(j);
            }
        }

        cout << "\n========================================\n";
        cout << "  TEST CASE #" << t + 1 << " [" << rows << "x" << cols << "]" << endl;
        cout << "========================================\n";

        for (int i = 0; i < rows; i++) {
            cout << "Row " << i << ":" << endl;
            cout << "  " << left << setw(8) << "Before:";
            for (int val : matrix.at(i)) cout << setw(5) << val;
            cout << endl;
            shakerSort(matrix.at(i));
            cout << "  " << left << setw(8) << "After:";
            for (int val : matrix.at(i)) cout << setw(5) << val;
            cout << "\n" << string(cols * 5 + 10, '-') << endl;
        }
    }
    return 0;
}
