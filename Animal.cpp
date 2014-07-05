#include <iostream>
#include "Animal.h"

Animal::Animal() : name(""), message("")
{
}

Animal::~Animal()
{
}

void Animal::setName(string name)
{
  this->name = name;
}

string Animal::getName()
{
  return this->name;
}

void Animal::setMessage(string message)
{
  this->message = message;
}

string Animal::getMessage()
{
  return this->message;
}

bool Animal::makeNoise()
{
  if (this->name == "")
  {
    return false;
  }
  if (this->message == "")
  {
    return false;
  }

  this->noise = this->name + "> " + this->message;
  return true;
}
