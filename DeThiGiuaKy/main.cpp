#include "Fraction.h"
#include "SmartPointer.h"
#include <iostream>

int main(){
    SmartPointer<Fraction>p1 = new Fraction(1, 3);
    SmartPointer<Fraction>p2 = new Fraction(2, 5);

    SmartPointer<Fraction>p3;
    if (!p3) p3 = p2;

    // Hàm count_ref ở đây trả về số lượng con trỏ share cùng vùng nhớ quản lý
    std::cout << p1.count_ref() << "\n";    // 1
    std::cout << p2.count_ref() << "\n";    // 2

    Fraction *f = p1 -> add(*p2);
    std::cout << *f << "\n";
    return 0;
}