#include <cstdlib>
#include <optional>

#include "./Sort.cpp"
#include "./Heapsort.cpp"
#include "./Quicksort.cpp"
#include "./Introsort.cpp"
#include "./Generator.cpp"

using std::atoi, std::optional;

int main(int argc, char **argv)
{
    (void)argc;
    int size = atoi(argv[2]);

    optional<int *> v = Generator<int>::generate(size, argv[1]);

    Sort<int> *sort_types[5];

    sort_types[0] = new Heapsort<int>(size, v);
    sort_types[0]->sort();
    // sort_types[1] = new Quicksort<int>(size, Pivot::FIXED);
    // sort_types[2] = new Quicksort<int>(size, Pivot::RANDOM);
    // sort_types[3] = new Introsort<int>(size, InsertionSort::WITHOUT);
    // sort_types[4] = new Introsort<int>(size, InsertionSort::WITH);

    return 0;
}