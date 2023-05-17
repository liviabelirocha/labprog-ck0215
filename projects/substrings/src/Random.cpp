#ifndef RANDOM_CPP
#define RANDOM_CPP

#include <random>

using std::mt19937, std::uniform_int_distribution, std::random_device;

class Random
{

private:
    static Random *_random;

    random_device _random_disposition;
    mt19937 _generator;

    Random() : _generator{_random_disposition()}
    {
    }

public:
    void operator=(const Random &) = delete;
    Random(Random &other) = delete;

    static Random *GetInstance()
    {
        if (_random == nullptr)
            _random = new Random();

        return _random;
    };

    int get_random_from_interval(int min, int max)
    {
        uniform_int_distribution<int> distribution(min, max);
        return distribution(_generator);
    }
};

#endif