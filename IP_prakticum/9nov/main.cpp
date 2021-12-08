#include <iostream>

int main()
{
	const int MAX = 500;
	int N;
	int arr[500];
	std::cin >> N;
	for (int i = 0; i < N; ++i)
		std::cin >> arr[i];
	//Task 1
	/**/

	//Task 2
	/*
	int max = arr[0];
	for (int i = 1; i < N; ++i)
		max = (max < arr[i] ? arr[i] : max);
	std::cout << max;*/

	//Task 3
	/*int max = (arr[0] > arr[1] ? arr[0] : arr[1]);
	int secMax = arr[0] + arr[1] - max;
	for (int i = 2; i < N; ++i) {
		if (arr[i] >= max)
			max = arr[i];
		else {
			secMax = (arr[i] > secMax ? arr[i] : secMax);
		}
			secMax = (arr[i-2] > secMax && arr[i-2]<max ? arr[i-2] : secMax);
	}
	secMax = (arr[N-2] > secMax && arr[N-2]<max ? arr[N-2] : secMax);
	std::cout << secMax << std::endl;*/

	//Task 4
	/*int Av = 0,count=0;
	for (int i = 0; i < N; ++i)
	{
		if (arr[i] % 2 == 0) {
			++count;
			Av += arr[i];
		}
	}
	std::cout << (double)Av / count << std::endl;*/


	//Task 5
	/*int S = 0;
	for (int i = 0; i < N; ++i)
	{
		if (i % 2)S += arr[i];
		else S -= arr[i];
	}
	std::cout << S << std::endl;*/

	//Task 6
	/*for (int i = 0; i < N; ++i)
	{
		int j = 0;
		while (j < i && arr[i] != arr[j])
			++j;
		if (j == i) {
			++j;
			while (arr[j] != arr[i] && j < N)
				j++;
			if (j < N)std::cout << arr[i]<<' ';
		}
	}*/

	//Task 6.2
	/*for (int i = 0; i < N; ++i)
	{
		int j = i+1;
		while (j < N && arr[i] != arr[j])
			++j;
		if (j<N)
			std::cout << arr[i] << ' ';
	}
	std::cout<<std::endl;*/

	//Task 7
	/*for (int i = 0; i < N; ++i)
	{
		int j = 0;
		while (j < i && arr[i] != arr[j])
			++j;
		if (j == i) {
			++j;
			while (arr[j] != arr[i] && j < N)
				j++;
			if (j == N)std::cout << arr[i]<<' ';
		}
	}*/

	//Task 8
	/*const int SUM = 42;
	for (int i = 0; i < N; ++i)
	{
		int j = i + 1;
		while (j < N && arr[j] + arr[i] != SUM)
			++j;
		if (j < N)
			std::cout << '(' << arr[i] << ", " << arr[j] << ')' << std::endl;
	}*/

	//Task 9
	/*int elem,count=0,max=0;
	std::cin >> elem;
	for (int i = 0; i < N; ++i)
	{
		if (!i) {
			while (arr[i] != elem && i < N)
				++i;
			if (i < N)
			{
				std::cout << "first ->" << i << std::endl;
			}
		}
		if (arr[i] == elem) {
			max = i;
			++count;
		}
	}
	std::cout << "last ->" << max << std::endl;
	std::cout << "count ->" << count << std::endl;*/


	//Task 10
	/*if (N < 3)
		std::cout << "No!" << std::endl;
	else {
		int i = 2;
		while (i < N && !(arr[i] > arr[i - 1] && arr[i - 1] > arr[i - 2])
			&& !(arr[i] < arr[i - 1] && arr[i - 1] < arr[i - 2]))
			++i;
		std::cout << (i == N ? "Yes\n" : "No\n");
	}*/

	//Task 11
	/*int maxSeq = 0, maxSeqIndex = 0;
	for(int i = 0; i < N-1; ++i)
	{
		int maxEl = arr[i];
		int curSeq = 1;
		for (int j = i + 1; j < N; ++j)
		{
			if (arr[j] > maxEl)
			{
				++curSeq;
				maxEl = arr[j];
			}
		}
		if (curSeq > maxSeq)
		{
			maxSeq = curSeq;
			maxSeqIndex = i;
		}
	}
	std::cout << "Longest increasing sequence starts at index " << maxSeqIndex 
			  << " with length " << maxSeq<<'\n';*/

	//Task 11.2
	/*int maxSeq = 1, currSeq = 1;

	for (int i = 1; i < N; ++i)
	{
		if (arr[i] > arr[i - 1])++currSeq;
		else {
			if (maxSeq < currSeq) 
				maxSeq = currSeq;
			currSeq = 1;
		}
	}
	if (maxSeq < currSeq)
		maxSeq = currSeq;
	std::cout << maxSeq << std::endl;*/
	
	//Task 12
	/*int size1, size2;
	int arr1[64], arr2[64];
	std::cout << "Size of array 1: ";
	std::cin >> size1;
	std::cout << "Elements of array 1: ";
	for (int i = 0; i < size1; ++i)
		std::cin >> arr1[i];
	std::cout << "Size of array 2: ";
	std::cin >> size2;
	std::cout << "Elements of array 2: ";
	for (int i = 0; i < size2; ++i)
		std::cin >> arr2[i];

	for (int i = 0; i < size1 + size2 - 1; ++i)
	{
		int coeff = 0;
		for (int j = (i + 1 - size2 > 0 ? i + 1 - size2 : 0); j <= i && j < size1; ++j)
			coeff += arr1[j] * arr2[i - j];
		std::cout << coeff << ' ';
	}*/
	
	//Task 13
	int i = 1, j = 0;
	do {
		arr[i] += arr[i - 1];
		j = 0;
		while (arr[j] != arr[i] && j<i)
			++j;
		++i;
	} while (i<N && j==i-1);
	if (i == N)std::cout << "No\n";
	else std::cout << "Yes\n";

	return 0;
}