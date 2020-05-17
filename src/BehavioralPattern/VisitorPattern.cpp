/*
 * VisitorPattern.cpp
 *
 *  Use case: We need a tool for structure traversal rather than anything else.
 *            define a new operation on an entire class hierarchy
 *            do not want to keep modifying every class in the hierarchy
 *            need access to the non common aspects of clesses in the hierarchy.
 *            create an external document to handle rendering 
 *              
 *
 *  ========> Visitor: a component is allowed to traverse the entire inheritance hierarchy.
 *                     Implemented by propagating a single visit() method throughout the entire hierarchy.
 *
 *          Application Ex: make a document model printable to HTML/ markdown
 *
 *  Created on: Oct 24, 2019
 *      Author: ubuntu
 */
#include "iostream"
#include "string"
#include "sstream"
#include "memory"
#include "vector"
#include "boost/lexical_cast.hpp"

using namespace std;

struct Expression
{
    virtual ~Expression() = default;
    // intrusive visitor method
    virtual void print(ostringstream &oss) = 0;
};

struct DoubleExpression: Expression
{
    double value;

    DoubleExpression(double value): value(value){}

    void print(ostringstream &oss) override
    {
        oss << value;
    }
};

struct AdditionExpression: Expression
{
    Expression *left,*right;
    AdditionExpression(Expression *left, Expression *right): left(left),right(right)
    {

    }
    ~AdditionExpression()
    {
        delete left;
        delete right;
    }

    void print(ostringstream &oss) override
    {
        oss << "(";
        left->print(oss);
        oss << "+";
        right->print(oss);
        oss << ")";
    }
};

// (1+(2+3))
int main(int argc, char *argv[])
{
    auto e = new AdditionExpression{
                            new DoubleExpression{1},
                            new AdditionExpression{
                                new DoubleExpression{2},
                                new DoubleExpression{3}
                            }
                        };
    ostringstream oss;
    e->print(oss);
    cout << oss.str() << endl;
    delete e;

    return 0;
}