#include <iostream>
#include <cstring>

char *repeatingWords(const char *text)
{
    unsigned l = 0;
    char *textCpy = new (std::nothrow) char[strlen(text) + 1];
    if (!textCpy)
        return nullptr;
    strcpy(textCpy, text);
    text = textCpy;
    char *buf = new (std::nothrow) char[strlen(text) / 2 + 1];
    *buf = '\0';
    if (!buf)
        return nullptr;
    char *textPtr = textCpy;
    while (*textPtr)
    {
        while (*textPtr && *textPtr != ',')
            ++textPtr;
        if (*textPtr)
        {
            *textPtr = '\0';
            if (strstr(textPtr + 1, textCpy) && !strstr(buf, textCpy))
            {
                if (l)
                    buf[l++] = ' ';
                buf[l] = '\0';
                strcat(buf, textCpy);
                l += strlen(textCpy);
                buf[l++] = ',';
                buf[l] = '\0';
            }
            textCpy = textPtr += 2;
        }
    }
    if (!l)
        ++l;
    buf[l - 1] = '\0';
    char *res = new (std::nothrow) char[l];
    if (res)
        strcpy(res, buf);
    delete[] buf;
    delete[] text;
    return res;
}

int main()
{
    const unsigned MAX = 128;
    char buf[MAX] = "cat, dog, cat, I, am, qk, professor, qk, hello";
    // std::cin.getline(buf, MAX);
    char *bufRes = repeatingWords(buf);
    if (!bufRes)
        std::cout << "Not enough memory for repeatingWords!\n";
    else
    {
        std::cout << bufRes << '\n';
        delete[] bufRes;
    }
    return 0;
}