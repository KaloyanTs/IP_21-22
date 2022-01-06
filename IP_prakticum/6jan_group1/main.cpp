#include <iostream>
#include <climits>

unsigned fib(unsigned n)
{
    if (!n)
        return 0;
    if (n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

void readAndPrintReverse(unsigned n)
{
    if (!n)
        return;
    int a;
    std::cin >> a;
    readAndPrintReverse(n - 1);
    std::cout << a << ' ';
}

unsigned sumOfDigits(const unsigned n)
{
    if (!n)
        return 0;
    return n % 10 + sumOfDigits(n / 10);
}

int max(const int a, const int b)
{
    return (a > b ? a : b);
}

int maxElem(const int *arr, unsigned n)
{
    if (!n)
        return INT_MIN;
    if (n == 1)
        return *arr;
    return max(*arr, maxElem(arr + 1, n - 1));
}

bool isPalindrome(const char *str, unsigned l)
{
    if (l < 2)
        return true;
    return (str[0] == str[l - 1] && isPalindrome(str + 1, l - 2));
}

unsigned IndexWithLowerElement(const int *arr, unsigned i1, unsigned i2)
{
    if (arr[i2] < arr[i1])
        return i2;
    return i1;
}

unsigned minElemIndex(const int *arr, unsigned n)
{
    if (!n)
        return -1;
    if (n == 1)
        return 0;
    return IndexWithLowerElement(arr, minElemIndex(arr, n - 1), n - 1);
}

int main()
{
    // std::cout << fib(9) << '\n';
    // readAndPrintReverse(5);
    // std::cout << sumOfDigits(3278538) << '\n';
    int arr[] = {4, 2, 6, 2, 7, 4, 3, 5};
    // std::cout << maxElem(arr, 8) << '\n';
    // std::cout << isPalindrome("racecar", 7) << '\n';
    std::cout << minElemIndex(arr, 8) << '\n';
    return 0;
}