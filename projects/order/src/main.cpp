#include <cstdlib>
#include <iostream>
#include <ctime>

#include "./Sort.cpp"
#include "./Heapsort.cpp"
#include "./Quicksort.cpp"
#include "./Introsort.cpp"
#include "./Generator.cpp"
#include "./Random.cpp"

using std::atoi, std::cout, std::forward, std::time, std::fixed, std::mt19937;
using namespace std::chrono;

Random *Random::_random = nullptr;

void print_algorithm(int index, double time)
{
    switch (index)
    {
    case 0:
        cout << "Heapsort: ";
        break;
    case 1:
        cout << "Quicksort (Fixed Pivot): ";
        break;
    case 2:
        cout << "Quicksort (Random Pivot): ";
        break;
    case 3:
        cout << "Introsort (Without Insertion Sort): ";
        break;
    case 4:
        cout << "Introsort (With Insertion Sort): ";
        break;
    }

    cout << fixed << time << '\n';
}

template <typename T>
void create_sort(int size, char *instance, int no_of_instances)
{
    // bool wc = *instance == 'P';

    T **instances = new T *[no_of_instances];

    for (int i = 0; i < no_of_instances; i++)
    {
        instances[i] = Generator<T>::generate(size, instance);

        // for (int j = 0; j < size; j++)
        //     cout << instances[i][j] << ' ';
        // cout << '\n';
    }

    double count[5];
    for (int i = 0; i < 5; i++)
        count[i] = 0;

    for (int i = 0; i < no_of_instances; i++)
    {
        Sort<T> *sort_types[5];

        sort_types[0] = new Heapsort<T>(size, instances[i]);
        sort_types[1] = new Quicksort<T>(size, instances[i], Pivot::FIXED);
        sort_types[2] = new Quicksort<T>(size, instances[i], Pivot::RANDOM);
        sort_types[3] = new Introsort<T>(size, instances[i], false);
        sort_types[4] = new Introsort<T>(size, instances[i], true);

        for (int j = 0; j < 5; j++)
            count[j] += sort_types[j]->get_time();
    }

    for (int i = 0; i < 5; i++)
        print_algorithm(i, count[i]);

    delete[] instances;
}

int main(int argc, char **argv)
{
    (void)argc;

    char *instance = argv[1];
    int size = atoi(argv[2]);
    int no_of_instances = atoi(argv[3]);

    create_sort<int>(size, instance, no_of_instances);

    return 0;
}