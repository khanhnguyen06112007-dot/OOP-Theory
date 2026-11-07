#include <iostream>
#include "Monomial.h"

using namespace std;

int main() {
    Monomial m1(3, 2);  
    Monomial m2(4, 2);  
    Monomial m3(0, 0);  
    std::cout << "Enter Monomial m3: ";
    std::cin >> m3;

    cout << "m1 = " << m1 << "\n";
    cout << "m2 = " << m2 << "\n";
    cout << "m3 = " << m3 << "\n\n";

    cout << "m1 + m2 = " << (m1 + m2) << " (Cung so mu)\n";
    cout << "m1 * m3 = " << (m1 * m3) << "\n\n";

    cout << "m3 > m1: " << (m3 > m1) << "\n";
    cout << "m1 == m2: " << (m1 == m2) << "\n\n";

    m1 += m2;
    cout << "m1 += m2 -> m1 = " << m1 << "\n";
    
    m1 *= Monomial(2, 1);
    cout << "m1 *= 2x^1 -> m1 = " << m1 << "\n\n";

    m1++;
    cout << "m1++ (tang so mu) -> m1 = " << m1 << "\n";

    Monomial m4 = !m1;
    cout << "Dao ham cua m1 (!m1) = " << m4 << "\n";

    return 0;
}