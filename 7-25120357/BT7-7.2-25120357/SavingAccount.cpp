#include "SavingAccount.h"
SavingAccount::SavingAccount(float initialBalance, int period, float rate){
    Account::deposit(initialBalance);
    m_period = period;
    m_rate = rate;
    m_duration = 0;
}
float SavingAccount::CalculateInterest(){
    return getBalance() * (m_rate / 100.0f) * (m_duration / 12.0f);
}

void SavingAccount::deposit(float money){
    float interest = CalculateInterest();
    Account::deposit(interest + money);
    m_duration = 0;
}
bool SavingAccount::withdraw(float money){
    float interest = CalculateInterest();
    Account::deposit(interest);
    if (!Account::withdraw(money)){
        Account::withdraw(interest);
        return false;
    }
    m_duration = 0;
    return true;
}
void SavingAccount::increaseDuration(){
    m_duration++;
}