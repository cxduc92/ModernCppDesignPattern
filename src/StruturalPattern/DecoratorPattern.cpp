/*
 * DecoratorPattern.cpp
 *
 *  Use case: Add behavior without altering the class itself
 *            Want to augment an object with additional functionality
 *            Do not want to rewrite or alter existing code (OCP)
 *            Want to keep new functionality separate (SRP)
 *            Have to interact with the existing structure from a separate component
 *
 *  ========> Decorator: Facilitates the addition of behaviors to individual objects
 *
 *          Application Ex: Add more functionality to the customer's API
 *
 *  Created on: Oct 24, 2019
 *      Author: ubuntu
 */
#include "iostream"
#include "cstdio"
#include "stdint.h"
#include "stdio.h"
#include "string"
#include "memory"
#include "fstream"
#include "boost/lexical_cast.hpp"

using namespace std;

// -----------------Customer API----------------------------------------
struct Shape
{
        virtual string str() const = 0;
        virtual void resize(const float &factor) = 0;
};

struct Circle:Shape
{
        float radius;

        Circle(float radius): radius(radius)
        {

        }

        void resize(const float &factor) override
        {
            radius *= factor;
        }

        string str() const override
        {
            ostringstream oss;
            oss << "A circle of radius " << radius;
            return oss.str();
        }
};

struct Square:Shape
{
        float side;

        Square(float side): side(side)
        {

        }

        string str() const override
        {
            ostringstream oss;
            oss << "A square of side " << side;
            return oss.str();
        }

        void resize(const float &factor) override
        {
            side *= factor;
        }
};

struct ColorShape:Shape
{
        Shape& shape;
        string color;

        ColorShape(Shape &shape,const string &color): shape(shape),color(color)
        {

        }

        string str() const override
        {
            ostringstream oss;
            oss << shape.str() << " has the color " << color;
            return oss.str();
        }

        void resize(const float &factor) override
        {
        }
};
// ----------------------------------------------------------------------------

// Decorator class which is inherited from interface Shape
// This is the extension for the customer API (decorator)
struct TransparentShape: Shape
{
        Shape& shape;
        uint8_t transparency;

        TransparentShape(Shape &shape, uint8_t transparency): shape(shape), transparency(transparency)
        {

        }

        string str() const override
        {
            ostringstream oss;
            oss << shape.str() << " has " << static_cast<float>(transparency) / 255.f * 100.f << "% transparency";
            return oss.str();
        }

        void resize(const float &factor) override
        {
        }
};

int runDecoratorPattern()
//int main(int argc, char *argv[])
{
    Square square(5);
    ColorShape color_shape(square,"red");
    cout << square.str() << endl << color_shape.str() << endl;

    Circle circle(3);
    cout << circle.str() << endl;
    circle.resize(5.f);
    cout << "Resize: " << circle.str() << endl;

    TransparentShape transparent_shape{color_shape, 51};
    cout << transparent_shape.str() << endl;
    return 0;
}

