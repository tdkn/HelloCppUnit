#include <string>

using namespace std;

class Animal
{
  private:
    string name;
    string message;

  public:
    Animal();
    ~Animal();

    void setName(string name);
    string getName(void);

    void setMessage(string message);
    string getMessage(void);

    bool makeNoise(void);
};

