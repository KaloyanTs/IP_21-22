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
        while (begin <= max && *begin != elem)
            ++begin;
        i = 0;
        if (begin <= max)
            while (i < count && *(begin + i) == elem)
                ++i;
    } while (i != count && ++begin <= max);
    return (begin <= max ? begin : nullptr);
}

const int *adjacent_find(const int *begin, const int *end)
{
    while (begin < end - 1 && *(begin) != *(begin + 1))
        ++begin;
    return (begin < end - 1 ? begin : nullptr);
}

const int *find_end(const int *begin, const int *end, const int *s_begin, const int *s_end)
{
    unsigned size = s_end - s_begin;
    const int *srch = end - size;
    while (srch >= begin && !equal(srch, srch + size, s_begin, s_end))
        --srch;
    return (srch >= begin ? srch : nullptr);
}

int main()
{
    int a[] = {1, 2, 1, 3, 3, 1, 3, 2};
    int b[] = {1, 3};
    std::cout << equal(a + 2, a + 4, b, b + 2) << '\n';
    std::cout << equal(a + 6, a + 8, b, b + 2) << '\n';
    const int *search_res = search(a, a + 8, b, b + 2);
    if (search_res)
        std::cout << search_res - a << '\n';
    else
        std::cout << "Not found.\n";
    search_res = search_n(a, a + 8, 3, 2);
    std::cout << '3' << " * " << '2' << (search_res ? " found on position " : " not found.\n");
    if (search_res)
        std::cout << search_res - a << ".\n";
    search_res = adjacent_find(a, a + 8);
    if (search_res)
        std::cout << *search_res << " repeating on position " << search_res - a << '\n';
    else
        std::cout << "No consecutive repeating elements.\n";
    search_res = find_end(a, a + 8, b, b + 2);
    if (search_n)
        std::cout << "Last occurence is on position " << search_res - a << '\n';
    else
        std::cout << "No occurences.\n";
    return 0;
}