#include <iostream>
#include <vector>

using namespace std;

#define ARRAY_SIZE 5

int main()
{
    int numbers[ARRAY_SIZE];
    int temp;

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        cout << "Number " << i << ": ";
        cin >> numbers[i];
    }

    for (int i = 0; i < ARRAY_SIZE; i++)
        for (int j = i + 1; j < ARRAY_SIZE; j++)
            if (numbers[j] < numbers[i])
            {
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }

    for (int i = 0; i < ARRAY_SIZE; i++)
        cout << numbers[i] << " ";
}