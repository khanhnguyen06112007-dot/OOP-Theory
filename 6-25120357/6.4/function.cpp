#include "function.h"
#include <fstream>
#include <iterator>
bool isPrime(int n){
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0) return false;
    }
    return true;
}
void filterPrimeNumbers(const std::string &inputFile, const std::string &outputFile){
    std::ifstream fin(inputFile);
    std::ofstream fout(outputFile);
    
    if (!fin.is_open() || !fout.is_open()) {
        throw std::runtime_error("Could not open input or output file.");
    }

    auto fin_begin = std::istream_iterator<int>(fin);
    auto fin_end = std::istream_iterator<int>();

    auto fout_begin = std::ostream_iterator<int>(fout, "\n");
    for (auto it = fin_begin; it != fin_end; ++it) {
        int number = *it;
        if (!isPrime(number)) {
            *fout_begin++ = number;
        }
    }
}