#ifndef GENERATOR_CPP
#define GENERATOR_CPP

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <optional>

using std::srand, std::time, std::rand, std::optional, std::nullopt, std::cout;

#define MIN_VALUE 1
#define MAX_VALUE 100

template <typename T>
class Generator
{
public:
    static optional<T *> generate(int size, char *instance)
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
            return Generator::worst_case();
        default:
            return nullopt;
        }
    }

    static T *ascending(int size)
    {
        T *vec = new T[size];

        srand(time(nullptr));
        int current = MIN_VALUE,
            increment = (MAX_VALUE - MIN_VALUE) / size;

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

        srand(time(nullptr));
        int current = MAX_VALUE,
            increment = (MAX_VALUE - MIN_VALUE) / size;

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

        srand(time(nullptr));

        for (int i = 0; i < size; i++)
            vec[i] = MIN_VALUE + rand() % (MAX_VALUE - MIN_VALUE + 1);

        return vec;
    }

    static optional<T *> worst_case()
    {
        return nullopt;
    }
};

#endif