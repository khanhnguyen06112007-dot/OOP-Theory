#include <iostream>
#include "Vehicle.h"


int main() {
    std::cout << "=== KIEM TRA XE MAY ===" << "\n";
    MotorBike bike(5.0f, 20.0f); 
    std::cout << "Nhien lieu ban dau: " << bike.getFuel() << " lit" << "\n";

    bike.addWeight(10.0f);
    bike.addFuel(2.0f);   

    if (bike.run(100.0f)) {
        std::cout << "Xe may chay thanh cong 100 km." << "\n";
    } else {
        std::cout << "Xe may het nhien lieu!" << "\n";
    }
    std::cout << "Nhien lieu con lai: " << bike.getFuel() << " lit" << "\n\n";

    std::cout << "=== KIEM TRA XE TAI ===" << "\n";
    Truck truck(50.0f, 2000.0f); 
    std::cout << "Nhien lieu ban dau: " << truck.getFuel() << " lit" << "\n";

    truck.removeWeight(500.0f); 

    if (truck.run(100.0f)) {
        std::cout << "Xe tai chay thanh cong 100 km." << "\n";
    } else {
        std::cout << "Xe tai het nhien lieu!" << "\n";
    }
    std::cout << "Nhien lieu con lai: " << truck.getFuel() << " lit" << "\n";

    return 0;
}