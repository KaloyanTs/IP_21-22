#include <iostream>

int main()
{
	const int MAX = 128;
	int N;
	int arr[MAX];
	std::cin >> N;
	for (int i = 0; i < N; ++i)
		std::cin >> arr[i];

	int maxSeq = 1, currSeq = 1, maxSeqIndex=0;

	for (int i = 1; i < N; ++i)
	{
		if (arr[i] > arr[i - 1])++currSeq;
		else {
			if (maxSeq < currSeq) {
				maxSeq = currSeq;
				maxSeqIndex = i-currSeq;
			}

			currSeq = 1;
		}
	}
	if (maxSeq < currSeq){
		maxSeq = currSeq;
		maxSeqIndex = N-currSeq;
	}
	std::cout << "Longest increasing subsequence starts at index " << maxSeqIndex
		<< " with length " << maxSeq << '\n';
	return 0;
}
