#include <iostream>

using namespace std;

struct dot_r2
{
    double x, y;
};

int main()
{
    try
    {
        auto *p = new dot_r2;

        p->x = 1, p->y = 2;

        cout << "p->x: " << p->x << "; p->y: " << p->y << '\n';

        delete p;
    }
    catch (const bad_alloc &e)
    {
        cout << "EXCEPTION!!! " << e.what() << '\n';
    }
}
