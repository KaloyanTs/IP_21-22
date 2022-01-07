#include <iostream>
#include <cstring>

void addWordToList(char *list, unsigned &l, const char *word)
{
    if (l)
        list[l++] = ' ';
    list[l] = '\0';
    while (*word)
        list[l++] = *word++;
    list[l++] = ',';
    list[l] = '\0';
}

char *repeatingWords(const char *text)
{
    unsigned l = 0;
    char *word = new (std::nothrow) char[strlen(text) + 1];
    if (!word)
        return nullptr;
    strcpy(word, text);
    //за да можем да работим с подадения низ го копираме в нов
    text = word;
    char *buf = new (std::nothrow) char[strlen(text) / 2 + 1];
    //в най-лошия случай всяка дума ще я има точно два пъти и ще се нуждаем от <= толкова място
    *buf = '\0';
    if (!buf)
        return nullptr;
    char *textPtr = word;
    while (*textPtr)
    {
        while (*textPtr && *textPtr != ',')
            ++textPtr;
        //търсим следващата дума
        if (*textPtr)
        {
            *textPtr = '\0';
            if (strstr(textPtr + 1, word) && !strstr(buf, word))
            //има я напред и не е намирана досега
            {
                addWordToList(buf, l, word);
                /*
                if (l)
                    buf[l++] = ' ';
                buf[l] = '\0';
                strcat(buf, word);          //  addWordToList
                l += strlen(word);          //               ни спестява малко време спрямо тези 2 реда?
                buf[l++] = ',';
                buf[l] = '\0';
                */
            }
            word = textPtr += 2;
            //прескачаме ", "
        }
    }
    if (!l)
        ++l;
    buf[l - 1] = '\0';
    //на тази позиция има ',', която не ни трябва повече
    char *res = new (std::nothrow) char[l];
    if (res)
        strcpy(res, buf);
    delete[] buf;
    delete[] text;
    return res;
}

void repeatingWordsListTask()
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
}

int main()
{
    repeatingWordsListTask();
    return 0;
}