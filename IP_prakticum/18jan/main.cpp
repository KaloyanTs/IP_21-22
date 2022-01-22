#include <iostream>

int lastPos(const int *arr, unsigned n, int val)
{
    unsigned i = n - 1;
    while (i < n && arr[i] != val)
        --i;
    return (i < n ? i : -1);
}

void insertAdd(int *arr, unsigned &n, unsigned pos, int val)
{
    for (unsigned j = n; j >= pos; --j)
        arr[j + 1] = arr[j];
    ++n;
    arr[pos] = val;
}

void insertOddSum(int *arr, unsigned &n)
{
    unsigned i = 0;
    int oddSum = 0;
    while (i < n)
    {
        if (arr[i] % 2)
            oddSum += arr[i];
        else
            insertAdd(arr, n, ++i, oddSum);
        ++i;
    }
}

void print(int *arr, unsigned n)
{
    for (unsigned i = 0; i < n; ++i)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
}

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void selectionSort(int *arr, unsigned n)
{
    unsigned iMax{0};
    for (unsigned i = 0; i < n - 1; ++i)
    {
        iMax = i;
        for (unsigned j = i + 1; j < n; ++j)
            if (arr[j] > arr[iMax])
                iMax = j;
        swap(arr[i], arr[iMax]);
    }
}

bool searchSum(int *arr, unsigned n, int val)
{
    selectionSort(arr, n);
    unsigned i = 0, j = n - 1;
    while (i < j && arr[i] + arr[j] != val)
        if (arr[i] + arr[j] > val)
            ++i;
        else
            --j;
    return i < j;
}

unsigned frequency(const int *arr, unsigned n, int num)
{
    unsigned freq{0};
    for (unsigned i = 0; i < n; ++i)
        freq += (arr[i] == num);
    return freq;
}

void selectionSortFreq(int *arr, unsigned n)
{
    int *freq = new (std::nothrow) int[n];
    if (!freq)
        return;
    for (unsigned i = 0; i < n; ++i)
        freq[i] = frequency(arr, n, arr[i]);
    unsigned iMax{0};
    for (unsigned i = 0; i < n - 1; ++i)
    {
        iMax = i;
        for (unsigned j = i + 1; j < n; ++j)
            if (freq[j] > freq[iMax])
                iMax = j;
        swap(arr[i], arr[iMax]);
        swap(freq[i], freq[iMax]);
    }
    delete[] freq;
}

void guessTask()
{
    unsigned begin, end, guess{0};
    unsigned reply{2};
    std::cout << "Enter bounds for your number:\n";
    std::cin >> begin >> end;
    guess = begin + 1;
    std::cout << "Enter:\n\t0 if it is your number;\n\t1 if the guess is bigger;\n\t2 if the guess is lower.\n";
    do
    {
        if (reply == 1)
            end = guess - 1;
        else
            begin = guess + 1;
        guess = (begin + end) / 2;
        std::cout << "Is it " << guess << "?\n";
        std::cin >> reply;

    } while (reply);
    std::cout << "Guessed your number!\n";
}

bool searchLeastCmp(int *arr, unsigned n, int val)
{
    selectionSort(arr, n);
    do
    {
        n /= 2;
        if (arr[n] == val)
            return true;
        if (arr[n] > val)
            arr += n + 1;
    } while (n);
    return false;
}

bool binarySearch(int *arr, unsigned n, int val)
{
    if (!n)
        return false;
    if (n == 1)
        return *arr == val;
    bool even = !(n % 2);
    n /= 2;
    if (arr[n] > val)
        return binarySearch(arr + n + 1, n - even, val);
    return binarySearch(arr, n, val);
}

int main()
{
    int arr[10] = {1, 4, 3, 2, 5};
    unsigned size = 5;
    std::cout << lastPos(arr, size, 4) << '\n';
    std::cout << lastPos(arr, size, 6) << '\n';
    insertOddSum(arr, size);
    print(arr, size);
    selectionSort(arr, size);
    print(arr, size);
    std::cout << std::boolalpha << searchSum(arr + 1, size - 1, 9) << '\n';
    selectionSortFreq(arr, size);
    print(arr, size);
    // guessTask();
    std::cout << searchLeastCmp(arr, size, -1) << '\n';
    std::cout << binarySearch(arr, size, 2) << '\n';
    return 0;
}