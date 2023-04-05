#include <cstdlib>
#include <iostream>
#include <ctime>
#include <chrono>

#include "./Sort.cpp"
#include "./Heapsort.cpp"
#include "./Quicksort.cpp"
#include "./Introsort.cpp"
#include "./Generator.cpp"

using std::atoi, std::cout, std::forward, std::srand, std::time, std::fixed;
using namespace std::chrono;

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
        cout << "Introsort (With Insertion Sort): ";
        break;
    case 4:
        cout << "Introsort (Without Insertion Sort): ";
        break;
    }

    cout << fixed << time << '\n';
}

template <typename T>
void create_sort(int size, char *instance, int no_of_instances)
{
    bool wc = *instance == 'P';

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
        sort_types[1] = new Quicksort<T>(size, instances[i], Pivot::FIXED, wc);
        // sort_types[2] = new Quicksort<int>(size, Pivot::RANDOM);
        // sort_types[3] = new Introsort<int>(size, InsertionSort::WITHOUT);
        // sort_types[4] = new Introsort<int>(size, InsertionSort::WITH);
        for (int j = 0; j < 2; j++)
        {
            count[j] += sort_types[j]->get_time();
            delete[] sort_types[j];
        }
    }

    for (int i = 0; i < 2; i++)
        print_algorithm(i, count[i]);
}

int main(int argc, char **argv)
{
    srand((unsigned)time(NULL));

    (void)argc;

    char *instance = argv[1];
    int size = atoi(argv[2]);
    int no_of_instances = atoi(argv[3]);

    create_sort<int>(size, instance, no_of_instances);

    return 0;
}