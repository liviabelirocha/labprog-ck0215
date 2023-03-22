#include <iostream>

using namespace std;

struct FullStack
{
};

struct EmptyStack
{
};

struct Stack
{
    int n;
    double *v;

    Stack(int max_size)
    {
        v = new double[max_size];
        n = 0;
    }

    ~Stack() // destructor
    {
        delete[] v;
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
    try
    {
        Stack Stack(10);

        for (int i = 0; i < 10; i++)
            Stack.stack(i);

        while (!Stack.empty())
            cout << Stack.unstack() << " ";

        cout << '\n';
    }
    catch (const bad_alloc &e)
    {
        cout << "EXCEPTION!!! " << e.what() << '\n';
    }
}