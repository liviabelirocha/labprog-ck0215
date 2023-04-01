#ifndef INTROSORT_CPP
#define INTROSORT_CPP

#include "./Sort.cpp"

enum InsertionSort
{
    WITHOUT,
    WITH
};

template <typename T>
class Introsort : public Sort<T>
{
private:
    InsertionSort _insertion_sort;

public:
    Introsort(int size, InsertionSort is) : Sort<T>(size)
    {
        _insertion_sort = is;
    }

    void worst_case() override {}

    bool sort() override
    {
        return true;
    }
};

#endif