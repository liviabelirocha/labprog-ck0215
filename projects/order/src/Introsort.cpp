#ifndef INTROSORT_CPP
#define INTROSORT_CPP

#include "./Sort.cpp"

enum InsertionSort
{
    WITHOUT,
    WITH
};

class Introsort : public Sort
{
private:
    InsertionSort _insertion_sort;

public:
    Introsort(int size, InsertionSort is) : _insertion_sort(is)
    {
        this->set_size(size);
    }

    void worst_case() override {}

    bool sort() override
    {
        return true;
    }
};

#endif