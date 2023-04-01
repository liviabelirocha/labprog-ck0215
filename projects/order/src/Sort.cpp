#ifndef SORT_CPP
#define SORT_CPP

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <optional>

using std::srand, std::time, std::rand, std::cout, std::optional;

#define MIN_VALUE 1
#define MAX_VALUE 100

template <typename T>
class Sort
{
protected:
    virtual void worst_case() = 0;

private:
    int _size;
    T *_vec;

public:
    virtual bool sort() = 0;

    explicit Sort(int size, optional<T *> vec)
    {
        _size = size;

        if (vec.has_value())
            _vec = vec.value();
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
};

#endif