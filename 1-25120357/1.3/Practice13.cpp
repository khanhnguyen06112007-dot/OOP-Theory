#include <iostream>
#include <stdexcept>
using namespace std;
const int MAX_SIZE = 100;
//================================//
template <typename T>
bool isLess(T a, T b){
    return a < b;
}

template <typename T>
bool isGreater(T a, T b){
    return a > b;
}

template <typename T>
bool EvenBeforeOdd(T a, T b){
    if (a % 2 == 0){
        return true;
    }
    else if (b % 2 == 0){
        return false;
    }
    else{
        return a < b;
    }
}

template <typename T>
bool OddBeforeEven(T a, T b){
    if (a % 2 != 0){
        return true;
    }
    else if (b % 2 != 0){
        return false;
    }
    else{
        return a < b;
    }
}

template <typename T>
void sort(T *arr, int size, bool (*compare)(T, T)){
    for (int i = 0; i < size; i++){
        for (int j = i + 1; j < size; j++){
            if (compare(arr[j], arr[i])){
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
//================================//
int inputSizeArray(){
    int size;
    std::cin >> size;
    if (size <= 0 || size > MAX_SIZE){
        throw std::out_of_range("Size must be between 1 and 100");
    }
    return size;
}
int main(){
    std::cout << "Initalize an array of integers: \n";
    std::cout << "Enter the size of the array: ";

    int size;
    try {
        size = inputSizeArray();
    } catch (const std::out_of_range& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }

    // Can swap between int, double to check the sorting function
    int *arr = new int [size];
    std::cout << "Enter the elements of the array: \n";
    for (int i = 0; i < size; i++){
        std::cin >> arr[i];
    }

    cout << "==============MENU==========================\n";
    cout << "||1. Sort in ascending order              ||\n";
    cout << "||2. Sort in descending order             ||\n";
    cout << "||3. Sort even numbers before odd numbers ||\n";
    cout << "||4. Sort odd numbers before even numbers ||\n";
    cout << "============================================\n";

    int choice;
    std::cout << "Enter your choice: ";
    do{
        std::cin >> choice;
        if (choice < 1 || choice > 4){
            std::cout << "Invalid choice. Please enter a number between 1 and 4: ";
        }
    }while(choice < 1 || choice > 4);

    switch (choice){
        case 1:
            sort(arr, size, isLess);
            break;
        case 2:
            sort(arr, size, isGreater);
            break;
        case 3:
            sort(arr, size, EvenBeforeOdd);
            break;
        case 4:
            sort(arr, size, OddBeforeEven);
            break;
    }

    std::cout << "Sorted array: \n";
    for (int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}