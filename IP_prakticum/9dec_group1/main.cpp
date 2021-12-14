#include <iostream>
#include <cstring>

void swap(float& a, float& b)
{
	float tmp = a;
	a = b;
	b = tmp;
}

void swap(unsigned& a, unsigned& b)
{
	unsigned tmp = a;
	a = b;
	b = tmp;
}

int* createArray(int size)
{
	int* a = new int[size];
	return a;
}

void Task3()
{
	unsigned size, sum = 0, min, max;
	std::cout << "Enter size of the array: ";
	std::cin >> size;
	unsigned* arr = new unsigned[size];
	for (unsigned i = 0; i < size; ++i)	//всичко може да се свърши и тук
		std::cin >> arr[i];
	sum = min = max = arr[0];
	for (unsigned i = 1; i < size; ++i)
	{
		sum += arr[i];
		if (min > arr[i])
			min = arr[i];
		if (max < arr[i])
			max = arr[i];
	}
	std::cout << "Sum: " << sum << '\n';
	std::cout << "Min: " << min << '\n';
	std::cout << "Max: " << max << '\n';
	delete[] arr;
}

const char* strcat(const char* a, const char* b)
{
	unsigned la = strlen(a);
	unsigned lb = strlen(b);
	char* c = new char[la + lb + 1];
	for (const char* i = &a[0]; *i; ++i)
		c[i - &a[0]] = *i;
	for (const char* i = &b[0]; *i; ++i)
		c[la + i - &b[0]] = *i;
	c[la + lb] = 0;
	return c;
}

void Task5()
{
	unsigned size;
	std::cout << "Enter size of array: ";
	std::cin >> size;
	unsigned* arr = new unsigned[size];
	for (unsigned i = 0; i < size; ++i)
		std::cin >> arr[i];
	unsigned bound = size / 2;
	for (unsigned i = 0; i < bound; ++i)
		if (arr[i] > arr[size - 1 - i])
			swap(arr[i], arr[size - 1 - i]);
	for (unsigned i = 0; i < size; ++i)
		std::cout << arr[i] << ' ';
	std::cout<<'\n';
	delete[] arr;
}

unsigned* createArray(unsigned size)
{
	unsigned* arr = new unsigned[size];
	return arr;
}

void fillArray(unsigned* arr, unsigned size)
{
	for (unsigned i = 0; i < size; ++i)
		std::cin >> arr[i];
}

unsigned* selectionSort(unsigned* arr, unsigned size)
{
	unsigned iMin;
	for (unsigned i = 0; i < size - 1; ++i)
	{
		iMin = i;
		for (unsigned j = i + 1; j < size; ++j)
			if (arr[j] < arr[iMin])
				iMin = j;
		int tmp = arr[i];
		arr[i] = arr[iMin];
		arr[iMin] = tmp;
	}
	return arr;
}

void printArray(unsigned* arr, int size)
{
	for (unsigned i = 0; i < size; ++i)
		std::cout << arr[i] << ' ';
	std::cout << '\n';
}

void Task6()
{
	unsigned size;
	std::cout << "Enter size of array: ";
	std::cin >> size;
	unsigned* arr = createArray(size);
	fillArray(arr, size);
	arr = selectionSort(arr, size);
	printArray(arr, size);
	delete[] arr;
}

void my_sort(unsigned* beg, unsigned* end)
{
	beg = selectionSort(beg, end - beg);
}

bool my_binary_search(unsigned* beg, unsigned* end, unsigned val)
{
	if (beg >= end && *beg != val)
		return false;
	unsigned mid = (end - beg) / 2;
	if (val == *(beg + mid))
		return true;
	if (val > *(beg + mid))
		return my_binary_search(beg + mid + 1, end, val);
	return my_binary_search(beg, beg + mid - 1, val);
}

int main()
{
	//Task3();
	//Task5();
	//Task6();
	unsigned arr[10] = { 1,3,5,6,7,9,11,13 };
	std::cout << my_binary_search(arr, arr + 8, 7) << '\n';
	return 0;
}