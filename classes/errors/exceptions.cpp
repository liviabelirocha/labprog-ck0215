#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Rectangle
{
    int xleft, xright, yinf, ysup;
};

struct EntryError
{
    const char *msg;
};

int read_int(const char *msg)
{
    cout << msg << ": ";

    string line;
    getline(cin, line);
    istringstream origin(line);

    int i;
    origin >> i;

    if (origin.fail())
        throw EntryError{"read_int: invalid format"};

    return i;
}

Rectangle
read_rect(const char *msg)
{
    cout << msg << '\n';

    Rectangle r;

    r.xleft = read_int("xleft");
    r.xright = read_int("xright");
    r.yinf = read_int("yinf");
    r.ysup = read_int("ysup");

    if (r.xleft >= r.xright || r.yinf >= r.ysup)
        throw EntryError{"read_rect: invalid coordinates"};

    return r;
}

int area(Rectangle r)
{
    return (r.xright - r.xleft) * (r.ysup - r.yinf);
}

int main()
{
    try
    {
        int a = area(read_rect("Type in the rectangle"));
        cout << "Area " << a << '\n';
    }
    catch (EntryError &er)
    {
        cout << "ERROR!!! " << er.msg << '\n';
    }
    catch (bad_alloc &e)
    {
        cout << "EXCEPTION!!! " << e.what() << '\n';
    }
    return 1;
}
