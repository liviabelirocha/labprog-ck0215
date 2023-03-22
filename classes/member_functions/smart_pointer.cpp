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

class SmartPointer
{
private:
    Person *_p;

public:
    SmartPointer(Person *p) : _p{p} {};

    ~SmartPointer() { delete _p; }

    Person *get() { return _p; }
};

int main()
{
    try
    {
        SmartPointer sp{new Person{"Cuida"}};

        Person *p = new Person{"Naive"};

        throw 1;

        delete p;
    }
    catch (...)
    {
        cout << "Something happened...\n";
    }
}