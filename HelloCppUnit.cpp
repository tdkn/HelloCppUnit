#include <iostream>
#include <string>

#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/CompilerOutputter.h>

#include "Animal.h"

using namespace std;
using namespace CPPUNIT_NS;

class UTest: public TestFixture
{
  private:
    CPPUNIT_TEST_SUITE(UTest);
    CPPUNIT_TEST(test_Constructor);
    CPPUNIT_TEST(test_Destructor);
    CPPUNIT_TEST(test_setName);
    CPPUNIT_TEST(test_getName);
    CPPUNIT_TEST(test_setMessage);
    CPPUNIT_TEST(test_getMessage);
    CPPUNIT_TEST(test_makeNoise_isNameNull);
    CPPUNIT_TEST(test_makeNoise_isMessageNull);
    CPPUNIT_TEST(test_makeNoise_filled);
    CPPUNIT_TEST_SUITE_END();

    Animal* animal;

  public:
    void setUp(void)
    {
      this->animal = new Animal();
    }
    void tearDown(void)
    {
      delete this->animal;
      this->animal = NULL;
    }

  private:
    void test_Constructor(void)
    {
      // assertion
      CPPUNIT_ASSERT("" == this->animal->getName());
      CPPUNIT_ASSERT("" == this->animal->getMessage());
    }

    void test_Destructor(void)
    {
      // preparation
      Animal* animal = new Animal();

      // action
      delete animal;

      // assertion
      // not required.
    }

    void test_setName(void)
    {
      // preparation
      const string name = "Wolf";

      // action
      this->animal->setName(name);

      // assertion
      CPPUNIT_ASSERT(name == this->animal->getName());
    }

    void test_getName(void)
    {
      // preparation
      const string name = "Wolf";
      this->animal->setName(name);

      // action
      string ret = this->animal->getName();

      // assertion
      CPPUNIT_ASSERT(name == ret);
    }

    void test_setMessage(void)
    {
      // preparation
      const string message = "hoooooooowl";

      // action
      this->animal->setMessage(message);

      // assertion
      CPPUNIT_ASSERT(message == this->animal->getMessage());
    }

    void test_getMessage(void)
    {
      // preparation
      const string message = "hoooooooowl";
      this->animal->setMessage(message);

      // action
      string ret = this->animal->getMessage();

      // assertion
      CPPUNIT_ASSERT(message == ret);
    }

    void test_makeNoise_isNameNull(void)
    {
      // preparation
      this->animal->setName("");
      this->animal->setMessage("hoooooooowl");

      // action
      bool ret = this->animal->makeNoise();

      // assertion
      CPPUNIT_ASSERT(false == ret);
    }

    void test_makeNoise_isMessageNull(void)
    {
      // preparation
      this->animal->setName("Wolf");
      this->animal->setMessage("");

      // action
      bool ret = this->animal->makeNoise();

      // assertion
      CPPUNIT_ASSERT(false == ret);
    }

    void test_makeNoise_filled(void)
    {
      // preparation
      this->animal->setName("Wolf");
      this->animal->setMessage("hoooooooowl");

      // action
      bool ret = this->animal->makeNoise();

      // assertion
      CPPUNIT_ASSERT(true == ret);
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(UTest);

int main(int argc, char const* argv[])
{
  TestResult controller;
  TestResultCollector result;
  controller.addListener(&result);

  BriefTestProgressListener progress;
  controller.addListener(&progress);

  TestRunner runner;
  runner.addTest(TestFactoryRegistry::getRegistry().makeTest());
  runner.run(controller);

  CompilerOutputter outputter(&result, stdCOut());
  outputter.write();

  return result.wasSuccessful() ? 0 : 1;
}

