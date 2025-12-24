#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace std;

template <typename T>
void printElementArray(const T& container) {
    for (const auto& num : container) {
        cout << num << " | ";
    }
    cout << "\n";
}

template <typename T>
void rearrangeSegments(T& container) {
    size_t totalSize = size(container);
    if (totalSize == 0 || totalSize % 4 != 0) {
        return;
    }
    size_t partSize = totalSize / 4;
    vector<typename T::value_type> temp(partSize);
    for (size_t i = 0; i < partSize; i++) {
        temp.at(i) = container.at(partSize + i);
        container.at(partSize + i) = container.at(3 * partSize + i);
        container.at(3 * partSize + i) = temp.at(i);
        temp.at(i) = container.at(2 * partSize + i);
        container.at(2 * partSize + i) = container.at(3 * partSize + i);
        container.at(3 * partSize + i) = temp.at(i);
    }
    reverse(container.begin(), container.begin() + partSize);
    reverse(container.begin() + 2 * partSize, container.begin() + 3 * partSize);
    reverse(container.begin() + 3 * partSize, container.begin() + 4 * partSize);
}

int main()
{
    ifstream testFile("test.txt");
    string line;
    if (!testFile.is_open()) {
        cerr << "Error opening file test.txt!\n";
        return 1;
    }
    while (getline(testFile, line)) {
        if (line.empty())
            continue;

        vector<int> currentArray;

        stringstream ss(line);
        int n;
        while (ss >> n) {
            currentArray.push_back(n);
        }
        cout << "Initial array:\n";
        printElementArray(currentArray);

        rearrangeSegments(currentArray);
        cout << "Final array:\n";
        printElementArray(currentArray);
        cout << "\n";
    }

    return 0;
}