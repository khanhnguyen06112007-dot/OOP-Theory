#include "Vehicle.h"

Vehicle::Vehicle(float initialFuel, float initialWeight) {
    m_fuel = initialFuel;
    m_weight = (initialWeight > 0) ? initialWeight : 0.0f;
}

void Vehicle::addWeight(float weight) {
    if (weight > 0) {
        m_weight += weight;
    }
}

void Vehicle::removeWeight(float weight) {
    if (weight > 0) {
        m_weight -= weight;
        if (m_weight < 0) {
            m_weight = 0.0f;
        }
    }
}

void Vehicle::addFuel(float fuel) {
    if (fuel > 0) {
        m_fuel += fuel;
    }
}

float Vehicle::getFuel() const {
    return m_fuel;
}

MotorBike::MotorBike(float initialFuel, float initialWeight) 
    : Vehicle(initialFuel, initialWeight) {}

bool MotorBike::run(float km) {
    if (km <= 0) return true;
    float fuelPerKm = (2.0f / 100.0f) + (m_weight / 10.0f) * (0.1f / 100.0f);
    float totalFuelNeeded = km * fuelPerKm;

    if (totalFuelNeeded > m_fuel) {
        return false; 
    }

    m_fuel -= totalFuelNeeded;
    return true;
}

Truck::Truck(float initialFuel, float initialWeight) 
    : Vehicle(initialFuel, initialWeight) {}

bool Truck::run(float km) {
    if (km <= 0) return true;

    float fuelPerKm = (20.0f / 100.0f) + (m_weight / 1000.0f) * (1.0f / 100.0f);
    float totalFuelNeeded = km * fuelPerKm;

    if (totalFuelNeeded > m_fuel) {
        return false; 
    }

    m_fuel -= totalFuelNeeded;
    return true;
}