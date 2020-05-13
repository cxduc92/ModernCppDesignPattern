/*
 * PrototypePattern.cpp
 *
 *  Use case: Create an object from another existing object
 *
 *  ========> Prototype: Create a copy(clone of a prototype)
 *
 *          Application Ex: Product improvement, create an improvement from existing design
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
#include "cmath"
#include "boost/lexical_cast.hpp"

using namespace std;
struct Address
{
        string street,city;
        int suite;
        Address(const string &street, const string &city, int suite):
            street(street),city(city),suite(suite)
        {

        }

        // operator to save the record of the current object
        friend ostream &operator<<(ostream &os,const Address &address)
        {
            os << "street: "<< address.street << " city: " << address.city << " suite: " << address.suite;
            return os;
        }
};

struct Contact
{
        string name;
        Address address;
        Contact(const string &name,const Address &address):name(name),address(address)
        {

        }

        // operator to save the record of the current object
        friend ostream &operator<<(ostream &os, const Contact &contact)
        {
            os << "name: " << contact.name << " address: " << contact.address;
            return os;
        }
};

//int main(int argc, char *argv[])
int runPrototypePattern()
{
    Contact john{"John Doe", Address{"123 Eaststr","London",123}};
    // Contact jane{"Jane Smith", Address{"123 Eaststr","London",103}};

    // prototype jane from john
    Contact jane = john;
    jane.name = "Jane Smith";
    jane.address.suite = 103;

    cout << john << endl;
    cout << jane << endl;
    return 0;
}

