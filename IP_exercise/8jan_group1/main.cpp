#include <iostream>
#include <cstring>
#include <cassert>
#include <cmath>
const unsigned MAX_COLUMNS = 3;

const char *findLast(const char *first, const char *last, char c)
{
    do
    {
        --last;
    } while (last >= first && *last != c);
    return (last < first ? nullptr : last);
}

void printWord(const char *first, const char *last)
{
    while (first != last)
        std::cout << *first++;
    std::cout << ' ';
}

char *copy(const char *inputFirst, const char *inputLast, char *output)
{
    while (inputFirst != inputLast)
        *output++ = *inputFirst++;
    return output;
}

char *reverseWords(const char *str)
{
    unsigned l = strlen(str);
    char *buf = new (std::nothrow) char[l + 1];
    if (!buf)
        return nullptr;
    char *buf_output = buf;
    const char *end = str + l;
    const char *lastSpace = nullptr;
    do
    {
        lastSpace = findLast(str, end, ' ');
        if (lastSpace)
        {
            buf_output = copy(lastSpace + 1, end, buf_output);
            *buf_output++ = ' ';
            end = lastSpace;
        }
    } while (lastSpace);
    buf_output = copy(str, end, buf_output);
    *buf_output = '\0';
    return buf;
}

void Task1()
{
    char *rev = reverseWords("I am very normal");
    std::cout << rev << '\n';
    delete[] rev;
}

double arrAverage(const int *m, unsigned n)
{
    double avg = 0;
    for (unsigned i = 0; i < n; ++i)
        avg += (double)m[i];
    return (n ? avg / n : n);
}

const double *averages(const int m[][MAX_COLUMNS], unsigned rows)
{
    double *avg = new (std::nothrow) double[rows];
    if (!avg)
        return nullptr;
    for (unsigned i = 0; i < rows; ++i)
        avg[i] = arrAverage(m[i], MAX_COLUMNS);
    return avg;
}

void printArr(const double *arr, unsigned n)
{
    for (unsigned i = 0; i < n; ++i)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
}

void Task2()
{
    int m[][MAX_COLUMNS] = {
        {
            1,
            1,
            1,
        },
        {
            1,
            2,
            3,
        },
        {
            1,
            10,
            20,
        },
    };
    const double *avg = averages(m, 3);
    printArr(avg, 3);
    delete[] avg;
}

unsigned countDigits(unsigned n, unsigned base)
{
    unsigned cD = 0;
    while (n)
    {
        n /= base;
        ++cD;
    }
    return cD;
}

const char *toString(unsigned n, unsigned base)
{
    assert(base > 1 && base <= 10);
    unsigned nDigits = countDigits(n, base);
    char *res = new (std::nothrow) char[nDigits + 1];
    res[nDigits] = '\0';
    if (!res)
        return nullptr;
    unsigned i = 0;
    while (n)
    {
        res[--nDigits] = n % base + '0';
        n /= base;
    }
    return res;
}

void Task3()
{
    const char *num = toString(2875432, 8);
    std::cout << num << '\n';
    delete[] num;
    num = toString(123456789, 10);
    std::cout << num << '\n';
    delete[] num;
}

int main()
{
    Task1();
    // Task2();
    // Task3();
    return 0;
}