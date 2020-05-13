/*
 * DependencyInversionPrinciple.cpp
 *
 *  Use case:
 *  A. High-level modules should not depend on low-level modules
 *     Both should depend on abstractions
 *  B. Abstractions should not depend on details
 *     Details should depend on abstractions
 *
 *  Abstraction: interfaces or base class
 *  Advantage:
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
#include "tuple"
//#include "boost/lexical_cast.hpp"

enum class Relationship
{
    parent,
    child,
    sibling
};

struct Person
{
        std::string name;
};

// abstraction level or intefaces
struct RelationshipBrowser
{
        virtual std::vector<Person> find_all_children_of(const std::string &name) = 0;
};

struct Relationships: RelationshipBrowser // low-level construct
{
        std::vector<std::tuple<Person, Relationship, Person>> relations;

        void add_parent_and_child(const Person &parent, const Person &child)
        {
            //relations.push_back(std::tuple{parent,Relationship::parent,child});
            //relations.push_back({child,Relationship::child,parent});
        }
};

struct Research // high-level
{
        Research(Relationships &relationship)
        {
//            auto & relations = relationship.relations;
//            for(auto&& [first,rel,second] : relations)
//            {
//                if(first.name == "John" && rel == Relationship::parent)
//                {
//                    std::cout << "John has a child called" << second.name << std::endl;
//                }
//            }
        }
};

//int main(int argc, char *argv[])
int runDependencyInversionPrinciple()
{
    Person parent
    { "John" };
    Person child1
    { "Chris" }, child2
    { "Matt" };

//    Relationships relationships;
//    relationships.add_parent_and_child(parent,child1);
//    relationships.add_parent_and_child(parent,child2);

//    Research _(relationships);
    return 0;
}

