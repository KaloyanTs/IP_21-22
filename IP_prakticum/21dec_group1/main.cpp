#include <iostream>
const unsigned LETTERS = 26;

unsigned getMax(unsigned *data, char &maxC)
{
    unsigned maxI = 0;
    for (unsigned i = 1; i < LETTERS; ++i)
        if (data[maxI] < data[i])
            maxI = i;
    maxC = maxI + 'a';
    return data[maxI];
}

void Task1()
{
    unsigned L;
    std::cin >> L;
    char *str = new char[L + 1];
    std::cin.ignore();
    std::cin.getline(str, L + 1);
    char *pstr = str;
    unsigned alpha[26] = {0};
    while (*pstr)
    {
        ++alpha[*pstr - 'a'];
        ++pstr;
    }
    char maxC{0};
    std::cout << getMax(alpha, maxC) << " -> " << maxC << '\n';
    delete[] str;
}

char *myStrcpy(char *dest, const char *str)
{
    char *destCpy = dest;
    do
    {
        *dest++ = *str;
    } while (*str++);
    return destCpy;
}

unsigned myStrlen(const char *str)
{
    unsigned l = 0;
    while (*str++)
        ++l;
    return l;
}

bool endsWithDot(const char *str, unsigned l)
{
    return str[l - 1] == '.';
}

void Task2()
{
    const unsigned maxL = 20;
    char word[maxL];
    char maxWord[maxL] = "";
    unsigned maxWordLength = 0, l = 0;
    do
    {
        std::cin.getline(word, maxL, ' ');
        l = myStrlen(word);
        if (l > maxWordLength)
        {
            myStrcpy(maxWord, word);
            maxWordLength = l;
        }
    } while (!endsWithDot(word, l));
    std::cout << maxWord << '\n';
}

void swap(char &c1, char &c2)
{
    char tmp = c1;
    c1 = c2;
    c2 = tmp;
}

char *selSort(char *arr)
{
    char *arrCpy = arr;
    char *parr = arr;
    char *maxEl = arr;
    while (*arr)
    {
        parr = arr + 1;
        maxEl = arr;
        while (*parr)
        {
            if (*parr > *maxEl)
                maxEl = parr;
            ++parr;
        }
        swap(*arr++, *maxEl);
    }
    return arrCpy;
}

void getCommon(const char *str1, const char *str2, char *res)
{
    while (*str1 && *str2)
    {
        if (*str1 == *str2)
        {
            *res++ = *str1;
            ++str1;
            ++str2;
        }
        else if (*str1 > *str2)
            ++str1;
        else if (*str1 < *str2)
            ++str2;
    }
    *res = '\0';
}

void Task3()
{
    const unsigned MAX = 20;
    char num1[MAX], num2[MAX], common[MAX];
    std::cin.getline(num1, MAX);
    std::cin.getline(num2, MAX);
    selSort(num1);
    selSort(num2);
    getCommon(num1, num2, common);
    std::cout << common << '\n';
}

const char *mystrChr(const char *str, char c)
{
    while (*str && *str != c)
        ++str;
    return (*str ? str : nullptr);
}

unsigned commonLetters(const char *str, const char *word)
{
    unsigned count{0};
    while (*word)
    {
        if (mystrChr(str, *word++))
            ++count;
    }
    return count;
}

void Task4()
{
    const unsigned MAX_STRING = 500;
    const unsigned MAX_WORD = 10;
    char S[MAX_STRING], d[MAX_WORD];
    std::cin.getline(S, 500);
    std::cin.getline(d, 10);
    std::cout << commonLetters(S, d) << '\n';
}

int main()
{
    // Task1()
    // Task2()
    // Task3();
    Task4();
    return 0;
}