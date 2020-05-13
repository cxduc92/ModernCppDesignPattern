/*
 * FacadePattern.cpp
 *
 *  Use case: Exposing several components through a single interface
 *            Balancing complexity and presentation / usability
 *            A typical system:
 *            _ many subsystems
 *            _ complex internal structure
 *            _ end user is not exposed to internals
 *
 *  ========> Facade: Exposing several components through a single interface
 *                    Provide a simple, easy way to understand / user interface over a large and sophisticated body of code
 *          Application Ex:
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
#include "vector"
using namespace std;

// complicated subsystems / projects, already finished implementation
struct Window
{

};

// Facade interface
class Console
{
    public:
        static Console &instance()
        {
            static Console console;
            return console;
        }

        vector<shared_ptr<Window>> windows;

        // rename to a convenient name to remember
        shared_ptr<Window> multicolumn(const string& title, uint8_t columnCount, uint8_t columnWidth, uint8_t charsHigh)
        {
            auto w = make_shared<Window>();
            return w;
        }
    private:
        const int charWidth = 10, charHeight = 14;
        Console(){}
        Console(Console const&) = delete;
        void operator=(Console const&) = delete;
};

int runFacadePattern()
//int main(int argc, char *argv[])
{
    // create a whole subsystem via one single interface
    auto window = Console::instance().multicolumn("Test",2,40,40);

    return 0;
}

