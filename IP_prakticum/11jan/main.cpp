#include <iostream>

unsigned strlenRec(const char *str)
{
    if (!*str)
        return 0;
    return 1 + strlen(str + 1);
}

bool binarySearch(const int *begin, const int *end, int val)
{
    if (begin == end)
        return *begin == val;
    const int *mid = begin + (end - begin) / 2;
    if (*mid == val)
        return true;
    if (*mid > val)
        return binarySearch(begin, mid, val);
    return binarySearch(mid + 1, end, val);
}

int main()
{
    int arr[] = {1, 3, 4, 4, 5, 6, 6, 6, 7, 8, 9, 11, 14};
    std::cout << binarySearch(arr, arr + sizeof(arr) / sizeof(int), 3) << '\n';
    return 0;
}