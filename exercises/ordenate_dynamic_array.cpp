#include <iostream>

using namespace std;

int main()
{
    int *numbers = new int[1];
    int size = 1, amount = 0, number, temp;

    cout << "Type in integers (0 to end): ";

    while (cin >> number && number != 0)
    {
        if (amount == size)
        {
            size *= 2;
            int *new_numbers = new int[size];

            for (int i = 0; i < amount + 1; i++)
                new_numbers[i] = numbers[i];

            delete[] numbers;
            numbers = new_numbers;
        }
        numbers[amount] = number;
        amount++;
    }

    for (int i = 0; i < amount; i++)
        for (int j = i + 1; j < amount; j++)
            if (numbers[j] < numbers[i])
            {
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }

    for (int i = 0; i < amount; i++)
        cout << numbers[i] << " ";
    cout << '\n';
    delete[] numbers;

    return 0;
}