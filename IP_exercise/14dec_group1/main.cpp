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
    const int *ptr = begin;
    const int *srch = nullptr;
    unsigned i = 0, size = s_end - s_begin;
    const int *max = end - size + 1;
    do
    {
        while (ptr != max && *ptr != *s_begin)
            ++ptr;
    } while (!equal(ptr, ptr + size, s_begin, s_end) && ++ptr < max);
    return (ptr < max ? ptr : nullptr);
}

int main()
{
    int a[] = {1, 2, 1, 3, 7, 2, 1, 9};
    int b[] = {1, 3};
    std::cout << equal(a + 2, a + 4, b, b + 2) << '\n';
    std::cout << equal(a + 6, a + 8, b, b + 2) << '\n';
    const int *search_res = search(a, a + 8, b, b + 2);
    if (search_res)
        std::cout << search_res - a << '\n';
    else
        std::cout << "Not found.\n";
    return 0;
}