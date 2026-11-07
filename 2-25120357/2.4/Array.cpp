#include "Array.h"
#include <sstream>
#include <stdexcept>
#include <iostream>

void Array::input(){
    char line[100];
    do{
        std::cout << "Enter size of integer array: ";
        std::cin.getline(line, 100);
    }while(!(std::stringstream(line) >> size) || size <= 0);

    arr = new int[size];
    for (int i = 0; i < size; i++){
        do{
            std::cout << "Enter value of arr[" << i << "]: ";
            std::cin.getline(line, 100);  
        }while(!(std::stringstream(line) >> arr[i]));
    }
}

void Array::output() const{
    std::cout << "Size of Array: " << size << "\n";
    std::cout << "Elements in array is: \n";
    for (int i = 0; i < size; i++){
        std::cout << "arr[" << i << "] = " << arr[i] << "\n";
    }
}

int Array::getSize() const{
    return size;
}
void Array::setSize(int size){
    if (size <= 0){
        throw std::invalid_argument("Kich co mang bi am");
    }
    int *newArr = new int[size];
    if (this -> size < size){
        for (int i = 0; i < this -> size; i++){
            newArr[i] = arr[i];
        }
        for (int i = this -> size; i < size; i++){
            newArr[i] = 0;
        }
    }
    else{
        for (int i = 0; i < size; i++){
            newArr[i] = arr[i];
        }
    }
    delete[]arr;
    this -> size = size;
    arr = newArr;
}

int Array::getElement(int index) const{
    if (index < 0 || index >= size){
        throw std::out_of_range("Index nam ngoai pham vi mang");
    }
    return arr[index];
}
void Array::setElement(int index, int num){
    if (index < 0 || index >= size){
        throw std::out_of_range("Index nam ngoai pham bi mang");
    }
    arr[index] = num;
}

int Array::find(int num) const{
    for (int i = 0; i < size; i++){
        if (arr[i] == num){
            return i;
        }
    }
    return -1;
}

void Array::sort(bool Compare(int, int)){
    for (int i = 0; i < size; i++){
        int j = i;
        while(j > 0 && !Compare(arr[j - 1], arr[j])){
            j--;
        }
        std::swap(arr[i], arr[j]);
    }
}

void Array::Destroy(){
    delete []arr;
}