#include <iostream>

int main()
{
	const int MAX = 128;
	int N;
	int arr[MAX];
	std::cin >> N;
	for (int i = 0; i < N; ++i)
		std::cin >> arr[i];

	for (int i = 0; i < N; ++i)
	{
		int j = 0;
		while (j < N && arr[i]!=arr[j]) {
			++j;
			if (j == i)++j;
		}
		if (j == N)
			std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
	return 0;
}
