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

char *copy(const char *inputBegin, const char *inputEnd, char *output)
{
    while (inputBegin < inputEnd)
        *output++ = *inputBegin++;
    return output;
}

unsigned newLength(const char *text, const char *find, const char *replace)
{
    unsigned res = strlen(text), findLength = strlen(find), replaceLength = strlen(replace);
    do
    {
        text = strstr(text, find);
        if (text)
        {
            res += replaceLength;
            res -= findLength;
            text += findLength;
        }
    } while (text);
    return res;
}

char *replace(const char *text, const char *find, const char *replace)
{
    char *buf = new (std::nothrow) char[newLength(text, find, replace) + 1];
    if (!buf)
        return nullptr;
    unsigned rL = strlen(replace), fL = strlen(find);
    char *bufEnd = buf;
    const char *textPtr = strstr(text, find);
    while (textPtr)
    {
        bufEnd = copy(text, textPtr, bufEnd);
        bufEnd = copy(replace, replace + rL, bufEnd);
        textPtr += fL;
        text = textPtr;
        textPtr = strstr(textPtr, find);
    }
    textPtr = text + strlen(text);
    bufEnd = copy(text, textPtr, bufEnd);
    *bufEnd = '\0';
    return buf;
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
    char *res = replace(text, word1, word2);
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