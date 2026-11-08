#include <iostream>
#include "function.h"

int main() {
    const std::string str = "A man, a plan, a canal: Panama";
    if (isPalindrome(str)) {
        std::cout << "The string is a palindrome." << std::endl;
    } else {
        std::cout << "The string is not a palindrome." << std::endl;
    }
    return 0;
}
