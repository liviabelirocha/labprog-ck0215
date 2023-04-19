#ifndef SORT_CPP
#define SORT_CPP

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <optional>
#include <chrono>

using std::srand, std::time, std::rand, std::cout;
using namespace std::chrono;

struct NotSorted
{
};

template <typename T>
class Sort
{
protected:
    // virtual void worst_case() = 0;

private:
    int _size;
    T *_vec;

public:
    virtual void sort() = 0;

    virtual T *get_ordered() = 0;

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
        auto start = steady_clock::now();
        sort();
        auto end = steady_clock::now();

        is_sorted();

        return duration<double>(end - start).count();
    }

    void is_sorted()
    {
        int size = get_size();
        T *v = get_ordered();

        for (int i = 0; i < size - 1; i++)
            if (v[i] > v[i + 1])
                throw NotSorted{};
    }
};

#endif