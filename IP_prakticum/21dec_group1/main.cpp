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

int main()
{

    return 0;
}