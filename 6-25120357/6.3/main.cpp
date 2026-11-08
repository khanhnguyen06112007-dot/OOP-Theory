#include "function.h"
#include <iostream>
int main(){
    std::string example = "   [[[the quick,,, brown fox ]]]  ";

    normalizeString(example);
    std::cout << example << std::endl;

    return 0;
}