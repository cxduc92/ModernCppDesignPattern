/*
 * CompositePattern.cpp
 *
 *  Use case: Objects use other object's fields/properties/member through inheritance and composition
 *            Composition make us ake compound objects
 *
 *  ========> Bridge: a mechanism that treats individual and aggregate objects uniformly
 *
 *
 *          Application Ex: group multiple shapes object as one uniform object
 *                          Neural Network
 *
 *  Created on: Oct 24, 2019
 *      Author: ubuntu
 */
#include "iostream"
#include "stdint.h"
#include "stdio.h"
#include "string"
#include "memory"
#include "vector"
#include "cstdio"
#include <boost/predef/library/c.h>

using namespace std;

struct GraphicObject
{
        virtual void draw() = 0;
};

struct Circle:GraphicObject
{
        void draw() override
        {
            cout << "Circle" << endl;
        }
};

struct Group:GraphicObject
{
        string name;

        explicit Group(const string &name):name(name){}

        void draw() override
        {
            cout << "Group " << name.c_str() << " contains:" << endl;
            for (auto&& o : objects)
            {
                o->draw();
            }
        }

        vector<GraphicObject*> objects;
};

struct Neuron;

template <typename Self>
struct SomeNeurons
{
  template <typename T> void connect_to(T& other)
  {
    for (Neuron& from : *static_cast<Self*>(this))
    {
      for (Neuron& to : other)
      {
//        from.out.push_back(&to);
//        to.in.push_back(&from);
      }
    }
  }
};

struct Neuron : SomeNeurons<Neuron>
{
  vector<Neuron*> in, out;
  unsigned int id;

  Neuron()
  {
    static int id = 1;
    this->id = id++;
  }

  /*template <typename T> void connect_to(T& other)
  {
    for (Neuron& target : other)
      connect_to(target);
  }*/

  // legal in MSVC only
  /*template<> void connect_to<Neuron>(Neuron& other)
  {
    out.push_back(&other);
    other.in.push_back(this);
  }*/

  // connect_to(vector<Neuron>&)

  Neuron* begin() { return this; }
  Neuron* end() { return this + 1; }

  friend ostream& operator<<(ostream& os, const Neuron& obj)
  {
    for (Neuron* n : obj.in)
    {
      os << n->id << "\t-->\t[" << obj.id << "]" << endl;
    }

    for (Neuron* n : obj.out)
    {
      os << "[" << obj.id << "]\t-->\t" << n->id << endl;
    }
    return os;
  }
};

struct NeuronLayer : vector<Neuron>, SomeNeurons<NeuronLayer>
{
  NeuronLayer(int count)
  {
    while (count-- > 0)
      emplace_back(Neuron{});
  }

  friend ostream& operator<<(ostream& os, NeuronLayer& obj)
  {

    for (auto& n : obj) os << n;
    return os;
  }
};

//int main(int argc, char *argv[])
int runCompositePattern()
{
//    Group root("root");
//    Circle c1, c2;
//    root.objects.push_back(&c1);
//    root.draw();
//
//    Group subgroup("sub");
//    subgroup.objects.push_back(&c2);
//
//    root.objects.push_back(&subgroup);
//
//    subgroup.draw();

    Neuron n1, n2;
    n1.connect_to(n2);

    cout << n1 << n2 << endl;

    NeuronLayer l1{ 5 };
    Neuron n3;
    l1.connect_to(n3);

    cout << "Neuron " << n3.id << endl << n3 << endl;
    cout << "Layer " << endl << l1 << endl;

    NeuronLayer l2{ 2 }, l3{ 3 };
    l2.connect_to(l3);
    cout << "Layer l2" << endl << l2;
    cout << "Layer l3" << endl << l3;
    return 0;
}

