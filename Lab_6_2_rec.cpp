#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 20;

// Рекурсивне заповнення масиву випадковими числами
void fillArray(int a[], int n, int i = 0) {
    if (i == n)
        return;

    a[i] = rand() % 101 - 50; // Діапазон від -50 до 50
    fillArray(a, n, i + 1);
}

// Рекурсивне виведення масиву
void printArray(const int a[], int n, int i = 0) {
    if (i == n) {
        cout << '\n';
        return;
    }

    cout << setw(4) << a[i];
    printArray(a, n, i + 1);
}

// Рекурсивний пошук індексу мінімального елемента
int findMinIndex(const int a[], int n, int i = 1, int minIndex = 0) {
    if (i == n)
        return minIndex;

    if (a[i] < a[minIndex])
        minIndex = i;

    return findMinIndex(a, n, i + 1, minIndex);
}

// Рекурсивний пошук індексу максимального елемента
int findMaxIndex(const int a[], int n, int i = 1, int maxIndex = 0) {
    if (i == n)
        return maxIndex;

    if (a[i] > a[maxIndex])
        maxIndex = i;

    return findMaxIndex(a, n, i + 1, maxIndex);
}

// Заміна місцями мінімального та максимального елементів
void swapMinMax(int a[], int minIndex, int maxIndex) {
    int temp = a[minIndex];
    a[minIndex] = a[maxIndex];
    a[maxIndex] = temp;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int a[N];

    // Формування масиву
    fillArray(a, N);

    // Виведення початкового масиву
    cout << "Initial array:\n";
    printArray(a, N);

    // Пошук мінімального та максимального елементів
    int minIndex = findMinIndex(a, N);
    int maxIndex = findMaxIndex(a, N);

    cout << "\nMinimum element: " << a[minIndex]
        << ", index: " << minIndex << '\n';

    cout << "Maximum element: " << a[maxIndex]
        << ", index: " << maxIndex << '\n';

    // Заміна місцями мінімального та максимального елементів
    swapMinMax(a, minIndex, maxIndex);

    // Виведення модифікованого масиву
    cout << "\nModified array:\n";
    printArray(a, N);

    return 0;
}