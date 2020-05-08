/*
 * Single ResponsibilityPrinciple.cpp
 *
 *  Use case: if we have a function with parameter of a base class.
 *  We should be able to substitute the derive class to the parameter.
 *  However when we override the virtual void function of base class in derive class, we could break the sequence.
 *  Therefore, we solve with factory pattern
 *
 *  Advantage:
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
#include "boost/lexical_cast.hpp"

class Rectangle
{
    protected:
        int m_width, m_height;
    public:
        Rectangle(int width, int height)
        {
            m_width = width;
            m_height = height;
        }

        int area() const
        {
            return m_height*m_width;
        }

        int getWidth() const
        {
            return m_width;
        }

        virtual void setWidth(int width)
        {
            m_width = width;
        }

        int getHeight() const
        {
            return m_height;
        }

        virtual void setHeight(int height)
        {
            m_height = height;
        }
};

class Square: public Rectangle
{
    public:
        Square(int size): Rectangle(size,size){}
        void setWidth(int width) override
        {
            this->m_width = this->m_height = width;
        }

        void setHeight(int height) override
        {
            this->m_width = this->m_height = height;
        }
};

void process(Rectangle& r)
{
    int w = r.getWidth();
    r.setHeight(10);

    std::cout << "expected area = " << (w*10)
                    << ", got " << r.area()<< std::endl;
}

struct RectangleFactory
{
        static Rectangle create_rectangle(int w, int h);
        static Rectangle create_square(int size);
};

//int main(int argc, char *argv[])
int runLiskoSubstitutionPrinciple()
{
    Rectangle r{3,4};
    process(r);

    Square sq{5};
    process(sq);
    return 0;
}

