#include <string>

using namespace std;

class Animal
{
  private:
    string name;
    string message;
    string noise;

  public:
    Animal();
    ~Animal();

    void setName(string name);
    string getName(void);

    void setMessage(string message);
    string getMessage(void);

    bool makeNoise(void);
};

