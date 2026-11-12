#include <iostream>
#include <exception>
#include "Matrix.h"


int main()
{
    try {
        Matrix<int> m1(4, 6); 
        
        std::cout << "Nhap ma tran (24 phan tu):\n";
        std::cin >> m1;

        Matrix<int> m2 = m1;
        int max = m2.findMax();
        m2[2][3] = max; 
        
        std::cout << "\nMa tran m2 sau khi cap nhat:\n";
        std::cout << m2;
        
    } catch (const std::exception& e) {
        std::cout << "\nDa xay ra ngoai le: " << e.what() << "\n";
    }
    
    return 0;
}