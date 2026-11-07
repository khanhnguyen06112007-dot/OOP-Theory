#include <iostream>
#include "Array.h"


int main() {
    int n;
    std::cout << "Nhap so luong phan tu mang: ";
    std::cin >> n;

    Array<int> arr1(n);
    std::cout << "Nhap cac phan tu cho arr1:\n";
    std::cin >> arr1;

    std::cout << "arr1 = " << arr1 << "\n\n";

    Array<int> arr2 = arr1;
    std::cout << "arr2 (sau khi arr2 = arr1) = " << arr2 << "\n\n";

    if (n > 0) {
        arr2[0] = 999; 
        std::cout << "Da thay doi arr2[0] = 999.\n";
        std::cout << "arr2 = " << arr2 << "\n";
        std::cout << "arr1 = " << arr1 << " (arr1 khong bi anh huong)\n\n";
    }

    int* ptr = (int*)arr1;
    if (n > 0) {
        std::cout << "Kiem tra con tro ptr sau khi ep kieu (int*)arr1:\n";
        std::cout << "Phan tu ptr[0] = " << ptr[0] << "\n";
    }

    return 0;
}