/**
 * se p é um ponteiro e i um inteiro,
 * então p[i] é, por definição, *(p+i)
 */

#include <iostream>

using namespace std;

int main()
{
    int v[7] = {10, 20, 30, 40, 50, 60, 70};

    int *p = &v[3];

    cout << "p[2]: " << p[2] << "\n";
    cout << "p[-3]: " << p[-3] << "\n";
}