/*
 * IteratorPattern.cpp
 *
 *  Use case: How traversal of data structures happens and who makes it happen
 *
 *  ========> Iterator: is a core functionality of various data structure
 *            An iterator is a class that facilitates the traversal and can be used implicitly
 *
 *          Application Ex: 
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

int runInteratorPattern()
//int main(int argc, char *argv[])
{
    vector<string> names {"john","jane","jill","jack"};
    vector<string>::iterator it = names.begin(); //begin(names)
    cout << "first name is " << *it << endl;

    ++it;
    it->append(string(" goodall"));
    cout << "the second name is "<< *it << endl;

    // 1 2 3 4 
    //         ^
    while (++it !=names.end())
    {
        cout << "another name: " << *it << endl;
    }
    
    //  1 2 3
    // ^    ^ rbegin
    // print the reverse order names
    for (auto ri = boost::rbegin(names); ri != boost::rend(names); ++ri)
    {
        cout << *ri;
        if(ri+1 != boost::rend(names))
        {
            cout << ". ";
        }
    }
    cout << endl;

    // begin/end
    // for each start from the first to last element of the array
    for(auto &name : names)
        cout << "name = " << name << endl;
    return 0;
}
