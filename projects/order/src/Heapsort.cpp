#ifndef HEAPSORT_CPP
#define HEAPSORT_CPP

#include "./Sort.cpp"

class Heapsort : public Sort
{
public:
    Heapsort(int size)
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