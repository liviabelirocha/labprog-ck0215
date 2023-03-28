#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct AccessToUndefinedValue
{
};

template <typename T>
class ValueOrError
{
private:
    bool error;
    T value;

public:
    ValueOrError(T val) : error(false), value(val) {}

    ValueOrError() : error(true) {}

    void setValue(T val)
    {
        error = false;
        value = val;
    }

    void setError()
    {
        error = true;
    }

    bool isError()
    {
        return error;
    }

    T getValue()
    {
        if (error)
            throw AccessToUndefinedValue{};

        return value;
    }
};

ValueOrError<int> read_int(const char *s)
{
    cout << s;

    string line;
    int i;

    getline(cin, line);
    istringstream origin(line);
    origin >> i;

    if (origin.fail())
        return ValueOrError<int>{};

    return ValueOrError<int>{i};
}

int main()
{
    auto res = read_int("Type in an int: ");

    if (res.isError())
        cout << "Error reading \n";
    else
        cout << "You typed in: " << res.getValue() << '\n';
}