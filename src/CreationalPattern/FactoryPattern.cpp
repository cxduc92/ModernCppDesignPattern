/*
 * FactoryPattern.cpp
 *
 *  Use case:   Object creation logic becomes too convoluted
 *              Constructor is not descriptive
 *              Object creation (non-piecewise, unlike Builder) can be outsourced to
 *
 *  ========> Factory: a component responsible solely for the wholesale (not piecewise)
 *                      creation of objects
 *                      A method is use to create the object
 *
 *          Application Ex: create an object constructor with multiple meaning without creating multiple classes
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

enum class PointType
{
        cartesian,
        polar
};

//struct Point
//{
//        /// add documentation description here to create cartesian or polar coordinates
//        Point(float a,float b, PointType type = PointType::cartesian)
//        {
//            if (type == PointType::cartesian)
//            {
//                x = a;
//                y = b;
//            }
//            else
//            {
//                x = a*cos(b);
//                y = a*sin(b);
//            }
//        }
//
//        float x,y;
//};

class Point
{
    public:
        Point(float x, float y): x(x),y(y){}
        float x,y;

        friend ostream &operator<<(ostream &os, const Point &point)
        {
            os << "x: " << point.x << " y: " << point.y;
            return os;
        }
};

// factory class to create object
struct PointFactory
{
        // Factory method: construct the object with method without implementing 2 classes
        static Point NewCartesian(float x, float y)
        {
            return Point { x, y };
        }

        // Factory method: construct the object with method
        static Point NewPolar(float r, float theta)
        {
            return Point { r * cos(theta), r * sin(theta) };
        }
};

enum class EMessageType
{
        PM_CONFIG,
        PM_AUTHORIZE,
        PM_AUTH_HASH,
        PM_AUTH_CERT
};

// abstraction class
class CMessage
{
    private:
        EMessageType m_type;
        uint8_t m_id;
    public:
        CMessage(const EMessageType &type, const uint8_t &id) :
            m_id(id),
            m_type(type)
        {

        }

        friend ostream& operator<<(ostream &os, const CMessage &msg)
        {
            printf("type : %d id: %d \n",static_cast<uint8_t>(msg.m_type),static_cast<uint8_t>(msg.m_id));
            return os;
        }
};

// factory class to create object
struct CMessageFactory
{
        // Factory method: construct the object with method without implementing multiple classes
        static CMessage pmConfig(const uint8_t &id)
        {
            return CMessage { EMessageType::PM_CONFIG, id };
        }

        static CMessage pmAuthorize(const uint8_t &id)
        {
            return CMessage { EMessageType::PM_AUTHORIZE,id };
        }

        static CMessage pmAuthHash(const uint8_t &id)
        {
            return CMessage { EMessageType::PM_AUTH_HASH, id };
        }

        static CMessage pmAuthCert(const uint8_t &id)
        {
            return CMessage { EMessageType::PM_AUTH_CERT, id };
        }
};

//int main(int argc, char *argv[])
int runFactoryPattern()
{
    auto p = PointFactory::NewPolar(5,M_PI_4);
    cout << p << endl;

    auto pmConfig = CMessageFactory::pmConfig(1);
    cout << pmConfig << endl;

    auto pmAuthorize = CMessageFactory::pmAuthorize(2);
    cout << pmAuthorize << endl;

    auto pmAuthHash = CMessageFactory::pmAuthHash(3);
    cout << pmAuthHash << endl;

    auto pmAuthCert = CMessageFactory::pmAuthCert(4);
    cout << pmAuthCert << endl;

    return 0;
}

