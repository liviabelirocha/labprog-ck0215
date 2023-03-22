#include <iostream>

using namespace std;

void switcher(int &a, int &b)
{
    int a_copy = a;
    a = b;
    b = a_copy;
}

int main()
{
    int i = 3;
    int &ri = i;
    cout << "ri: " << ri << "\n";
    ri = 7;
    cout << "i: " << i << "\n";

    int j = 5;

    cout << "j: " << j << "\n";

    switcher(i, j);

    cout << "i: " << i
         << " j: " << j << "\n";
}