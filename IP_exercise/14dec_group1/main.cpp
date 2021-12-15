#include <iostream>

bool equal(const int *begin_1, const int *end_1, const int *begin_2, const int *end_2)
{
    if (end_1 - begin_1 != end_2 - begin_2)
        return false;
    while (begin_2 != end_2 && *begin_1 == *begin_2)
    {
        ++begin_1;
        ++begin_2;
    }
    return begin_2 == end_2;
}

const int *search(const int *begin, const int *end, const int *s_begin, const int *s_end)
{
    const int *srch = nullptr;
    unsigned i = 0, size = s_end - s_begin;
    const int *max = end - size;
    do
    {
        while (begin != max && *begin != *s_begin)
            ++begin;
    } while (!equal(begin, begin + size, s_begin, s_end) && ++begin <= max);
    return (begin <= max ? begin : nullptr);
}

const int *search_n(const int *begin, const int *end, unsigned count, int elem)
{
    const int *max = end - count;
    unsigned i = 0;
    do
    {
        while (begin != max && *begin != elem)
            ++begin;
        i = 0;
        while (i < count && *(begin + i) == elem)
            ++i;
    } while (i != count && ++begin <= max);
    return (begin <= max ? begin : nullptr);
}

int main()
{
    int a[] = {1, 2, 1, 3, 2, 2, 2, 9};
    int b[] = {1, 3};
    std::cout << equal(a + 2, a + 4, b, b + 2) << '\n';
    std::cout << equal(a + 6, a + 8, b, b + 2) << '\n';
    const int *search_res = search(a, a + 8, b, b + 2);
    if (search_res)
        std::cout << search_res - a << '\n';
    else
        std::cout << "Not found.\n";
    search_res = search_n(a, a + 8, 3, 2);
    std::cout << '3' << " * " << '2' << (search_n ? " found on position " : "not found.\n");
    if (search_n)
        std::cout << search_res - a << ".\n";
    return 0;
}