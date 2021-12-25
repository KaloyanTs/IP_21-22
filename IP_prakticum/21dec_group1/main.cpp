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

int main()
{
    //Task1()
    //Task2()
    
    return 0;
}