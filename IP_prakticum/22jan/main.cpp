#include <iostream>

unsigned absVal(int n)
{
    return (unsigned)(n < 0 ? -n : n);
}

unsigned digitSum(int n)
{
    if (!n)
        return 0;
    return absVal(n % 10) + digitSum(n / 10);
}

void Task1a()
{
    std::cout << digitSum(-23) << '\n';
}

void deallocArr(int *&arr)
{
    delete[] arr;
    arr = nullptr;
}

int *allocArr(unsigned n)
{
    int *arr = new (std::nothrow) int[n];
    if (!arr)
        return nullptr;
    for (unsigned i = 0; i < n; ++i)
        std::cin >> arr[i];
    return arr;
}

unsigned max(unsigned a, unsigned b)
{
    return (a < b ? b : a);
}

unsigned maxSum(int *arr, unsigned n)
{
    unsigned maxS{0};
    for (unsigned i = 0; i < n; ++i)
        maxS = max(maxS, digitSum(arr[i]));
    return maxS;
}

void deallocMatrix(int **&m, unsigned n)
{
    for (unsigned i = 0; i < n; ++i)
        delete[] m[i];
    delete[] m;
    m = nullptr;
}

unsigned countThisSum(int *arr, unsigned N, unsigned s)
{
    unsigned res{0};
    for (unsigned i = 0; i < N; ++i)
        res += (digitSum(arr[i]) == s);
    return res;
}

int **allocMatrixSum(int *arr, unsigned N, unsigned n, unsigned m)
{
    int **M = new (std::nothrow) int *[n + 1];
    if (!M)
        return nullptr;
    for (unsigned i = 0; i <= n; ++i)
    {
        M[i] = new (std::nothrow) int[countThisSum(arr, N, i) + 1];
        if (!M[i])
        {
            deallocMatrix(M, i);
            return nullptr;
        }
        M[i][0] = 0;
    }
    return M;
}

void fillSums(int **sums, unsigned sumCount, int *arr, unsigned N)
{
    unsigned currSum{0};
    for (unsigned i = 0; i < N; ++i)
    {
        currSum = digitSum(arr[i]);
        sums[currSum][++sums[currSum][0]] = arr[i];
    }
}

void printSums(int **sums, unsigned sumCount)
{
    for (unsigned i = 0; i <= sumCount; ++i)
    {
        std::cout << i << ": ";
        for (unsigned j = 1; j <= sums[i][0]; ++j)
            std::cout << sums[i][j] << ' ';
        std::cout << '\n';
    }
}

void Task1b()
{
    unsigned N;
    std::cin >> N;
    int *arr = allocArr(N);
    if (!arr)
    {
        std::cout << "Not enough memory!\n";
        return 0;
    }
    unsigned maxS = maxSum(arr, N);
    int **sums = allocMatrixSum(arr, N, maxS, N);
    if (!sums)
    {
        std::cout << "Not enough memory!\n";
        return 0;
    }
    fillSums(sums, maxS, arr, N);
    printSums(sums, maxS);
    deallocArr(arr);
    deallocMatrix(sums, maxS + 1);
}

int main()
{
    // Task1a();
    Task1b();
    return 0;
}