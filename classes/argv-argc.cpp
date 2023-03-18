#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    cout << "A chamada foi:";

    for (int i = 0; i < argc; i++)
        cout << ' ' << argv[i];

    cout << " | teve " << argc << " parâmetros \n";
}
