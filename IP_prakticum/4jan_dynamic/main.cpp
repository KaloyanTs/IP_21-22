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

void Task5()
{
    const unsigned MAX = 32;
    unsigned n;
    char str[MAX];
    char **arr = allocWordArray(n, MAX);
    if (!arr)
    {
        std::cout << "Not enough memory!\n";
        return;
    }
    sortWords(arr, n, strcmp);
    std::cout << "Sorted words:\n";
    printWordArray(arr, n);
    deallocWordArray(arr, n);
}

unsigned isInBeginning(char *text, char *word)
{
    unsigned l = 0;
    while (*word && *text == *word)
    {
        ++text;
        ++word;
        ++l;
    }
    if (!*word)
        return l;
    return 0;
}

char *replace(char *text, char *find, char *replace, const unsigned TEXT_MAX)
{
    char *buf = new (std::nothrow) char[TEXT_MAX];
    if (!buf)
        return nullptr;
    unsigned l = 0;
    while (*text)
    {
        unsigned i = isInBeginning(text, find);
        text += i;
        if (i)
        {
            i = 0;
            while (replace[i])
            {
                buf[l++] = replace[i];
                ++i;
            }
        }
        else
        {
            buf[l++] = *text;
            ++text;
        }
    }
    buf[l++] = '\0';
    char *res = new (std::nothrow) char[l];
    if (!res)
    {
        delete[] buf;
        return nullptr;
    }
    strcpy(res, buf);
    delete[] buf;
    return res;
}

void Task6()
{
    const unsigned TEXT_MAX = 256;
    const unsigned WORD_MAX = 32;
    char text[TEXT_MAX];
    char word1[WORD_MAX], word2[WORD_MAX];
    std::cin.getline(text, TEXT_MAX);
    std::cin.getline(word1, WORD_MAX);
    std::cin.getline(word2, WORD_MAX);
    char *res = replace(text, word1, word2, TEXT_MAX * 2);
    if (!res)
    {
        std::cout << "Not enough memory for replace!\n";
        return;
    }
    std::cout << res << '\n';
    delete[] res;
}

int main()
{
    // Task5();
    Task6();
    return 0;
}