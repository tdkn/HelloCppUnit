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

  std::cout << this->name + "> " + this->message << std::endl;
  return true;
}
