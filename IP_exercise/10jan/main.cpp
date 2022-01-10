#include <iostream>
#include <cstring>

void deallocMatrix(int **&arr, unsigned n)
{
    for (unsigned i = 0; i < n; ++i)
        delete[] arr[i];
    delete arr;
    arr = nullptr;
}

int **allocMatrix(unsigned n)
{
    int **arr = new (std::nothrow) int *[n];
    if (!arr)
        return nullptr;
    for (unsigned i = 0; i < n; ++i)
    {
        arr[i] = new (std::nothrow) int[n];
        if (!arr)
        {
            deallocMatrix(arr, n);
            return nullptr;
        }
        for (unsigned j = 0; j < n; ++j)
            std::cin >> arr[i][j];
    }
    return arr;
}

int specialSum(int **arr, unsigned n)
{
    int res{0};
    for (unsigned i = 1; i < n; ++i)
        for (unsigned j = 0; j < i; ++j)
        {
            if ((j < 1 || arr[i][j] >= arr[i][j - 1]) &&
                (i < 1 || arr[i][j] >= arr[i - 1][j]) &&
                (j >= n - 1 || arr[i][j] >= arr[i][j + 1]) &&
                (i >= n - 1 || arr[i][j] >= arr[i + 1][j]))
                res += arr[i][j];
        }
    return res;
}

int main()
{
    unsigned n;
    std::cout << "Enter size of the square matrix: \n";
    std::cin >> n;
    int **m = allocMatrix(n);
    std::cout << specialSum(m, n) << '\n';
    deallocMatrix(m, n);
    return 0;
}