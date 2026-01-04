#include <iostream>
#include <random>
#include <type_traits>

using namespace std;

template <typename T>
T randomNum(T min, T max) {
    static random_device rd;
    static mt19937 gen(rd());

    if constexpr (is_floating_point_v<T>) {
        uniform_real_distribution<T> distr(min, max);
        return distr(gen);
    }
    else {
        uniform_int_distribution<T> distr(min, max);
        return distr(gen);
    }
}

template <typename T>
void fillRandomArray(void* ptr, int size, T min, T max) {
    if (!ptr) return;
    T* arr = static_cast<T*>(ptr);

    for (int i = 0; i < size; i++) {
        arr[i] = randomNum(min, max);
    }
}

template <typename T>
void inputArray(void* ptr, int size, const string& arrayName) {
    if (!ptr) return;

    T* arr = static_cast<T*>(ptr);

    for (int i = 0; i < size; i++) {
        cout << arrayName << "[" << i << "] = ";
        cin >> arr[i];
    }
    cout << "\n";
}

template <typename T>
void printArray(const void* ptr, int size, const string& message) {
    if (!ptr) {
        cout << "Array is empty (nullptr)!";
        return;
    }

    const T* arr = static_cast<const T*>(ptr);
    cout << message << ": [ ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << (i == size - 1 ? "" : ", ");
    }
    cout << " ]\n";
}

template <typename T>
T calculateProduct(void* ptr, int size, int M) {
    if (!ptr)
        return 0;

    T* arr = static_cast<T*>(ptr);

    T currentSum = 0;
    T currentProduct = 1;
    bool atLeastOne = false;

    for (int i = 0; i < size; i++) {
        if (currentSum + arr[i] <= M) {
            currentSum += arr[i];
            currentProduct *= arr[i];
            atLeastOne = true;
        }
        else {
            break;
        }
    }

    return atLeastOne ? currentProduct : 0;
}

int main()
{
    int M = 35;

    int sizeA = 10;
    int sizeB = 12;
    int sizeC = 8;

    int* A = new int[sizeA];
    fillRandomArray(A, sizeA, 1, 100);
    printArray<int>(A, sizeA, "Array A");
    cout << "Product for array A (Sum limit " << M << "): " << calculateProduct<int>(A, sizeA, M) <<"\n\n";

    delete[] A;
    A = nullptr;

    int* B = new int[sizeB];
    fillRandomArray<int>(B, sizeB, 1, 100);
    printArray<int>(B, sizeB, "Array B");
    cout << "Product for array B (Sum limit " << M << "): " << calculateProduct<int>(B, sizeB, M) << "\n\n";

    delete[] B;
    B = nullptr;

    int* C = new int[sizeC];
    fillRandomArray(C, sizeC, 1, 100);
    printArray<int>(C, sizeC, "Array C");
    cout << "Product for array C (Sum limit " << M << "): " << calculateProduct<int>(C, sizeC, M) << "\n\n";

    delete[] C;
    C = nullptr;

    return 0;
}
