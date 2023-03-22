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
};

void init(Stack10 &s)
{
    s.n = 0;
}

void stack(Stack10 &s, double x)
{
    if (s.n == 10)
        throw FullStack{};

    s.v[s.n++] = x; // n++ -> v[n] and then increment n
}

bool empty(Stack10 &s)
{
    return (s.n == 0);
}

double top(Stack10 &s)
{
    if (empty(s))
        throw EmptyStack{};

    return s.v[s.n - 1];
}

double unstack(Stack10 &s)
{
    double t = top(s);
    s.n--;
    return t;
}

int size(Stack10 &s)
{
    return s.n;
}

int main()
{
    Stack10 Stack;
    init(Stack);

    for (int i = 0; i < 10; i++)
        stack(Stack, i);

    while (!empty(Stack))
        cout << unstack(Stack) << " ";

    cout << '\n';
}