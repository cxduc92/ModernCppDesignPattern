/*
 * MementoPattern.cpp
 *
 *  Use case: An object or system goes through many changes.
 *            We need an approach to navigate through changes.(Undo changes)
 *
 *  ========> Command: An token/handle represents the system state.Let us rool back to the state when the token was generated.
 *  May or may not directly expose state information
 *
 *          Application Ex: Bank account
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

// snap shot of the BankAccount object
class Memento
{
    int balance;

public:
    Memento(int balance) : balance(balance) {}

    friend class BankAccount;
};

class BankAccount
{
private:
    int balance{0};

public:
    BankAccount(int balance) : balance(balance) {}

    Memento deposit(int amount)
    {
        balance += amount;
        return Memento{balance};
    }

    Memento withdraw(int amount)
    {
        balance -= amount;
        return Memento{balance};
    }

    // undo balance changes
    void undo(const Memento &m)
    {
        balance = m.balance;
    }

    friend ostream &operator<<(ostream &os, const BankAccount &account)
    {
        os << "balance : " << account.balance;
        return os;
    }
};

// // records all the changes in the account
// class BankAccount2
// {
//     int balance{0};
//     vector<shared_ptr<Memento>> changes;
//     int current; // ^^^^
//     BankAccount2(int balance): balance(balance)
//     {
//         changes.emplace_back(make_shared<Memento>(balance));
//         current = 0;
//     }

//     shared_ptr<Memento> deposit(int amount)
//     {
//         balance += amount;
//         auto m= make_shared<Memento>(balance);
//         changes.push_back(m);
//         ++current;
//         return m;
//     }

//     void restore(const shared_ptr<Memento>&m)
//     {
//         if(m)
//         {
//             balance = m->balance;
//             changes.push_back(m);
//             current = changes.size()-1;
//         }
//     }

//     shared_ptr<Memento> undo()
//     {
//         if(current > 0)
//         {
//             --current;
//             auto m = changes[current];
//             balance = m->balance;
//             return m;
//         }
//     }

//     shared_ptr<Memento> redo()
//     {
//         if(current + 1 < changes.size())
//         {
//             ++current;
//             auto m = changes[current];
//             balance = m->balance;
//             return m;
//         }
//         return {};
//     }

//     friend ostream &operator<<(ostream &os, const BankAccount2 &account2)
//     {
//         os << "balance: " << account2.balance;
//         return os;
//     }
// };

int runMementoPattern()
//int main(int argc, char *argv[])
{
    BankAccount ba{100};
    auto m1 = ba.deposit(50); // 150
    auto m2 = ba.deposit(25); // 175
    auto m3 = ba.withdraw(50); // 125
    cout << ba << "$\n";

    ba.undo(m1);
    cout << "back to m1: " << ba << "$\n";

    ba.undo(m2);
    cout << "back to m2: " << ba << "$\n";
    return 0;
}
