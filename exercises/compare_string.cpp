#include <iostream>

using namespace std;

bool same(const char *r, const char *s)
{
    while (*r != '\0' && *s != '\0')
    {
        if (*r != *s)
            return false;
        r++;
        s++;
    }

    if (*r != '\0' || *s != '\0')
        return false;

    return true;
}

int main(int argc, char **argv)
{
    (void)argc;
    char *word1 = argv[1];
    char *word2 = argv[2];

    cout << same(word1, word2) << '\n';
}
