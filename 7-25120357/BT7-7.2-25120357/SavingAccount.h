#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H
#include "Account.h"

class SavingAccount : public Account{
private:   
    int m_period;
    float m_rate;
    int m_duration;
public:
    SavingAccount(float initialBalance = 0, int period = 12, float rate = 6.0f);
    float CalculateInterest();
    void deposit(float money);
    bool withdraw(float money);
    void increaseDuration();
};

#endif