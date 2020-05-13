/*
 * OpenClosedPrinciple.cpp
 *
 *  Use case: Filter(specific task) the class (product) for certain attributes(color)
 *  ========> Normally, the system or code would be extended or added more feature many times.
 *            How could we extend the classes module ? By using specification pattern
 *
 *  Advantage: No need to implement multiple specification for a specific task
 *
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

enum class Color
{
    red, green, blue
};
enum class Size
{
    small, medium, large
};

struct Product
{
        std::string name;
        Color color;
        Size size;
};

struct ProductFilter
{
        std::vector<Product*> by_color(std::vector<Product*> items, Color color)
        {
            std::vector<Product*> result;
            for (auto &i : items)
                if (i->color == color)
                    result.push_back(i);
            return result;
        }

        std::vector<Product*> by_size(std::vector<Product*> items, Size size)
        {
            std::vector<Product*> result;
            for (auto &i : items)
                if (i->size == size)
                    result.push_back(i);
            return result;
        }

        // not great implementation, what if the customer come back and say: "add 4 more attributes and filter them"
        // need 2^4 more function with copy paste code
        std::vector<Product*> by_size_and_color(std::vector<Product*> items, Color color, Size size)
        {
            std::vector<Product*> result;
            for (auto &i : items)
                if (i->size == size && i->color == color)
                    result.push_back(i);
            return result;
        }
};

////////////////////////////////////////////////////////////////////////////////////////////
// Specification pattern: perform a specific task for certain attributes with extended behavior
////////////////////////////////////////////////////////////////////////////////////////////

// add a specification interface
template<typename T> struct Specification
{
        virtual bool is_satisfied(T *item) = 0;
};

// add another interface template class called filter
template<typename T> struct Filter
{
        virtual std::vector<T*> filter(std::vector<T*> items, Specification<T> &spec) = 0;
};

struct BetterFilter: Filter<Product>
{
        std::vector<Product*> filter(std::vector<Product*> items, Specification<Product> &spec) override
        {
            std::vector<Product*> result;
            for (auto &item : items)
                if (spec.is_satisfied(item))
                    result.push_back(item);
            return result;
        }
};

struct ColorSpecification: Specification<Product>
{
        Color color;
        ColorSpecification(Color color) :
                        color(color)
        {
        }

        bool is_satisfied(Product *item) override
        {
            return item->color == color;
        }
};

struct SizeSpecification: Specification<Product>
{
        Size size;
        SizeSpecification(Size size) :
                        size(size)
        {
        }

        bool is_satisfied(Product *item) override
        {
            return item->size == size;
        }
};

template<typename T> struct AndSpecification: Specification<T>
{
        Specification<T> &first;
        Specification<T> &second;
        AndSpecification(Specification<T> &first,
                        Specification<T> &second) :
                        first(first), second(second)
        {
        }

        bool is_satisfied(T *item) override
        {
            return first.is_satisfied(item) && second.is_satisfied(item);
        }
};

//int main(int argc, char *argv[])
int runOpenClosedPrinciple()
{
    Product apple
    { "Apple", Color::green, Size::small };
    Product tree
    { "Tree", Color::green, Size::large };
    Product house
    { "House", Color::blue, Size::large };

    std::vector<Product*> items
    { &apple, &tree, &house };

    ProductFilter pf;

    BetterFilter bf;
    ColorSpecification green(Color::green);
    SizeSpecification large(Size::large);
    AndSpecification<Product> green_and_large(green, large);

    auto green_stuff = pf.by_color(items, Color::green);
    for (auto &item : green_stuff)
        std::cout << "product filter:" << item->name << " is green \n";

    for (auto &item : bf.filter(items, green))
        std::cout << "better filter:" << item->name << " is green\n";

    for (auto &item : bf.filter(items, green_and_large))
        std::cout << "better filter:" << item->name << " is green and large\n";
    return 0;
}

