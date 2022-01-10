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

void matrixSum()
{
    unsigned n;
    std::cout << "Enter size of the square matrix: \n";
    std::cin >> n;
    int **m = allocMatrix(n);
    std::cout << specialSum(m, n) << '\n';
    deallocMatrix(m, n);
}

char *appendWord(const char *begin, const char *end, char *buf)
{
    while (begin < end)
        *buf++ = *begin++;
    return buf;
}

bool equal(const char *from1, const char *to1,
           const char *from2, const char *to2)
{
    while (from1 < to1 && from2 < to2 && *from1 == *from2)
    {
        ++from1;
        ++from2;
    }
    return (from1 == to1 && from2 == to2);
}

const char *adjRepeating(const char *str)
{
    char *buf = new (std::nothrow) char[strlen(str) + 1];
    if (!buf)
        return nullptr;
    const char *strEnd = str + strlen(str);
    char *bufEnd = buf;
    const char *strPtr1 = str, *strPtr2 = nullptr;
    strPtr1 = strchr(str, ',');
    while (strPtr1)
    {
        strPtr2 = strchr(strPtr1 + 1, ',');
        if (!strPtr2)
            strPtr2 = strEnd;
        if (equal(str, strPtr1, strPtr1 + 1, strPtr2))
        {
            bufEnd = appendWord(str, strPtr1, bufEnd);
            *bufEnd++ = ',';
        }
        str = ++strPtr1;
        strPtr1 = strchr(str, ',');
    }
    if (bufEnd != buf)
        --bufEnd;
    *bufEnd = '\0';
    char *res = new (std::nothrow) char[strlen(buf) + 1];
    if (res)
        strcpy(res, buf);
    delete[] buf;
    return res;
}

void consecutiveWords()
{
    const unsigned MAX = 128;
    // char buf[MAX];
    // std::cin.getline(buf, MAX);
    const char *res = adjRepeating("cat,cat,dog,cat,pig,small,sma,small,small,smaller,cat,dog,dog");
    if (!res)
    {
        std::cout << "Not enough memory!\n";
        return;
    }
    std::cout << res << '\n';
    delete[] res;
}

int main()
{
    // matrixSum();
    consecutiveWords();
    return 0;
}