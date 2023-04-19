#ifndef QUICKSORT_CPP
#define QUICKSORT_CPP

#include <cstdlib>

#include "./Sort.cpp"
#include "./Generator.cpp"
#include "./Random.cpp"

using std::swap;

enum Pivot
{
    FIXED,
    RANDOM
};

template <typename T>
class Quicksort : public Sort<T>
{
private:
    T *_arr;
    Pivot _pivot;

    // void worst_case() override
    // {
    //     T *v = Generator<T>::ascending(this->get_size());
    //     this->set_vec(v);
    // }

    int get_pivot(int start, int end)
    {
        Random *random = Random::GetInstance();
        if (_pivot == Pivot::FIXED)
            return start;

        return random->get_random_from_interval(start, end - 1);
    }

    int partition(int start, int end)
    {
        int pivot_index = get_pivot(start, end);
        T pivot = _arr[pivot_index];

        int i = start;
        int j = end;

        while (true)
        {
            while (_arr[i] < pivot)
                i++;

            while (_arr[j] > pivot)
                j--;

            if (i >= j)
                return j;

            swap(_arr[i], _arr[j]);
            i++;
            j--;
        }
    }

    void quicksort(int start, int end)
    {
        if (start < end)
        {
            int pivot_index = partition(start, end);
            quicksort(start, pivot_index);
            quicksort(pivot_index + 1, end);
        }
    }

public:
    Quicksort(int size, T *v, Pivot pivot /*,  bool wc = false */) : Sort<T>(size, v)
    {
        _pivot = pivot;

        // if (wc)
        //     this->worst_case();
        _arr = new T[size];
        memcpy(_arr, this->get_vec(), size * sizeof(T));
    }

    ~Quicksort()
    {
        delete[] _arr;
    }

    void sort() override
    {
        this->quicksort(0, this->get_size() - 1);

        // cout << "quicksort" << std::endl;
        // int *end = _arr + this->get_size();
        // for (int *i = _arr; i != end; i++)
        //     cout << *i << " ";
        // cout << '\n';
    }

    T *get_ordered() override
    {
        return _arr;
    }
};

#endif