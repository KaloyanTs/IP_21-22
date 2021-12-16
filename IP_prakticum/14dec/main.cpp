#include <iostream>

void printArr(int *arr, unsigned size)
{
	for (unsigned i = 0; i < size; ++i)
		std::cout << arr[i] << ' ';
	std::cout << '\n';
}

int *getMin(int *a, unsigned size)
{
	int minI = 0;
	for (unsigned i = 1; i < size; ++i)
		if (*(a + i) < *(a + minI))
			minI = i;
	a += minI;
	return a;
}

unsigned myStrlen(const char *str)
{
	unsigned l = 0;
	while (*str++)
		++l;
	return l;
}

char *myStrcat(char *str1, const char *str2)
{
	unsigned l = myStrlen(str1);
	unsigned add = 0;
	do
	{
		*(str1 + l + add++) = *str2++;
	} while (*str2);
	*(str1 + l + add) = '\0';
	return str1;
}

int myStrcmp(const char *str1, const char *str2)
{
	if (str1 == str2)
		return 0;
	while (*str1 && *str2 && *str1 == *str2)
	{
		++str1;
		++str2;
	}
	if (!*str1 && !*str2)
		return 0;
	if (!*str1)
		return -1;
	if (!*str2)
		return 1;
	return (*str1 < *str2 ? -1 : 1);
}

char *myStrcpy(char *str1, const char *str2)
{
	char *res = str1;
	while (*str2)
		*str1++ = *str2++;
	*str1 = '\0';
	return res;
}

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int *selectionSort(int *const arr, unsigned size)
{
	if (!size)
		return nullptr;
	for (unsigned i = 0; i < size - 1; ++i)
	{
		unsigned minI = i;
		for (unsigned j = i + 1; j < size; ++j)
			if (arr[j] < arr[minI])
				minI = j;
		swap(arr[minI], arr[i]);
	}
	return arr;
}

const int *myBinarySearch(const int *beg, unsigned size, unsigned val)
{
	const int *end = beg + size;
	while (size > 0 && *(beg + size / 2) != val)
	{
		size /= 2;
		if (val > *(beg + size))
			beg = beg + size + 1;
		else
			end = beg + size - 1;
	}
	return (val == *(beg + size / 2) ? beg + size / 2 : nullptr);
}

void bSearch()
{
	unsigned size;
	std::cout << "Enter size of array: ";
	std::cin >> size;
	int *const arr = new int[size];
	std::cout << "Enter the array:\n";
	for (unsigned i = 0; i < size; ++i)
		std::cin >> arr[i];
	int val;
	std::cout << "Value to be searched: ";
	std::cin >> val;
	selectionSort(arr, size);
	const int *b = myBinarySearch(arr, size, val);
	if (!b)
		std::cout << "NOT found\n";
	else
	{
		std::cout << "Found on position " << b - arr << ".\n";
		printArr(arr, size);
	}
	delete[] arr;
}

void stringFunctions()
{
	const unsigned MAX = 64;
	char str[MAX] = "Hi!";
	myStrcpy(str, "Hello, world!");
	std::cout << myStrlen(str) << '\n';
	myStrcat(str, " I'm a human!");
	std::cout << str << std::endl;
	std::cout << myStrcmp("Hello!", "Heilo!!!") << '\n';
}

int main()
{
	const unsigned MAX = 8;
	int arr[MAX];

	/*for (unsigned i = 0; i < MAX; ++i)
		std::cin >> arr[i];

	int* min = getMin(arr, 8);
	std::cout << "Min element is: " << *min << '\n';
	std::cout << "On position: " << min - arr << '\n';
	std::cout << *arr << std::endl;*/
	stringFunctions();
	// bSearch();
	return 0;
}