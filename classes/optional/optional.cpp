#include <iostream>
#include <optional>

using namespace std;

int main()
{
    optional<double> opt{};

    cout << "has_value: " << opt.has_value() << '\n';

    opt = 3.14;

    cout << "has_value: " << opt.has_value() << '\n';
    cout << "value: " << opt.value() << '\n';
}