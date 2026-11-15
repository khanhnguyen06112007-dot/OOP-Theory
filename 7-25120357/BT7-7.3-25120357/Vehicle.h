#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle {
protected:
    float m_fuel;   
    float m_weight; 

public:
    Vehicle(float initialFuel = 0.0f, float initialWeight = 0.0f);

    void addWeight(float weight);
    void removeWeight(float weight);
    void addFuel(float fuel);
    float getFuel() const;
};

class MotorBike : public Vehicle {
public:
    MotorBike(float initialFuel = 0.0f, float initialWeight = 0.0f);
    bool run(float km);
};

class Truck : public Vehicle {
public:
    Truck(float initialFuel = 0.0f, float initialWeight = 0.0f);
    bool run(float km);
};

#endif