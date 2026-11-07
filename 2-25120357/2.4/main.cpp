#include "Array.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

bool asc(int a, int b){
    return a < b;
}

int main(){
    Array a;
    std::cout << "Nhap mang a: \n";
    a.input();

    std::cout << "Thong tin mang a: \n";
    a.output();

    int num;
    char line[100];
    do{
        std::cout << "Nhap gia tri can tim trong mang: ";
        std::cin.getline(line, 100);
    }while(!(std::stringstream(line) >> num));
    int res = a.find(num);
    if (res == -1){
        std::cout << "Gia tri num khong ton tai trong mang! \n";
    }
    else{
        std::cout << "Tim thay gia tri " << num << " tai vi tri " << res << "\n";
    }

    try{
        int index;

        char line[100];
        do{
            std::cout << "Nhap vi tri index: ";
            std::cin.getline(line, 100);
        }while(!(std::stringstream(line) >> index));

        std::cout << "Phan tu tai vi tri " << index << " la: " << a.getElement(index) << "\n";

        int num;

        do{
            std::cout << "Nhap gia tri can thay doi: ";
            std::cin.getline(line, 100);
        }while(!(std::stringstream(line) >> num));
        a.setElement(index, num);
        std::cout << "Mang a sau khi thay doi la: ";
        a.output();
    }catch(std::out_of_range &error){
        std::cout << "Error: " << error.what() << "\n";
    }

    std::cout << "Thuc hien sap xep mang: ";
    a.sort(asc);
    std::cout << "Mang a sau khi sap xep: ";
    a.output();

    try{
        std::cout << "Kich thuoc mang hien tai la: ";
        std::cout << a.getSize() << "\n";
        int size;

        char line[100];
        do{
            std::cout << "Nhap kich thuoc mang muon doi: ";
            std::cin.getline(line, 100);
        }while(!(std::stringstream(line) >> size));
        a.setSize(size);
        std::cout << "Mang a sau khi thay doi kich thuoc: ";
        a.output(); 
    }catch(std::invalid_argument &error){
        std::cout << "Error: " << error.what() << "\n";
    }
    a.Destroy();

    return 0;
}