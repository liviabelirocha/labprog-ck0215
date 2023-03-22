#include <iostream>

using namespace std;

class Person
{
private:
    const char *name;

public:
    Person(const char *identifier) : name{identifier}
    {
        cout << "Constructing " << name << '\n';
    }

    ~Person()
    {
        cout << "Deconstructing " << name << '\n';
    }
};

int main()
{
    Person *people = new Person[3]{"Mario", "Luigi", "Peach"};
    delete[] people;
}