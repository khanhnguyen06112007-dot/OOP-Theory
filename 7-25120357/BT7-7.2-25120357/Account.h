#ifndef ACCOUNT_H
#define ACCOUNT_H
class Account{
private:
    float m_balance;
public:
    float getBalance(){return m_balance;}
    void deposit(float money) {m_balance += money;}
    bool withdraw(float money){
        if (money > m_balance){
            return false;
        }
        m_balance -= money;
        return true;  
    }
};
#endif