#ifndef GENERATOR_CPP
#define GENERATOR_CPP

#include <cstdlib>
#include <iostream>

using std::rand;

#define MIN_VALUE 1

template <typename T>
class Generator
{
private:
    static T get_max(int size)
    {
        return size * 2 + 1;
    }

public:
    static T *generate(int size, char *instance)
    {
        switch (*instance)
        {
        case 'A':
            return Generator::random(size);

        case 'C':
            return Generator::ascending(size);

        case 'D':
            return Generator::descending(size);

        case 'P':
            return Generator::ascending(size);

        default:
            return Generator::ascending(size);
        }
    }

    static T *ascending(int size)
    {
        T *vec = new T[size];

        T current = MIN_VALUE,
          increment = (Generator::get_max(size) - MIN_VALUE) / size;

        for (int i = 0; i < size; i++)
        {
            vec[i] = current + rand() % increment;
            current = vec[i];
        }

        return vec;
    }

    static T *descending(int size)
    {
        T *vec = new T[size];

        T current = Generator::get_max(size),
          increment = (Generator::get_max(size) - MIN_VALUE) / T(size);

        for (int i = 0; i < size; i++)
        {
            vec[i] = current - rand() % increment;
            current = vec[i];
        }

        return vec;
    }

    static T *random(int size)
    {
        T *vec = new T[size];

        for (int i = 0; i < size; i++)
            vec[i] = MIN_VALUE + rand() % (Generator::get_max(size) - MIN_VALUE + 1);

        return vec;
    }
};

#endif