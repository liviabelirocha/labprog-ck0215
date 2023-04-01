#ifndef QUICKSORT_CPP
#define QUICKSORT_CPP

#include "./Sort.cpp"

enum Pivot
{
    FIXED,
    RANDOM
};

template <typename T>
class Quicksort : public Sort<T>
{
private:
    Pivot _pivot;

public:
    Quicksort(int size, Pivot pivot) : Sort<T>(size)
    {
        _pivot = pivot;
    }

    void worst_case() override {}

    bool sort() override
    {
        return true;
    }
};

#endif