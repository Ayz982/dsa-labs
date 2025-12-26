#include <iostream>
#include <vector>
#include <iterator>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

template <typename T>
void printElement(const T& matrix, int rows, int cols, int delayMs) {
    gotoxy(cols, rows);
    cout << matrix.at(rows).at(cols);
    cout.flush();
    Sleep(delayMs);
}

template <typename T>
void visualizeTraversalSpiral(const T& matrix, int delayMs) {
    int n = size(matrix);
    for (int p = 0; p <= (n + 1) / 2; p++) {
        //bottom
        for (int j = n - p - 1; j >= p; j--) {
            printElement(matrix, n - p - 1, j, delayMs);
        }
        //left
        for (int i = n - p - 2; i >= p; i--) {
            printElement(matrix, i, p, delayMs);
        }
        //top
        if (n - 1 - p > p) {
            for (int j = p + 1; j <= n - 1 - p; j++) {
                printElement(matrix, p, j, delayMs);
            }
        }
        //right
        if (n - 1 - p > p) {
            for (int i = p + 1; i <= n - 2 - p; i++) {
                printElement(matrix, i, n - 1 - p, delayMs);
            }
        }
    }
    gotoxy(0, n + 1);
}

template <typename T>
void fillMatrix(T& matrix) {
    int n = size(matrix);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix.at(i).at(j) = '*';
        }
    }
}


int main()
{
    int n;
    cin >> n;
    vector<vector <char>> matrix(n, vector<char> (n, 0));
    fillMatrix(matrix);
    visualizeTraversalSpiral(matrix, 500);

    return 0;
}
