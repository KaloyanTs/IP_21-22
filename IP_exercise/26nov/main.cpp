#include <iostream>
#include <ctime>
const unsigned MAX = 20;

void fillArr(int arr[], const unsigned size)
{
	for (unsigned i = 0; i < size; ++i)
		arr[i] = rand() % size + 1;
}

void printArr(int arr[], const unsigned size)
{
	for (unsigned i = 0; i < size; ++i)
		std::cout << arr[i] << ' ';
	std::cout << '\n';
}

void merge(int arr[], const unsigned left, const unsigned mid, const unsigned right)
{
	int arrCpy[MAX] = { 0 };
	unsigned nl = left, nr = mid+1, c = 0;
	while (nl <= mid && nr <= right)
	{
		if (arr[nl] < arr[nr])
			arrCpy[c++] = arr[nl++];
		else
			arrCpy[c++] = arr[nr++];
	}
	while (nl <= mid)
		arrCpy[c++] = arr[nl++];
	while (nr <= right)
		arrCpy[c++] = arr[nr++];
	for (unsigned i = 0; i < right - left + 1; ++i)
		arr[left + i] = arrCpy[i];
}

void mergeRec(int arr[], const unsigned left, const unsigned right)
{
	if (left >= right)
		return;
	unsigned mid = (left + right) / 2;
	mergeRec(arr, left, mid);
	mergeRec(arr, mid + 1, right);
	merge(arr, left, mid, right);
}

void mergeSort(int arr[], const unsigned size)
{
	if (size > 1)
		mergeRec(arr, 0, size - 1);
}

void bubbleSort(int arr[], const unsigned size)
{
	for (unsigned i = 0; i < size - 1; ++i)
		for (unsigned j = 0; j < size-1; ++j)
		{
			if (arr[j + 1] < arr[j])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
}

void insertionSort(int arr[], const unsigned size)
{
	unsigned i = 0, swapsC = 0;
	while (i < size - 1)
	{
		swapsC = 0;
		while (arr[i + 1] < arr[i])
		{
			int tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
			if(i)
				--i;
			++swapsC;
		}
		i += (swapsC ? swapsC : 1);
	}
}

void selectionSort(int arr[],const unsigned size)
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
		
}

void swap(int arr[], const unsigned pos1, const unsigned pos2)
{
	int tmp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tmp;
}

unsigned partition(int arr[], unsigned left, unsigned right)
{
	unsigned pivotIndex = left;
	for (unsigned i = left; i < right; ++i)
	{
		if (arr[i] < arr[right])
		{
			swap(arr, i, pivotIndex++);
		}
	}
	swap(arr, pivotIndex, right);
	return pivotIndex;
}

void quickSortRec(int arr[], unsigned left, unsigned right)
{
	if (left >= right)
		return;
	int pIndex = partition(arr, left, right);
	quickSortRec(arr, left, (pIndex - 1 < 0 ? 0 : pIndex - 1));
	quickSortRec(arr, pIndex + 1, right);
}

void quickSort(int arr[], const unsigned size)
{
	if (size < 2)
		return;
	quickSortRec(arr, 0, size - 1);
}

int main()
{
	srand(time(0));
	int arr[MAX];
	fillArr(arr, MAX);
	//bubbleSort(arr, MAX);
	//selectionSort(arr, MAX);
	//insertionSort(arr,MAX);
	//mergeSort(arr, MAX);
	quickSort(arr, MAX);
	printArr(arr, MAX);
	return 0;
}