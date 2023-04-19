#ifndef INTROSORT_CPP
#define INTROSORT_CPP

#include <cmath>

#include "./Sort.cpp"
#include "./Quicksort.cpp"
#include "./Heapsort.cpp"

using std::log, std::swap;

template <typename T>
class Introsort : public Sort<T>
{
private:
    T *_arr;
    bool _insertion_sort;
    bool _wc;
    int _limit;

    // void worst_case() override
    // {
    //     T *v = Generator<T>::ascending(this->get_size());
    //     this->set_vec(v);
    // }

    int partition(int start, int end)
    {
        T pivot = _arr[start];

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

    int left_child(int i)
    {
        return 2 * i + 1;
    }

    int right_child(int i)
    {
        return 2 * i + 2;
    }

    void build_max_heap(int start, int end)
    {
        int size = end - start + 1;

        for (int i = size / 2 - 1; i >= 0; i--)
        {
            int parent = i;
            while (this->left_child(parent) < size)
            {
                int k = this->left_child(parent);
                int right = k + 1;
                if (right < size && _arr[start + right] > _arr[start + k])
                    k++;

                if (_arr[start + k] > _arr[start + parent])
                {
                    swap(_arr[start + k], _arr[start + parent]);
                    parent = k;
                }
                else
                    break;
            }
        }
    }

    void heapsort(int start, int end)
    {
        int size = end - start + 1;

        for (int i = size - 1; i >= 1; i--)
        {
            swap(_arr[start], _arr[start + i]);
            int parent = 0;
            while (this->left_child(parent) < i)
            {
                int k = this->left_child(parent);
                int right = k + 1;
                if (right < i && _arr[start + right] > _arr[start + k])
                    k++;

                if (_arr[start + k] > _arr[start + parent])
                {
                    swap(_arr[start + k], _arr[start + parent]);
                    parent = k;
                }
                else
                    break;
            }
        }
    }

    void insertion_sort(int start, int end)
    {
        for (int i = start + 1; i < end; i++)
        {
            int key = _arr[i];
            int j = i - 1;
            while (j >= 0 && _arr[j] > key)
            {
                _arr[j + 1] = _arr[j];
                j--;
            }
            _arr[j + 1] = key;
        }
    }

    void introsort(int start, int end, int limit)
    {
        if (start < end)
        {
            if (((end - start + 1) <= 16) && _insertion_sort)
            {
                insertion_sort(start, end + 1);
                return;
            }

            if (limit == 0)
            {
                build_max_heap(start, end);
                heapsort(start, end);
                return;
            }

            int pivot_index = partition(start, end);
            introsort(start, pivot_index, limit - 1);
            introsort(pivot_index + 1, end, limit - 1);
        }
    }

public:
    Introsort(int size, T *v, bool is) : Sort<T>(size, v)
    {
        _insertion_sort = is;

        int bit_shift = size;
        int count = 0;
        while (bit_shift > 1)
        {
            bit_shift >>= 1;
            count++;
        }
        _limit = 2 * count;

        _arr = new T[size];
        memcpy(_arr, this->get_vec(), size * sizeof(T));
    }

    ~Introsort()
    {
        delete[] _arr;
    }

    void sort() override
    {
        int size = this->get_size();
        introsort(0, size - 1, _limit);

        // cout << "introsort\n";
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