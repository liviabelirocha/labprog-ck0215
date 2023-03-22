#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool read_int(const char *msg, int &i)
{
    cout << msg << ": ";
    string line;
    getline(cin, line);
    istringstream origin(line);
    origin >> i;
    return origin.fail();
}

struct Rectangle
{
    int xleft, xright, yinf, ysup;
};

struct RectOrError
{
    bool error;
    Rectangle rect;
};

RectOrError
read_rect(const char *msg)
{
    cout << msg << '\n';

    Rectangle r;

    if (read_int("xleft", r.xleft) || read_int("xright", r.xright) ||
        read_int("yinf", r.yinf) || read_int("ysup", r.ysup) ||
        r.xleft >= r.xright || r.yinf >= r.ysup)
        return RectOrError{true, r};

    return RectOrError{false, r};
}

int area(RectOrError re)
{
    if (re.error)
        return -1;

    Rectangle &r = re.rect;

    return (r.xright - r.xleft) * (r.ysup - r.yinf);
}

int main()
{
    int a = area(read_rect("Type in the rectangle"));

    if (a == -1)
    {
        cout << "Error reading rectangle" << '\n';
        return 0;
    }

    cout << "Area " << a << '\n';
    return 1;
}
