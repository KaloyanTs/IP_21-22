#include <iostream>

bool isGoingUp(const int *a, unsigned n)
{
    if (n <= 1)
        return true;
    return (a[0] < a[1]) && isGoingUp(a + 1, n - 1);
}

int main()
{
    int arr[] = {1, 3, 8, 7, 8};
    std::cout << isGoingUp(arr, 5) << '\n';
    return 0;
}