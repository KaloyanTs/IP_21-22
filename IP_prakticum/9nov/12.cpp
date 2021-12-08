#include <iostream>

int main()
{
	const int MAX = 65;
	int size1, size2;
	int arr1[MAX], arr2[MAX];
	std::cout << "Degree of polynomial 1: ";
	std::cin >> size1;
	++size1;
	std::cout << "Coefficients of polynomial 1: ";
	for (int i = 0; i < size1; ++i)
		std::cin >> arr1[i];
	std::cout << "Degree of polynomial 2: ";
	std::cin >> size2;
	++size2;
	std::cout << "Coefficients of polynomial 2: ";
	for (int i = 0; i < size2; ++i)
		std::cin >> arr2[i];

    if( (size1==1 && arr1[0]==0) || (size2==1 && arr2[0]==0) ){
        std::cout<<"0\n";
    }
    else {
        for (int i = 0; i < size1 + size2 - 1; ++i)
        {
            int coeff = 0;
            for (int j = (i + 1 - size2 > 0 ? i + 1 - size2 : 0); j <= i && j < size1; ++j)
                coeff += arr1[j] * arr2[i - j];
            std::cout << coeff << ' ';
        }
    }
	return 0;
}
