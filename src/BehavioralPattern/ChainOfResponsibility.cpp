/*
 * ChainOfResponsibility.cpp
 *
 *  Use case: Sequence of handlers processing an event one after another
 *
 *  ========> Chain of Responsibility: Sequence of event handlers
 *
 *          Application Ex: click a graphical element on a form
 *                          CCG computer game
 *
 *  Created on: Oct 24, 2019
 *      Author: ubuntu
 */
#include "iostream"
#include "string"
#include "sstream"
#include "memory"
using namespace std;

struct Creature
{
        string name;
        int attack,defence;
        Creature(const string &name, const int &attack, const int &defence)
        : name(name),attack(attack),defence(defence)
        {
        }

        friend ostream &operator<<(ostream &os,const Creature &creature)
        {
            os << "name: " << creature.name << " attack: " << creature.attack << " defence: " << creature.defence ;
            return os;
        }
};

// this class will take the creature struct and modify them
// Creature handlers
// this is a sequence
class CreatureModifier
{
        CreatureModifier *next{nullptr};
    protected:
        Creature &creature;
    public:
        CreatureModifier(Creature &creature) :
                        creature(creature)
        {

        }

        // add pointer chain
        void add(CreatureModifier *cm)
        {
            if(next) next->add(cm);
            else next = cm;
        }

        virtual void handle()
        {
            if(next) next->handle();
        }
};

class DoubleAttackModifier:public CreatureModifier
{
    public:
        DoubleAttackModifier(Creature &creature) :
                        CreatureModifier(creature)
        {

        }

        // call the next handler after double attack
        void handle() override
        {
            creature.attack *= 2;
            CreatureModifier::handle();
        }
};

class IncreaseDefenceModifier: public CreatureModifier
{
    public:
        IncreaseDefenceModifier(Creature &creature) :
                        CreatureModifier(creature)
        {

        }

        // call the next handler after increase defence
        void handle() override
        {
            creature.defence += 5;
            CreatureModifier::handle();
        }
};

int chainOfResponsibility()
//int main(int argc, char *argv[])
{
    Creature orge("orge",15,3);
    CreatureModifier root(orge);
    DoubleAttackModifier r1(orge);
    IncreaseDefenceModifier r2(orge);

    // buff to character
    root.add(&r1);
    root.add(&r2);

    // apply spell cast
    root.handle();

    cout << orge << endl;
    return 0;
}

