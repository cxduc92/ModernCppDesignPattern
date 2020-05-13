/*
 * BridgePattern.cpp
 *
 *  Use case: Connecting components together through abstraction layer
 *
 *  ========> Bridge: a mechanism that decouples an interface from an implementation
 *                    both can exist as hierarchy
 *                    A stronger form of encapsulation
 *
 *
 *          Application Ex: To hide trading secret or personal secret.
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
#include "map"
#include "boost/lexical_cast.hpp"

using namespace std;

// pimpl idiom: the method would be defined inside a class
// action of person is actually integrated in class PersonImpl
// this approach will hide the implementation in a different pimpl
// that we not explicitly handle  binary file to the customer
// We are hiding the implementation details. Not exposing it outside
//
// Another advange is when the we change the methods in the cpp files,
// the customer does not have to compile their project again which is time effective.
// What we do is just recompile the binary file and ship again. Customer does not have to do anything
//
// App: To hide trading secret or personal secret.
// Therefore, we only give the customer the header file with public methods
// We ship API to customer only the abstraction header file (Person.h)
//class Person
//{
//    public:
//        string name;
//        Person()
//        :impl(new PersonImpl)
//        {
//
//        }
//
//        ~Person()
//        {
//            delete impl;
//        }
//
//        class PersonImpl;
//        PersonImpl* impl;
//
//        void greet()
//        {
//            impl->greet(this);
//        }
//};
//
//class Person::PersonImpl
//{
//    public:
//        void greet(Person* p)
//        {
//            cout << "hello my name is "<< p->name <<endl;
//        }
//    private:
//        void privateMethod();
//};

// this would be a pimpl library
template <typename T> class pimpl
{
    private:
        // unique pointer, it would be delete automatically
        // therefore, we dont have to delete it in the destructor
        unique_ptr<T> impl;
    public:
        pimpl(): impl{new T{}}
        {
        }

        ~pimpl()
        {
        }

        template <typename ...Args>pimpl(Args&& ...args)
                        :impl {new T{forward<Args>(args)...}}
        {
        }

        T* operator->()
        {
            return impl.get();
        }

        T& operator*()
        {
            return *impl.get();
        }

};

class foo
{
        class impl;
        pimpl<impl> impl;
};

// Shapes- circle,square
// Renderer - raster, vector

// 2x2 RasterCircleRenderer, RasterSquareRenderer, VectorCircleRend.
struct Renderer
{
        virtual void render_circle(float x, float y, float radius) = 0;
};

struct VectorRendere: Renderer
{
        void render_circle(float x, float y, float radius) override
        {
            cout << "Rasterizing the circle of radius " << radius << endl;
        }
};

struct RasterRenderer: Renderer
{
        void render_circle(float x,float y,float radius) override
        {
            cout << "Drawing a vector circle of radius " << radius << endl;
        }
};

// Bridge: reference to the renderer
// Define an interface as a bridge to the component that actually using it.
// The component using it is Circle, the bridge is from interface Renderer to interface Shape
struct Shape
{
    protected:
        Renderer& renderer;
        Shape(Renderer &renderer): renderer(renderer)
        {

        }
    public:
        virtual void draw() = 0;
        virtual void resize(float factor) = 0;
};

struct Circle:Shape
{
        Circle(Renderer &renderer,float x,float y, float radius):
            Shape(renderer),x{x},y{y},radius{radius}
        {

        }

        float x,y,radius;

        void draw() override
        {
            renderer.render_circle(x,y,radius);
        }

        void resize(float factor) override
        {
            radius *= factor;
        }
};

int runBridgePattern()
//int main(int argc, char *argv[])
{
    RasterRenderer rr;
    Circle raster_circle{rr,5,5,5};
    raster_circle.draw();
    raster_circle.resize(2);
    raster_circle.draw();
    return 0;
}

