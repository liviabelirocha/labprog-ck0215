#include <iostream>
#include <optional>

using namespace std;

optional<int> read_age()
{
    int age;
    cout << "Type in your age: ";
    cin >> age;

    if (cin.fail() or age < 0)
        return {};
    else
        return {age};
}

int main()
{
    optional<int> resp = read_age();

    if (resp.has_value())
        cout << "Your age is: " << resp.value() << '\n';
    else
        cout << "Error reading age\n";
}