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

int **allocMatrixSum(int *arr, unsigned N, unsigned n)
{
    int **M = new (std::nothrow) int *[n + 1];
    if (!M)
        return nullptr;
    for (unsigned i = 0; i <= n; ++i)
    {
        M[i] = new (std::nothrow) int[countThisSum(arr, N, i) + 1];
        // M[i] = new (std::nothrow) int[<всички числа> + 1];
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
        return;
    }
    unsigned maxS = maxSum(arr, N);
    int **sums = allocMatrixSum(arr, N, maxS);
    if (!sums)
    {
        std::cout << "Not enough memory!\n";
        return;
    }
    fillSums(sums, maxS, arr, N);
    printSums(sums, maxS);
    deallocArr(arr);
    deallocMatrix(sums, maxS + 1);
}

void deallocEquations(int **&eq, unsigned N)
{
    for (unsigned i = 0; i < N; ++i)
        delete[] eq[i];
    delete[] eq;
    eq = nullptr;
}

int **allocEquations(unsigned N)
{
    int **eq = new (std::nothrow) int *[N];
    if (!eq)
        return nullptr;
    for (unsigned i = 0; i < N; ++i)
    {
        eq[i] = new (std::nothrow) int[4];
        // eq[i]=0 when no root found
        // eq[i]!=0 when found a root
        if (!eq[i])
        {
            deallocEquations(eq, i);
            return nullptr;
        }
        eq[i][0] = 0;
        std::cin >> eq[i][1] >> eq[i][2] >> eq[i][3];
    }
    return eq;
}

void calc(int *eq, int arg)
{
    eq[0] = (eq[1] * arg * arg + eq[2] * arg + eq[3] == 0);
}

void tryForRoots(int **eq, unsigned N, int *arg, unsigned K)
{
    for (unsigned i = 0; i < N; ++i)
    {
        unsigned j = 0;
        while (j < K && !eq[i][0])
            calc(eq[i], arg[j++]);
    }
}

void printEquations(int **eq, unsigned N)
{
    for (unsigned i = 0; i < N; ++i)
        if (eq[i][0])
        {
            for (unsigned j = 1; j <= 3; ++j)
                std::cout << eq[i][j] << ' ';
            std::cout << '\n';
        }
}

int *readArguments(unsigned K)
{
    int *arg = new (std::nothrow) int[K];
    if (!arg)
        return nullptr;
    for (unsigned i = 0; i < K; ++i)
        std::cin >> arg[i];
    return arg;
}

void Task2()
{
    unsigned N;
    std::cin >> N;
    int **eq = allocEquations(N);
    if (!eq)
    {
        std::cout << "Not enough memory!\n";
        return;
    }
    unsigned K;
    std::cin >> K;
    int *arguments = readArguments(K);
    if (!arguments)
    {
        deallocEquations(eq, N);
        std::cout << "Not enough memory!\n";
        return;
    }
    tryForRoots(eq, N, arguments, K);
    printEquations(eq, N);

    deallocEquations(eq, N);
    delete[] arguments;
}

int main()
{
    // Task1a();
    // Task1b();
    Task2();
    return 0;
}