#include <iostream>

bool equal(const int *begin_1, const int *end_1, const int *begin_2, const int *end_2)
{
    if (end_1 - begin_1 != end_2 - begin_2)
        return false;
    unsigned i = 0;
    while (i < end_1 - begin_1 && *(begin_1 + i) == *(begin_2 + i))
        ++i;
    return i == end_1 - begin_1;
}

const int *search(const int *begin, const int *end, const int *s_begin, const int *s_end)
{
    const int *ptr = begin;
    const int *srch = nullptr;
    unsigned i = 0, size = s_end - s_begin;
    do
    {
        while (ptr != end && *ptr != *s_begin)
            ++ptr;
        srch = ptr;
        i = 0;
        while (i < size && srch != end && *srch == *(ptr + i))
        {
            ++i;
            ++srch;
        }
        ++ptr;
    } while (i != size && ptr < end - size);
    if (i == size)
        return ptr - 1;
    return nullptr;
}

int main()
{
    int a[] = {1, 2, 1, 3};
    int b[] = {1,3};
    std::cout << equal(a, a + 2, b, b + 2) << '\n';
    std::cout << equal(a + 2, a + 4, b, b + 2) << '\n';
    const int *search_res = search(a, a + 4, b, b + 2);
    if (search_res)
        std::cout << search_res - a << '\n';
    else
        std::cout << "Not found.\n";
    return 0;
}