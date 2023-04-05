#ifndef SORT_CPP
#define SORT_CPP

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <optional>
#include <chrono>

using std::srand, std::time, std::rand, std::cout;
using namespace std::chrono;

template <typename T>
class Sort
{
protected:
    virtual void worst_case() = 0;

private:
    int _size;
    T *_vec;

public:
    virtual void sort() = 0;

    explicit Sort(int size, T *vec)
    {
        _size = size;
        _vec = vec;
    }

    int get_size()
    {
        return _size;
    }

    T *get_vec()
    {
        return _vec;
    }

    void set_vec(T *vec)
    {
        _vec = vec;
    }

    double get_time()
    {
        auto start = high_resolution_clock::now();
        this->sort();
        auto end = high_resolution_clock::now();

        return duration_cast<duration<double>>(end - start).count();
    }
};

#endif