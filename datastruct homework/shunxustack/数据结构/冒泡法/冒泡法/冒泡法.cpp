#include <iostream>

void bubble_sort(int a[], int n) {
    bool change = true;
    for (int i = n - 1; i >= 1 && change; --i) {
        change = false;
        for (int j = 0; j < i; ++j) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                change = true;
            }
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

    bubble_sort(a, n);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}