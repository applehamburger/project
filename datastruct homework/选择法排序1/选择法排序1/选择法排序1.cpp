#include <iostream>

void SelectSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[k])
                k = j;
        }
        if (k != i) {
            int temp = a[k];
            a[k] = a[i];
            a[i] = temp;
        }
    }
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    int a[n];
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    SelectSort(a, n);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
