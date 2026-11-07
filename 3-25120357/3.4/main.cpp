#include "Array.h"
#include <iostream>

int main(){ 
    Array<int>a;
    a.outputArray();

    Array<double>b(5);
    b.outputArray();

    int rawData[] = {5, 10, 15, 20};
    Array<int>c(rawData, 4);
    c.outputArray();

    Array<int>d(c);
    d.outputArray();
    

    return 0;
}