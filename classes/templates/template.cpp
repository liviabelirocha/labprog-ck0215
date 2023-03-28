#include <iostream>

using namespace std;

template <typename T>
T sum(T *v, int n)
{
    T sum = 0;

    for (T *end = v + n; v != end; v++)
        sum += *v;

    return sum;
}

int main()
{
    double vd[] = {1.2, 3.4, 5.6};
    int vi[] = {1, 2, 3, 4, 5, 6};

    cout << sum(vd, 3) << '\n'
         << sum(vi, 6) << '\n';
}