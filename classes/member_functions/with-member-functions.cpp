#include <iostream>

using namespace std;

struct FullStack
{
};

struct EmptyStack
{
};

struct Stack10
{
    double v[10];

    int n;

    void init()
    {
        n = 0;
    }

    void stack(double x)
    {
        if (n == 10)
            throw FullStack{};

        v[n++] = x; // n++ -> v[n] and then increment n
    }

    bool empty()
    {
        return n == 0;
    }

    double top()
    {
        if (empty())
            throw EmptyStack{};

        return v[n - 1];
    }

    double unstack()
    {
        double t = top();
        n--;
        return t;
    }

    int size()
    {
        return n;
    }
};

int main()
{
    Stack10 Stack;
    Stack.init();

    for (int i = 0; i < 10; i++)
        Stack.stack(i);

    while (!Stack.empty())
        cout << Stack.unstack() << " ";

    cout << '\n';
}