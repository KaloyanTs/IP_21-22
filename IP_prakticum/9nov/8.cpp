#include <iostream>

int main()
{
	const int MAX = 128;
	int N;
	int arr[MAX];
	std::cin >> N;
	for (int i = 0; i < N; ++i)
		std::cin >> arr[i];

	const int SUM = 42;
	for (int i = 0; i < N-1; ++i)
	{
		int j = i + 1;
		while (j < N && arr[j] + arr[i] != SUM)
			++j;
		if (j < N)
			std::cout << '(' << arr[i] << ", " << arr[j] << ')' << std::endl;
	}
	return 0;
}
