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

int main()
{
    int a[] = {1, 2, 1, 3};
    int b[] = {2, 1};
    std::cout << equal(a, a + 2, b, b + 2) << '\n';
    std::cout << equal(a + 1, a + 3, b, b + 2) << '\n';

    return 0;
}