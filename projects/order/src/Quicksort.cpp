#ifndef QUICKSORT_CPP
#define QUICKSORT_CPP

#include "./Sort.cpp"

enum Pivot
{
    FIXED,
    RANDOM
};

class Quicksort : public Sort
{
private:
    Pivot _pivot;

public:
    Quicksort(int size, Pivot pivot) : _pivot(pivot)
    {
        this->set_size(size);
    }

    void worst_case() {}

    bool sort() override
    {
        return true;
    }
};

#endif