/*
 * CommandPattern.cpp
 *
 *  Use case: Ordinary C++ statement are perishable
 *            Want an object that represents an operation
 *            GUI command
 *
 *  ========> Command: An object which re
 *
 *          Application Ex: click a graphical element on a form
 *                          CCG computer game
 *
 *  Created on: Oct 24, 2019
 *      Author: ubuntu
 */
#include "iostream"
#include "string"
#include "sstream"
#include "memory"
#include "vector"
using namespace std;

struct BankAccount
{
        int balance{0};
        int overdraft_limit{-500};

        void deposit(int amount)
        {
            balance += amount;
            cout << "deposited " << amount << ", balance is now " << balance << endl;
        }

        void withdraw(int amount)
        {
            if(balance - amount >= overdraft_limit)
            {
                balance -= amount;
                cout << "withdrew " << amount << ", balance is now " << balance << endl;
            }
        }

        friend ostream &operator<<(ostream &os, const BankAccount &account)
        {
            os << "balance: " << account.balance;
            return os;
        }
};

struct Command
{
        virtual void call() = 0;
};

struct BankAccountCommand : Command
{
        BankAccount& account;
        enum Action {deposit,withdraw} action;// enum inside a class, therefore there is no enum class
        int amount;

        BankAccountCommand(BankAccount &account, Action action, int amount)
        : account(account),action(action),amount(amount)
        {
        }

        void call() override
        {
            switch(action)
            {
                case deposit:
                    account.deposit(amount);
                    break;
                case withdraw:
                    account.withdraw(amount);
                    break;
            }
        }
};

int runCommandPattern()
//int main(int argc, char *argv[])
{
    BankAccount ba;

    vector<BankAccountCommand> commands
    {
        BankAccountCommand{ba,BankAccountCommand::deposit,100},
        BankAccountCommand{ba,BankAccountCommand::withdraw,200}
    };

    cout << ba << endl;

    for (auto& cmd: commands)
        cmd.call();
    cout << ba << endl;
    return 0;
}

