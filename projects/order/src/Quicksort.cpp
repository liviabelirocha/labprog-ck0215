#ifndef QUICKSORT_CPP
#define QUICKSORT_CPP

#include "./Sort.cpp"

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

    int get_pivot(int start, int end)
    {
        if (_pivot == Pivot::FIXED)
            return start + (end - start) / 2;
        return start;
    }

    int partition(int start, int end)
    {
        int pivot_index = this->get_pivot(start, end);
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
            int pivot_index = this->partition(start, end);
            this->quicksort(start, pivot_index);
            this->quicksort(pivot_index + 1, end);
        }
    }

public:
    Quicksort(int size, T *v, Pivot pivot, bool wc = false) : Sort<T>(size, v)
    {
        _pivot = pivot;

        if (wc)
            this->worst_case();
        // else
        // {
        _arr = new T[size];
        memcpy(_arr, this->get_vec(), size * sizeof(T));
        // }
    }

    ~Quicksort()
    {
        delete[] _arr;
    }

    void worst_case() override {}

    void sort() override
    {
        this->quicksort(0, this->get_size() - 1);

        // int *end = _arr + this->get_size();
        // for (int *i = _arr; i != end; i++)
        //     cout << *i << " ";
        // cout << '\n';
    }
};

#endif