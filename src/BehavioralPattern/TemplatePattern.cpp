/*
 * TemplatePattern.cpp
 *
 *  Use case: Algorithms can be decomposed into parts and specifics. The overall algorithm make use of abstract number
 *              
 *
 *  ========> Template: Allow us to define the "skeleton" of the algorithm, with concrete implementations defined in subclasses
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

class Game
{
public:
    Game(int number_of_players) : number_of_players(number_of_players) {}
    // template method
    void run()
    {
        start();
        while (!have_winner())
            take_turn();
        cout << "Player " << get_winner() << " wins.\n";
    }

protected:
    // behavior functions will be inherited in the concrete class
    virtual void start() = 0;
    virtual bool have_winner() = 0;
    virtual void take_turn() = 0;
    virtual int get_winner() = 0;
    int current_player{0};
    int number_of_players;
};

class Chess : public Game
{
public:
    Chess() : Game(2) {}

protected:
    void start() override
    {
        cout << "Starting a game of chess with "
             << number_of_players << " players\n";
    }

    bool have_winner() override
    {
        return turn == max_turn;
    }

    void take_turn() override
    {
        cout << "Turn " << turn << " taken by player " << current_player << "\n";
        ++turn;
        current_player = (current_player + 1) % number_of_players;
    }

    int get_winner() override
    {
        return current_player;
    }

private:
    int turn{0}, max_turn{10};
};

int runTemplatePattern()
//int main(int argc, char *argv[])
{
    Chess chess;
    chess.run();
    return 0;
}