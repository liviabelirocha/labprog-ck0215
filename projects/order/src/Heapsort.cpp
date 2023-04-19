#ifndef HEAPSORT_CPP
#define HEAPSORT_CPP

#include <iostream>
#include <optional>
#include <cstring>

#include "./Sort.cpp"
#include "./Generator.cpp"

using std::cout, std::swap, std::memcpy;

template <typename T>
class Heapsort : public Sort<T>
{
private:
    T *_heap;

    // void worst_case() override
    // {
    //     T *v = Generator<T>::ascending(this->get_size());
    //     this->set_vec(v);
    // }

    int left_child(int i)
    {
        return 2 * i + 1;
    }

    int right_child(int i)
    {
        return 2 * i + 2;
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    void build_max_heap()
    {
        int size = this->get_size();

        for (int i = size / 2 - 1; i >= 0; i--)
        {
            int parent = i;
            while (this->left_child(parent) < size)
            {
                int k = this->left_child(parent);
                int right = k + 1;
                if (right < size && _heap[right] > _heap[k])
                    k++;

                if (_heap[k] > _heap[parent])
                {
                    swap(_heap[k], _heap[parent]);
                    parent = k;
                }
                else
                    break;
            }
        }
    }

    void heapsort()
    {
        for (int i = this->get_size() - 1; i >= 1; i--)
        {
            swap(_heap[0], _heap[i]);
            int parent = 0;
            while (this->left_child(parent) < i)
            {
                int k = this->left_child(parent);
                int right = k + 1;
                if (right < i && _heap[right] > _heap[k])
                    k++;

                if (_heap[k] > _heap[parent])
                {
                    swap(_heap[k], _heap[parent]);
                    parent = k;
                }
                else
                    break;
            }
        }
    }

public:
    Heapsort(int size, T *v) : Sort<T>(size, v)
    {
        _heap = new T[size];
        memcpy(_heap, this->get_vec(), size * sizeof(T));
    }

    ~Heapsort()
    {
        delete[] _heap;
    }

    void sort() override
    {
        build_max_heap();
        heapsort();

        // cout << "heapsort" << std::endl;
        // int *end = _heap + this->get_size();
        // for (int *i = _heap; i != end; i++)
        //     cout << *i << " ";
        // cout << '\n';
    }

    T *get_ordered() override
    {
        return _heap;
    }
};

#endif