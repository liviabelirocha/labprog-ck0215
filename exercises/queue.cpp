#include <iostream>

using namespace std;

class QueueError
{

public:
    const char *_msg;
    QueueError(const char *msg) : _msg{msg} {}
};

class Queue
{
private:
    double *_numbers;
    int _size, _amount;

public:
    Queue()
    {
        cout << "Constructing new queue...\n";
        _numbers = new double[1];
        _size = 1;
        _amount = 0;
    }

    ~Queue()
    {
        cout << "Deconstructing queue...\n";
        delete[] _numbers;
    }

    void add(double number)
    {
        if (_amount == _size)
        {
            _size *= 2;

            double *new_numbers = new double[_size];

            for (int i = 0; i < _amount; i++)
                new_numbers[i] = _numbers[i];

            delete[] _numbers;
            _numbers = new_numbers;
        }

        _numbers[_amount++] = number;
    }

    bool empty()
    {
        return _amount == 0;
    }

    double head()
    {
        return _numbers[0];
    }

    double remove()
    {
        if (this->empty())
            throw QueueError{"ERROR!!! Empty queue"};

        double elem = this->head();
        _amount--;

        for (int i = 0; i < _amount; i++)
            _numbers[i] = _numbers[i + 1];

        return elem;
    }
};

int main()
{
    try
    {
        Queue q = Queue{};

        for (int i = 0; i < 10; i++)
            q.add(i);

        while (!q.empty())
            cout << q.remove() << " ";

        cout << '\n';
    }
    catch (QueueError &e)
    {
        cout << e._msg << '\n';
    }
    catch (bad_alloc &e)
    {
        cout << "EXCEPTION!!! " << e.what() << '\n';
    }
}