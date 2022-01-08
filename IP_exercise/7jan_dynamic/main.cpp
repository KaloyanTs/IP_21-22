#include <iostream>
#include <cstring>

char *addWordToList(char *listBegin, char *listEnd,
                    const char *wordBegin, const char *wordEnd)
{
    if (listBegin != listEnd)
        *listEnd++ = ' ';
    while (wordBegin < wordEnd)
        *listEnd++ = *wordBegin++;
    *listEnd++ = ',';
    *listEnd = '\0';
    return listEnd;
}

const char *findLast(const char *begin, const char *end, char c)
{
    do
    {
        --end;
    } while (end >= begin && *end != c);
    return (end < begin ? nullptr : end);
}

bool startsWith(const char *sourceBegin, const char *sourceEnd,
                const char *targetBegin, const char *targetEnd)
{
    while (targetBegin < targetEnd &&
           sourceBegin < sourceEnd &&
           *targetBegin == *sourceBegin)
    {
        ++sourceBegin;
        ++targetBegin;
    }
    return targetBegin == targetEnd;
}

const char *myStrstr(const char *sourceBegin, const char *sourceEnd,
                     const char *targetBegin, const char *targetEnd)
{
    while (sourceBegin < sourceEnd && !startsWith(sourceBegin, sourceEnd, targetBegin, targetEnd))
        ++sourceBegin;
    return (sourceBegin < sourceEnd ? sourceBegin : nullptr);
}

char *repeatingWords(const char *str)
{
    unsigned l = strlen(str);
    char *buf = new (std::nothrow) char[l / 2 + 1];
    if (!buf)
        return nullptr;
    const char *end = str + l, *last = nullptr;
    char *bufEnd = buf;
    do
    {
        last = findLast(str, end, ' ');
        if (last)
        {
            if (myStrstr(str, last - 1, last + 1, end) &&
                !myStrstr(buf, bufEnd, last + 1, end))
                bufEnd = addWordToList(buf, bufEnd, last + 1, end);
            end = last - 1;
        }
    } while (last);
    if (bufEnd != buf)
        --bufEnd;
    *bufEnd = '\0';
    char *res = new (std::nothrow) char[strlen(buf) + 1];
    if (!res)
    {
        delete[] buf;
        return nullptr;
    }
    strcpy(res, buf);
    delete[] buf;
    return res;
}

void repeatingWordsListTask()
{
    char buf[] = "cat, dog, cat, I, am, qk, professor, qk, hello";
    char *bufRes = repeatingWords(buf);
    if (!bufRes)
        std::cout << "Not enough memory for repeatingWords!\n";
    else
    {
        std::cout << bufRes << '\n';
        delete[] bufRes;
    }
}

int main()
{
    repeatingWordsListTask();
    return 0;
}