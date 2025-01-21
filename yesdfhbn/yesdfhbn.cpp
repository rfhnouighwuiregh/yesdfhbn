#include <iostream>
#include <cstdlib>
#include <limits>
#include <algorithm>

void findMinSumRecursive(int arr[], int n, int start, int& minSum, int& minPos) {
    if (start > n - 10) return;

    int currentSum = 0;
    for (int i = 0; i < 10; ++i) {
        currentSum += arr[start + i];
    }

    if (currentSum < minSum) {
        minSum = currentSum;
        minPos = start;
    }

    findMinSumRecursive(arr, n, start + 1, minSum, minPos);
}

int findMax(int arr[], int size) {
    return *std::max_element(arr, arr + size);
}

int findMax(int arr[][10], int rows) {
    int maxVal = arr[0][0];
    for (int i = 0; i < rows; ++i) {
        maxVal = std::max(maxVal, findMax(arr[i], 10));
    }
    return maxVal;
}

int findMax(int arr[][10][10], int dim1) {
    int maxVal = arr[0][0][0];
    for (int i = 0; i < dim1; ++i) {
        maxVal = std::max(maxVal, findMax(arr[i], 10));
    }
    return maxVal;
}

int findMax(int a, int b) {
    return (a > b) ? a : b;
}

int findMax(int a, int b, int c) {
    return std::max({ a, b, c });
}

int main() {
    setlocale(LC_ALL, "Russian");
    // ������� 4
    const int SIZE = 100;
    int arr[SIZE];

    std::srand(time(0));
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = std::rand() % 100;
    }

    int minSum = std::numeric_limits<int>::max();
    int minPos = -1;

    findMinSumRecursive(arr, SIZE, 0, minSum, minPos);
    std::cout << "Минимальная сумма: " << minSum << " начинается с позиции: " << minPos << std::endl;

    // Задание 5
    int oneDArray[5] = { 1, 3, 5, 0, 2 };
    std::cout << "Максимальное значение в одномерном массиве: " << findMax(oneDArray, 5) << std::endl;

    int twoDArray[3][10] = { {1, 5, 3, 2, 8, 6, 4, 0, 7, 9},
                            {3, 6, 2, 8, 1, 4, 5, 7, 0, 9},
                            {10, 15, 12, 20, 9, 4, 8, 3, 11, 14} };
    std::cout << "Максимальное значение в двумерном массиве: " << findMax(twoDArray, 3) << std::endl;

    int threeDArray[2][10][10] = { {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {11, 12, 13, 14, 15, 16, 17, 18, 19, 20}},
                                   {{21, 22, 23, 24, 25, 26, 27, 28, 29, 30}, {31, 32, 33, 34, 35, 36, 37, 38, 39, 40}} };
    std::cout << "Максимальное значение в трёхмерном массиве: " << findMax(threeDArray, 2) << std::endl;

    std::cout << "Максимальное значение между двумя числами (5, 10): " << findMax(5, 10) << std::endl;

    std::cout << "Максимальное значение между тремя числами (5, 10, 3): " << findMax(5, 10, 3) << std::endl;

    return 0;
}