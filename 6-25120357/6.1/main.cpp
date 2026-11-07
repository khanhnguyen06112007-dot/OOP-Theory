#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> EvenIndex(int N) {
    if (N <= 0) return {};
    std::vector<int> result(N, 0);
    int maxRand = (N + 1) / 2;
    int index = 0;

    std::generate(result.begin(), result.end(), [&index, maxRand]() {
        if (index++ % 2 == 0) {
            return rand() % (maxRand + 1); 
        }
        return 0; 
    });
    return result;
}

int main() {
    int N = 10;
    std::vector<int> a = EvenIndex(N);
    for (int i = 0; i < N; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
