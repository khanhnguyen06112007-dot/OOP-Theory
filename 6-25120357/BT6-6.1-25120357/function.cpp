#include "function.h"
#include <algorithm>
#include <cstdlib>

std::vector<int> EvenIndex(int N){
    if (N <= 0) return {};
    std::vector<int> result(N);
    int maxRand = (N + 1)/2;
    int index = 0;
    std::generate(result.begin(), result.end(), [&index, maxRand](){
        if (index++ % 2 == 0){
            return 1 + rand() % maxRand;
        }
        else return 0;
    });
    return result;
}

std::vector<int> OddIndex(int N){
    if (N <= 0) return {};
    std::vector<int> result(N);
    int index = 0;
    std::generate(result.begin(), result.end(), [&index](){
        if (index++ % 2 == 1){
            return rand();
        }
        else return 0;
    });
    return result;
}

bool isPrime(int n){
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0) return false;
    }
    return true;
}
std::vector<int>GeneratePrime(int N){
    if (N <= 0) return {};
    std::vector<int> result(N);
    int cur = 2;
    std::generate(result.begin(), result.end(), [&cur](){
        while(!isPrime(cur)) cur++;
        return cur++;
    });
    return result;
}
