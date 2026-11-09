#include <iostream>
#include <vector>
#include <algorithm>
#include "function.h"

int main() {
    int N = 10;
    std::vector<int> a = EvenIndex(N);
    for (int i = 0; i < N; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    std::vector <int> b = OddIndex(N);
    for (int i = 0; i < N; ++i) {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;

    std::vector <int> c = GeneratePrime(N);
    for (int i = 0; i < N; ++i) {
        std::cout << c[i] << " ";
    }

    return 0;
}
