#include <iostream>
#include <cstring>

void deallocWordArray(char **&arr, unsigned n)
{
    for (unsigned i = 0; i < n; ++i)
        delete[] arr[i];
    delete[] arr;
    arr = nullptr;
}

unsigned readCountWords()
{
    unsigned n;
    std::cout << "Enter count of words: ";
    std::cin >> n;
    return n;
}

char **allocWordArray(unsigned &n, const unsigned MAX)
{
    n = readCountWords();
    char **arr = new (std::nothrow) char *[n];
    if (!arr)
        return nullptr;
    std::cin.ignore();
    for (unsigned i = 0; i < n; ++i)
    {
        arr[i] = new (std::nothrow) char[MAX];
        if (!arr[i])
        {
            deallocWordArray(arr, i);
            return nullptr;
        }
        std::cin.getline(arr[i], MAX);
    }
    return arr;
}

void swap(char *&str1, char *&str2)
{
    char *tmp = str1;
    str1 = str2;
    str2 = tmp;
}

void sortWords(char **&arr, unsigned n, int f(const char *, const char *))
{
    unsigned iMin{0};
    for (unsigned i = 0; i < n - 1; ++i)
    {
        iMin = i;
        for (unsigned j = i + 1; j < n; ++j)
            if (f(arr[iMin], arr[j]) > 0)
                iMin = j;
        swap(arr[iMin], arr[i]);
    }
}

void printWordArray(char **arr, unsigned n)
{
    for (unsigned i = 0; i < n; ++i)
        std::cout << arr[i] << '\n';
}

int main()
{
    const unsigned MAX = 32;
    unsigned n;
    char str[MAX];
    char **arr = allocWordArray(n, MAX);
    if (!arr)
    {
        std::cout << "Not enough memory!\n";
        return 0;
    }
    sortWords(arr, n, strcmp);
    std::cout << "Sorted words:\n";
    printWordArray(arr, n);
    deallocWordArray(arr, n);
    return 0;
}