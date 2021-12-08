#include <iostream>

int main()
{
	const int MAX = 128;
	int N;
	int arr[MAX];
	std::cin >> N;
	for (int i = 0; i < N; ++i)
		std::cin >> arr[i];

	int i=0, elem, count = 0, max = 0;
	std::cin >> elem;
	while(i<N)
	{
		if (i==0) {
			while (arr[i] != elem && i < N)
				++i;
			if (i < N)
				std::cout << "first ->" << i << std::endl;
		}
		if (arr[i] == elem) {
			max = i;
			++count;
		}
		++i;
	}
	if (count > 0)
	{
		std::cout << "last ->" << max << std::endl;
		std::cout << "count ->" << count << std::endl;
	}
	else {
		std::cout << "No such element!\n";
	}

	return 0;
}
