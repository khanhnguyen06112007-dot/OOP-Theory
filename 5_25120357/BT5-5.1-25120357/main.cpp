#include <iostream>
#include "Polynomial.h"

int main() {
    try {
        Polynomial p1, p2;
        
        std::cout << "=== Nhap Da thuc P1 ===\n";
        std::cin >> p1;
        
        std::cout << "\n=== Nhap Da thuc P2 ===\n";
        std::cin >> p2;

        std::cout << "\n--- KET QUA KHOI TAO ---\n";
        std::cout << p1 << "\n";
        std::cout << p2 << "\n";

        std::cout << "\n--- PHEP TOAN SO HOC ---\n";
        std::cout << "P1 + P2 = " << (p1 + p2) << "\n";
        std::cout << "P1 - P2 = " << (p1 - p2) << "\n";
        std::cout << "P1 * P2 = " << (p1 * p2) << "\n";

        std::cout << "\n--- DAO HAM & NGUYEN HAM ---\n";
        std::cout << "Dao ham P1 (!P1)    = " << (!p1) << "\n";
        std::cout << "Nguyen ham P1 (~P1) = " << (~p1) << "\n";

        std::cout << "\n--- PHEP SO SANH ---\n";
        std::cout << "P1 == P2 : " << (p1 == p2 ? "True" : "False") << "\n";
        std::cout << "P1 != P2 : " << (p1 != p2 ? "True" : "False") << "\n";
        std::cout << "P1 >  P2 : " << (p1 > p2  ? "True" : "False") << "\n";
        std::cout << "P1 <  P2 : " << (p1 < p2  ? "True" : "False") << "\n";

    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
    return 0;
}