/*
 * ProxyPattern.cpp
 *
 *  Use case: An interface for accessing a particular resource
 *            What if, later on, we want to put all methods-related operations into a separate process
 *            Can we avoid changing our code?
 *            Same interface, different behavior
 *
 *  ========> Proxy: a class that functions as an interface to a particular resource.
 *                   That resource maybe remote, expensive to construct,
 *                   or may require logging or some other added functionality
 *
 *          Application Ex:
 *
 *  Created on: Oct 24, 2019
 *      Author: ubuntu
 */
#include "iostream"
#include "string"
#include "sstream"
#include "memory"
using namespace std;

struct BankAccount
{
        virtual ~BankAccount() = default;
        virtual void deposit(int amount) = 0;
        virtual void withdraw(int amount) = 0;
};

struct CurrentAccount: BankAccount // checking
{
        explicit CurrentAccount(const int balance)
        :
                        balance(balance)
        {
        }

        void deposit(int amount) override
        {
            balance += amount;
        }

        void withdraw(int amount) override
        {
            if (amount <= balance)
                balance -= amount;
        }

        friend ostream& operator<<(ostream &os, const CurrentAccount &obj)
        {
            return os << "balance: " << obj.balance;
        }

    private:
        int balance;
};

int runProxyPattern()
//int main(int argc, char *argv[])
{
    BankAccount *a = new CurrentAccount(123);
    a->deposit(321);
    delete a;

    auto b = make_shared<CurrentAccount>(123);
    BankAccount *actual = b.get(); // enhancement

    return 0;
}

