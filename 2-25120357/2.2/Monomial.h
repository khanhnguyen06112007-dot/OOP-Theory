#ifndef MONOMIAL_H
#define MONOMIAL_H

class Monomial{
private:
    float coef;
    int expo;
public:
    void input();
    void output() const;

    float getCoef() const;
    void setCoef(float coef);

    int getExpo() const;
    void setExpo(int expo);

    float evaluate(float x) const;
    Monomial derive() const;
    Monomial mul(const Monomial &other) const;
};

#endif