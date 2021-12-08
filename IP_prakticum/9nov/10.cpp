#include <iostream>

int main()
{
	const int MAX = 128;
	int N;
	int arr[MAX];
	std::cin >> N;
	for (int i = 0; i < N; ++i)
		std::cin >> arr[i];

	if (N < 3)
		std::cout << "It's a saw.\n";
	else {
		int i = 1,saw=0;
        while(saw>-2 && saw<2 && i<N)
        {
            if(arr[i]>arr[i-1])
                ++saw;
            else if(arr[i]<arr[i-1])
                --saw;
                ++i;
        }
		std::cout << "It's" << (saw>-2 && saw<2 ? "" : " not") << " a saw.\n";
	}
	return 0;
}
