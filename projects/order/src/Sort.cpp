#ifndef SORT_CPP
#define SORT_CPP

#include <cstdlib>
#include <ctime>
#include <iostream>

using std::srand, std::time, std::rand, std::cout;

#define MIN_VALUE 1
#define MAX_VALUE 100

class Sort
{
private:
    int _size;
    int *_vec;

    void ascending()
    {
        int *vec = new int[_size];

        srand(time(nullptr));
        int current = MIN_VALUE,
            increment = (MAX_VALUE - MIN_VALUE) / _size;

        for (int i = 0; i < _size; i++)
        {
            vec[i] = current + rand() % increment;
            current = vec[i];
        }

        _vec = vec;
        delete[] vec;
    }

    void descending()
    {
        int *vec = new int[_size];

        srand(time(nullptr));
        int current = MAX_VALUE,
            increment = (MAX_VALUE - MIN_VALUE) / _size;

        for (int i = 0; i < _size; i++)
        {
            vec[i] = current - rand() % increment;
            current = vec[i];
        }

        _vec = vec;
        delete[] vec;
    }

    void random()
    {
        int *vec = new int[_size];

        srand(time(nullptr));

        for (int i = 0; i < _size; i++)
            vec[i] = MIN_VALUE + rand() % (MAX_VALUE - MIN_VALUE + 1);

        _vec = vec;
        delete[] vec;
    }

public:
    virtual bool sort() = 0;
    virtual void worst_case() = 0;

    int get_size()
    {
        return _size;
    }

    void set_size(int size)
    {
        _size = size;
    }
};

#endif