#include <iostream>

int main()
{
	const int MAX = 128;
	int N;
	int arr[MAX];
	std::cin >> N;
	for (int i = 0; i < N; ++i)
		std::cin >> arr[i];

	//Образуваме сумите b1=a1, b2=a1+a2, b3=a1+a2+a3, ..., bn=a1+a2+...+an
	//И ако намерим 2 еднакви bi=bj, тогава разликата им a(i+1)+...+aj = 0
	int i = 1, j = 0;
	do {
		arr[i] += arr[i - 1];
		j = 0;
		while (arr[i]!=0 && arr[j] != arr[i] && j < i)
			++j;
		++i;
	} while (arr[i-1]!=0 && i < N && j == i - 1);
	if (i == N)std::cout << "No\n";
	else std::cout << "Yes\n";

	return 0;
}
