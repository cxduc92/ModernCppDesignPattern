/*
 * SingletonPattern.cpp
 *
 *  Use case:   For a few components, it only makes sense to have one in the system.
 *              Constructor call is expensive(in term of memory allocation)
 *              We have to take care of lazy instantiation & thread safety
 *
 *  ========> Singleton: an unique object in a system
 *
 *          Application Ex: Context object, Factory object, Data base repository
 *
 *  Created on: Oct 24, 2019
 *      Author: ubuntu
 */
#include "iostream"
#include "cstdio"
#include "stdint.h"
#include "stdio.h"
#include "string"
#include "vector"
#include "fstream"
#include "map"
#include "boost/lexical_cast.hpp"

using namespace std;
using namespace boost;

enum class ESystemState
{
    Idle,
    Initializing,
    LoggingIn,
    Authorizing,
    Authorized,
    LoggingOut
};

struct DDataObject
{
        uint8_t id;
        uint8_t value;
};

class CSingletonContext
{
        CSingletonContext() :
                        m_SystemState(ESystemState::Idle),
                        m_DataObject{ 0, 0 }
        {
            cout << "Initialzing Context\n";
        }

        ESystemState m_SystemState;
        DDataObject m_DataObject;

    public:
        // ensure nobody can replicate the database object by deleting copy constructor
        CSingletonContext(CSingletonContext const&) = delete;
        void operator=(CSingletonContext const&) = delete;

        static CSingletonContext& get()
        {
            static CSingletonContext context;
            return context;
        }

        ESystemState getSystemState() const
        {
            return m_SystemState;
        }

        void setSystemState(const ESystemState &state)
        {
            m_SystemState = state;
        }

        DDataObject getData() const
        {
            return m_DataObject;
        }

        void setData(const DDataObject &data)
        {
            m_DataObject = data;
        }
};

class SingletonDatabase
{
        SingletonDatabase()
        {
            cout << "Initialzing database \n";
            ifstream ifs("capitals.txt");

            string s, s2;
            while (getline(ifs, s))
            {
                getline(ifs, s2);
                int pop = lexical_cast<int>(s2);
                capitals[s] = pop;
            }
        }

        map<string, int> capitals;

    public:
        // ensure nobody can replicate the database object by deleting copy constructor
        SingletonDatabase(SingletonDatabase const&) = delete;
        void operator=(SingletonDatabase const&) = delete;

        static SingletonDatabase& get()
        {
            static SingletonDatabase db;
            return db;
        }

        int get_population(const string &name)
        {
            return capitals[name];
        }
};

int runSingletonPattern()
//int main(int argc, char *argv[])
{
    string city = "Tokyo";
    cout << city << " has population: " << SingletonDatabase::get().get_population(city) << endl;

    printf("System State before set: %d\n", static_cast<int>(CSingletonContext::get().getSystemState()));

    // In case of System Context use case
    DDataObject data;
    data.id = 1;
    data.value = 10;
    CSingletonContext::get().setSystemState(ESystemState::LoggingIn);
    CSingletonContext::get().setData(data);
    printf("System State after set: %d\n", static_cast<int>(CSingletonContext::get().getSystemState()));
    printf("Message ID: %d\n", static_cast<int>(CSingletonContext::get().getData().id));
    printf("Value: %d\n", static_cast<int>(CSingletonContext::get().getData().value));
    return 0;
}

