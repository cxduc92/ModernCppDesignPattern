/*
 * MediatorPattern.cpp
 *
 *  Use case: Facilitates communication between components. The components could in and out the system any time
 *            It makes no sense for them to have direct references to one another
 * 
 *  ========> Mediator: A component that facilitates communication between other components without them neccessarily being aware of each other having
 *                      direct (reference) access to each other
 * 
 *                      Context class (Central Component): every single part of the system has a pointer to that component and communicates exclusively through that component
 * 
 *          Application Ex: Chat room participants
 *                          Players in MMORPG
 *
 *  Created on: Oct 24, 2019
 *      Author: ubuntu
 */
#include "iostream"
#include "string"
#include "sstream"
#include "memory"

#include "Person.hpp"
#include "ChatRoom.hpp"

int runMeditatorPattern()
//int main(int argc, char *argv[])
{
  ChatRoom room;

  Person john{"John"};
  Person jane{"Jane"};
  room.join(&john);
  room.join(&jane);
  john.say("hi room");
  jane.say("oh, hey john");

  Person simon{"Simon"};
  room.join(&simon);
  simon.say("hi everyone!");

  jane.pm("Simon", "glad you found us, simon!");

  return 0;
}