#include <iostream>
#include <cstring>

unsigned absVal(int n)
{
    return (unsigned)(n < 0 ? -n : n);
}

unsigned digitSum(int n)
{
    if (!n)
        return 0;
    return absVal(n % 10) + digitSum(n / 10);
}

void Task1a()
{
    std::cout << digitSum(-23) << '\n';
}

void deallocArr(int *&arr)
{
    delete[] arr;
    arr = nullptr;
}

int *allocArr(unsigned n)
{
    int *arr = new (std::nothrow) int[n];
    if (!arr)
        return nullptr;
    for (unsigned i = 0; i < n; ++i)
        std::cin >> arr[i];
    return arr;
}

unsigned max(unsigned a, unsigned b)
{
    return (a < b ? b : a);
}

unsigned maxSum(int *arr, unsigned n)
{
    unsigned maxS{0};
    for (unsigned i = 0; i < n; ++i)
        maxS = max(maxS, digitSum(arr[i]));
    return maxS;
}

void deallocMatrix(int **&m, unsigned n)
{
    for (unsigned i = 0; i < n; ++i)
        delete[] m[i];
    delete[] m;
    m = nullptr;
}

unsigned countThisSum(int *arr, unsigned N, unsigned s)
{
    unsigned res{0};
    for (unsigned i = 0; i < N; ++i)
        res += (digitSum(arr[i]) == s);
    return res;
}

int **allocMatrixSum(int *arr, unsigned N, unsigned n)
{
    int **M = new (std::nothrow) int *[n + 1];
    if (!M)
        return nullptr;
    for (unsigned i = 0; i <= n; ++i)
    {
        M[i] = new (std::nothrow) int[countThisSum(arr, N, i) + 1];
        // M[i] = new (std::nothrow) int[<всички числа> + 1];
        if (!M[i])
        {
            deallocMatrix(M, i);
            return nullptr;
        }
        M[i][0] = 0;
    }
    return M;
}

void fillSums(int **sums, unsigned sumCount, int *arr, unsigned N)
{
    unsigned currSum{0};
    for (unsigned i = 0; i < N; ++i)
    {
        currSum = digitSum(arr[i]);
        sums[currSum][++sums[currSum][0]] = arr[i];
    }
}

void printSums(int **sums, unsigned sumCount)
{
    for (unsigned i = 0; i <= sumCount; ++i)
    {
        std::cout << i << ": ";
        for (unsigned j = 1; j <= sums[i][0]; ++j)
            std::cout << sums[i][j] << ' ';
        std::cout << '\n';
    }
}

void Task1b()
{
    unsigned N;
    std::cin >> N;
    int *arr = allocArr(N);
    if (!arr)
    {
        std::cout << "Not enough memory!\n";
        return;
    }
    unsigned maxS = maxSum(arr, N);
    int **sums = allocMatrixSum(arr, N, maxS);
    if (!sums)
    {
        std::cout << "Not enough memory!\n";
        return;
    }
    fillSums(sums, maxS, arr, N);
    printSums(sums, maxS);
    deallocArr(arr);
    deallocMatrix(sums, maxS + 1);
}

void deallocEquations(int **&eq, unsigned N)
{
    for (unsigned i = 0; i < N; ++i)
        delete[] eq[i];
    delete[] eq;
    eq = nullptr;
}

int **allocEquations(unsigned N)
{
    int **eq = new (std::nothrow) int *[N];
    if (!eq)
        return nullptr;
    for (unsigned i = 0; i < N; ++i)
    {
        eq[i] = new (std::nothrow) int[4];
        // eq[i]=0 when no root found
        // eq[i]!=0 when found a root
        if (!eq[i])
        {
            deallocEquations(eq, i);
            return nullptr;
        }
        eq[i][0] = 0;
        std::cin >> eq[i][1] >> eq[i][2] >> eq[i][3];
    }
    return eq;
}

void calc(int *eq, int arg)
{
    eq[0] = (eq[1] * arg * arg + eq[2] * arg + eq[3] == 0);
}

void tryForRoots(int **eq, unsigned N, int *arg, unsigned K)
{
    for (unsigned i = 0; i < N; ++i)
    {
        unsigned j = 0;
        while (j < K && !eq[i][0])
            calc(eq[i], arg[j++]);
    }
}

void printEquations(int **eq, unsigned N)
{
    for (unsigned i = 0; i < N; ++i)
        if (eq[i][0])
        {
            for (unsigned j = 1; j <= 3; ++j)
                std::cout << eq[i][j] << ' ';
            std::cout << '\n';
        }
}

int *readArguments(unsigned K)
{
    int *arg = new (std::nothrow) int[K];
    if (!arg)
        return nullptr;
    for (unsigned i = 0; i < K; ++i)
        std::cin >> arg[i];
    return arg;
}

void Task2()
{
    unsigned N;
    std::cin >> N;
    int **eq = allocEquations(N);
    if (!eq)
    {
        std::cout << "Not enough memory!\n";
        return;
    }
    unsigned K;
    std::cin >> K;
    int *arguments = readArguments(K);
    if (!arguments)
    {
        deallocEquations(eq, N);
        std::cout << "Not enough memory!\n";
        return;
    }
    tryForRoots(eq, N, arguments, K);
    printEquations(eq, N);

    deallocEquations(eq, N);
    delete[] arguments;
}

bool isLetter(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void appendWord(char *&buf, const char *&str)
{
    while (isLetter(*str))
        *buf++ = *str++;
}

void findBegining(const char *&s)
{
    while (*s && !isLetter(*s))
        ++s;
}

unsigned wordCount(const char *s)
{
    if (!*s)
        return 0;
    unsigned cnt = 0;
    while (*s)
        if (*s++ == ' ')
            ++cnt;
    return cnt + 1;
}

void initializeWords(const char **ptr, char *s)
{
    unsigned i = 0;
    ptr[i++] = s++;
    while (*s)
    {
        if (*(s - 1) == ' ')
            ptr[i++] = s;
        ++s;
    }
}

void modify(char *s)
{
    unsigned l = 0;
    unsigned iter{0};
    while (s[iter])
    {
        if (isLetter(s[iter]))
            s[l++] = s[iter];
        else if (iter && isLetter(s[iter - 1]))
            s[l++] = ' ';
        ++iter;
    }
    if (s[l] == ' ')
        --l;
    s[l] = '\0';
}

bool compare(const char *s1, const char *s2)
{
    while (*s1 && *s2 && *s1 != ' ' && *s2 != ' ' && *s1 == *s2)
    {
        ++s1;
        ++s2;
    }
    return ((!*s1 || *s1 == ' ') && (!*s2 || *s2 == ' '));
}

void swap(const char *&a, const char *&b)
{
    const char *tmp = a;
    a = b;
    b = tmp;
}

void swap(unsigned &a, unsigned &b)
{
    unsigned tmp = a;
    a = b;
    b = tmp;
}

void selectionSort(const char **words, unsigned wordCnt, unsigned *counts)
{
    unsigned iMin{0};
    for (unsigned i = 0; i < wordCnt - 1; ++i)
    {
        iMin = i;
        for (unsigned j = i + 1; j < wordCnt; ++j)
            if (counts[j] > counts[iMin])
                iMin = j;
        swap(counts[iMin], counts[i]);
        swap(words[i], words[iMin]);
    }
}

void printWord(const char *word)
{
    while (*word && *word != ' ')
        std::cout << *word++;
    std::cout << ' ';
}

void printWordsArr(const char **words, unsigned wordCnt)
{
    for (unsigned i = 0; i < wordCnt; ++i)
        printWord(words[i]);
    std::cout << '\n';
}

void reduceWords(const char **words, unsigned &wordCnt, unsigned *counts)
{
    unsigned newCnt = 0;
    unsigned iter{0};
    while (iter < wordCnt)
    {
        if (words[iter])
        {
            words[newCnt] = words[iter];
            counts[newCnt++] = counts[iter];
        }
        ++iter;
    }
    wordCnt = newCnt;
}

void uniqueWords(char *s)
{
    modify(s);
    unsigned wordCnt = wordCount(s);
    if (!wordCnt)
        return;
    const char **ptr = new (std::nothrow) const char *[wordCnt];
    unsigned *counts = new (std::nothrow) unsigned[wordCnt];
    if (!ptr || !counts)
    {
        std::cout << "Not enough memory!\n";
        return;
    }
    initializeWords(ptr, s);
    for (unsigned i = 0; i < wordCnt; ++i)
        counts[i] = 1;
    for (unsigned i = 0; i < wordCnt - 1; ++i)
        if (ptr[i])
            for (unsigned j = i + 1; j < wordCnt; ++j)
                if (ptr[j] && compare(ptr[i], ptr[j]))
                {
                    ++counts[i];
                    ptr[j] = nullptr;
                }
    reduceWords(ptr, wordCnt, counts);
    selectionSort(ptr, wordCnt, counts);
    printWordsArr(ptr, wordCnt);
}

void Task3()
{
    const unsigned MAX = 1024;
    char str[MAX];
    std::cin.getline(str, MAX);
    uniqueWords(str);
}

bool rightInLeft(unsigned a, unsigned b)
{
    if (a == b)
        return true;
    if (b > a)
        return false;
    if (a % 10 == b % 10)
        return rightInLeft(a / 10, b / 10) || rightInLeft(a / 10, b);
    return rightInLeft(a / 10, b);
}

bool oneInAnother(unsigned a, unsigned b)
{
    return rightInLeft(a, b) || rightInLeft(b, a);
}

void RecTask()
{
    unsigned a, b;
    std::cin >> a >> b;
    std::cout << std::boolalpha << oneInAnother(a, b) << '\n';
}

int main()
{
    // Task1a();
    // Task1b();
    // Task2();
    Task3();
    // RecTask();
    return 0;
}