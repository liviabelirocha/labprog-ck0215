#include <cstdlib>
#include <chrono>
#include <iostream>
#include <cstring>

#include "./instancias_Reais_Trabalho_2.hpp"
#include "./Random.cpp"

using std::atoi, std::time, std::cout, std::fixed, std::strlen;
using namespace std::chrono;

Random *Random::_random = nullptr;

typedef void (*pattern_recognition)(const char *, const char *, int *);

void brute_force(const char *pattern, const char *text, int *ocurrences)
{
    int text_idx = 0, pattern_ocurrences_idx = 0;

    while (text[text_idx] != '\0')
    {
        int pattern_idx = 0;
        while (pattern[pattern_idx] != '\0' && text[text_idx + pattern_idx] == pattern[pattern_idx])
            pattern_idx++;

        if (pattern[pattern_idx] == '\0')
        {
            ocurrences[pattern_ocurrences_idx] = text_idx;
            pattern_ocurrences_idx++;
        }
        text_idx++;
    }

    ocurrences[pattern_ocurrences_idx] = -1;
}

void generate_A(const char *pattern, int *A)
{
    A[0] = 0;

    int j = 1, i = 0;

    while (pattern[j] != '\0')
    {
        if (pattern[j] == pattern[i])
        {
            i++;
            A[j] = i;
            j++;
        }
        else
        {
            if (i != 0)
                i = A[i - 1];
            else
            {
                A[j] = 0;
                j++;
            }
        }
    }
}

void knuth_morris_pratt(const char *pattern, const char *text, int *ocurrences)
{
    int pattern_length = strlen(pattern), pattern_idx = 0, text_idx = 0, pattern_ocurrences_idx = 0;

    int *A = new int[pattern_length];
    generate_A(pattern, A);

    while (text[text_idx] != '\0')
    {
        if (pattern[pattern_idx] == text[text_idx])
        {
            pattern_idx++;
            text_idx++;
        }

        if (pattern[pattern_idx] == '\0')
        {
            ocurrences[pattern_ocurrences_idx] = text_idx - pattern_idx;
            pattern_ocurrences_idx++;
            pattern_idx = A[pattern_idx - 1];
        }
        else if (text[text_idx] != '\0' && pattern[pattern_idx] != text[text_idx])
        {
            if (pattern_idx != 0)
                pattern_idx = A[pattern_idx - 1];
            else
                text_idx++;
        }
    }

    ocurrences[pattern_ocurrences_idx] = -1;
    delete[] A;
}

char *generate_random_word(Random &random, char letter, int size)
{
    char *word = new char[size];
    for (int i = 0; i < size; i++)
    {
        char random_letter = random.get_random_from_interval('a', letter);
        word[i] = random_letter;
    }

    return word;
}

double measure_time(pattern_recognition function, const char *pattern, const char *text, int *ocurrences)
{
    auto start = steady_clock::now();
    function(pattern, text, ocurrences);
    auto end = steady_clock::now();
    return duration<double>(end - start).count();
}

int main(int argc, char **argv)
{
    (void)argc;

    Random *random = Random::GetInstance();

    char *instance_type = argv[1]; // A or R;

    double brute_force_duration = 0, knuth_morris_pratt_duration = 0;

    if (*instance_type == 'A')
    {
        char *letter = argv[2];
        int size = atoi(argv[3]);
        int text_size = atoi(argv[4]);
        int no_of_instances = atoi(argv[5]);

        int *ocurrences = new int[text_size + 1];

        for (int i = 0; i < no_of_instances; i++)
        {
            char *text = generate_random_word(*random, *letter, text_size);
            char *pattern = generate_random_word(*random, *letter, size);

            brute_force_duration += measure_time(brute_force, pattern, text, ocurrences);
            knuth_morris_pratt_duration += measure_time(knuth_morris_pratt, pattern, text, ocurrences);

            delete[] text;
            delete[] pattern;
        }

        delete[] ocurrences;
    }

    else if (*instance_type == 'R')
    {
        int x = atoi(argv[2]);
        int y = atoi(argv[3]);

        int size = y - x + 1;

        int *ocurrences = new int[size + 1];

        for (int i = x; i <= y; i++)
        {
            brute_force_duration += measure_time(brute_force, Padroes_Palavras[i], Texto_Livros, ocurrences);
            knuth_morris_pratt_duration += measure_time(knuth_morris_pratt, Padroes_Palavras[i], Texto_Livros, ocurrences);
        }

        delete[] ocurrences;
    }

    cout << "Brute Force: " << fixed << brute_force_duration << '\n'
         << "Knuth Morris Pratt: " << fixed << knuth_morris_pratt_duration << '\n';

    return 0;
}