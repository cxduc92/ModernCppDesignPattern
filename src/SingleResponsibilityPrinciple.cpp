/*
 * Single ResponsibilityPrinciple.cpp
 *
 *  Use case: when we have multiple classes with the same methods
 *  ========> It's better to create a persistence manager to manage common methods
 *
 *  Advantage: When we have to change code in the common methods (which happens everyday),
 *              we dont have to change all the methods in multiple class. Only change the methods in the persistence manager
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

struct Journal{
        std::string title;
        std::vector<std::string> entries;

        Journal(const std::string &title) : title(title){}

        void add_entry(const std::string& entry)
        {
            static int count = 1;
            entries.push_back(boost::lexical_cast<std::string>(count++) + "."+entry);
        }

        void save(const std::string& filename)
        {
            std::ofstream ofs(filename);
            for(auto& e:entries)
                ofs << e << std::endl;
        }
};

struct PersistenceManager
{
        void save(const Journal &j,const std::string &filename)
        {
            std::ofstream ofs(filename);
            for (auto &e : j.entries)
                ofs << e << std::endl;
        }

};

//int main(int argc, char *argv[])
int runSingleResponsibility()
{
    Journal journal{"Dear Diary"};
    journal.add_entry("Creational Design Pattern");
    journal.add_entry("Open Closed Principle");
    journal.add_entry("Specification pattern");

    PersistenceManager pm;
    pm.save(journal,"diary.txt");
    return 0;
}

