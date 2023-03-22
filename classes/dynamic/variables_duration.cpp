/**
 * Durações de Armazenamento em C++
 * 1. Estática: do início ao fim do programa.
 * 2. Automática: do momento da criação ao fim do bloco mais interno.
 * 3. Dinâmica: gerenciada manualmente
 * 4. Thread
 */

#include <iostream>

using namespace std;

int static_global = 3;

int times_two(int i_automatic_local)
{
    return 2 * i_automatic_local;
}

int main()
{
    cout << "n: ";
    int n;
    cin >> n;

    cout << "2*n " << times_two(n) << '\n';
}