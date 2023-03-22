#include <iostream>

using namespace std;

int main()
{
    int v[7] = {10, 20, 30, 40, 50, 60, 70};

    int *end = v + 7;

    for (int *p = v; p != end; p++)
        cout << *p << "\n";
}
