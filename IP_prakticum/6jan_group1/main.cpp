#include <iostream>
#include <climits>

void print(const int *arr, unsigned n)
{
    for (unsigned i = 0; i < n; ++i)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
}

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

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void selectionSort(int *arr, unsigned n)
{
    if (n < 2)
        return;
    swap(arr[0], arr[minElemIndex(arr, n)]);
    selectionSort(arr + 1, n - 1);
}

void insert(int *arr, unsigned n, int val)
{
    if (!n)
    {
        arr[0] = val;
        return;
    }
    if (val < arr[0])
        swap(val, arr[0]);
    insert(arr + 1, n - 1, val);
}

void insertionSort(int *arr, unsigned n)
{
    if (n == 0)
        return;
    insert(arr, n - 1, arr[n - 1]);
    insertionSort(arr, n - 1);
}

unsigned nfib(unsigned n, unsigned k)
{
    if (!k)
        return 0;
    if (n < k)
        return 1;
    if (n == k)
        return k;
    return 2 * nfib(n - 1, k) - nfib(n - k - 1, k);
}

bool areFactors(unsigned *arr, unsigned n, unsigned num)
{
    if (!n)
        return num == 1;
    if (num % *arr == 0)
        return areFactors(arr, n, num / *arr);
    else
        return areFactors(arr + 1, n - 1, num);
}

void Task9()
{
    unsigned arr[10];
    unsigned n, num;
    std::cin >> n;
    for (unsigned i = 0; i < n; ++i)
        std::cin >> arr[i];
    std::cin >> num;
    std::cout << areFactors(arr, n, num) << '\n';
}

bool isInNum(unsigned num, unsigned digit)
{
    if (!num)
        return false;
    return num % 10 == digit || isInNum(num / 10, digit);
}

bool repeatingDigits(unsigned n)
{
    if (n < 10)
        return false;
    return isInNum(n / 10, n % 10) || repeatingDigits(n / 10);
}

unsigned biggestUniqueDigits(unsigned n)
{
    if (!repeatingDigits(n))
        return n;
    return biggestUniqueDigits(n - 1);
}

int main()
{
    unsigned num;
    // std::cout << fib(9) << '\n';
    // readAndPrintReverse(5);
    // std::cout << sumOfDigits(3278538) << '\n';
    int arr[10] = {4, 2, 6, 2, 7, 4, 3, 5};
    // std::cout << maxElem(arr, 8) << '\n';
    // std::cout << isPalindrome("racecar", 7) << '\n';
    // std::cout << minElemIndex(arr, 8) << '\n';
    // selectionSort(arr, 8);
    // insert(arr, 8, 5);
    // insertionSort(arr, 8);
    // print(arr, 8);
    // std::cout << nfib(8, 4) << '\n';
    // Task9();
    std::cin >> num;
    std::cout << biggestUniqueDigits(num) << '\n';
    return 0;
}