#include <cstdlib>

#include "./Sort.cpp"
#include "./Heapsort.cpp"
#include "./Quicksort.cpp"
#include "./Introsort.cpp"

using std::atoi;

int main(int argc, char **argv)
{
    (void)argc;
    char *instance = argv[1];
    int size = atoi(argv[2]);

    Sort *sort_types[5];

    sort_types[0] = new Heapsort(size);
    sort_types[1] = new Quicksort(size, Pivot::FIXED);
    sort_types[2] = new Quicksort(size, Pivot::RANDOM);
    sort_types[3] = new Introsort(size, InsertionSort::WITHOUT);
    sort_types[4] = new Introsort(size, InsertionSort::WITH);
}