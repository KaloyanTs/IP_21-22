#include <iostream>

void printArr(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << ' ';
	std::cout << '\n';
}

unsigned int absValue(int n) {
	return (n < 0 ? -n : n);
}

float min(float a, float b)
{
	const int EPS = 1e-6;
	return (a - b > EPS ? b : a);
}

float max(float a, float b)
{
	const int EPS = 1e-6;
	return (a - b > EPS ? a : b);
}

bool equal(float a, float b, float EPS)
{
	return (a - b < EPS && a - b > -EPS);
}

unsigned int factorial(unsigned int n)
{
	unsigned int f = 1;
	unsigned int i = 0;
	while (++i <= n)
		f *= i;
	return f;
}

unsigned int TripleFactorial(unsigned int n)
{
	unsigned int f = (n == 0 ? 1 : n);
	for (int i = n; i > 0; i -= 3)
		f *= i;
	return f;
}

float pow(float a, unsigned int n)
{
	float result = 1;
	unsigned int i = 0;
	while (i++ < n)
		result *= a;
	return result;
}

unsigned int Fibonacci(unsigned int n)
{
	unsigned int a1 = 1,a2=1;
	unsigned int i = 2;
	if (n == 0)a2 = 0;
	while (i++ < n)
	{
		a2 += a1;
		a1 = a2 - a1;
	}
	return a2;
}

void Binary(unsigned int n)
{
	unsigned int LargestPow2 = 2;
	while (LargestPow2 < n)
		LargestPow2 *= 2;
	LargestPow2 /= 2;
	while (LargestPow2 > 0)
	{
		if (LargestPow2 > n)
			std::cout << '0';
		else {
			std::cout << '1';
			n-= LargestPow2;
		}
		LargestPow2 /= 2;
	}
	std::cout << '\n';
}

unsigned int GCD(unsigned int a, unsigned int b)
{
	if (a == 0)return b;
	if (b == 0)return a;
	while (a != b)
		if (a > b)a -= b;
		else b -= a;
	return a;
}

int StringCompare(char s1[], char s2[])
{
	unsigned size1 = 0, size2 = 0;
	int pos = 0,res=0;
	unsigned int minSize = (unsigned int)min(size1, size2);
	do {
		if (s1[pos] != 0)
			++size1;
		if (s2[pos] != 0)
			++size2;
		if (size1 == size2)
		{
			if (s1[pos] > s2[pos])res = 1;
			if (s1[pos] < s2[pos])res = -1;
		}
		++pos;
	} while (res==0 && size1==size2);
	if (res == 0)
	{
		if (size1 > size2)res = -1;
		else if (size2 > size1)res = 1;
		else res = 0;
	}
	return res;
}

void PascalDUMB(unsigned int rows)
{
	const int MAX = 128;
	int arr[MAX],arrPrev[MAX];
	unsigned int size = 1;
	arr[0] = 1;
	if(rows>0)
	do {
		printArr(arr, size);
		for (unsigned int i = 0; i < size; ++i)
			arrPrev[i] = arr[i];
		++size;
		arr[0] = arr[size - 1] = 1;
		for (unsigned int j = 1; j < size - 1; ++j)
		{
			arr[j] = arrPrev[j - 1] + arrPrev[j];
		}
	} while (size < rows + 1);
}

unsigned calcBinomDigits(unsigned row, unsigned pos)
{
	unsigned binom = 1,count=0;
	for (int i = 0; i < pos; ++i)
	{
		binom *= row;
		--row;
		binom /= i + 1;
	}
	while (binom > 0)
	{
		binom /= 10;
		++count;
	}
	return count;
}

void Pascal(unsigned rows)
{
	unsigned el = 1,maxDigit=calcBinomDigits(rows-1,(rows-1)/2);	//<- най-голямото число в триъг.
	for (unsigned i = 0; i <rows; ++i)
	{
		for (unsigned j = 0; j < rows - i -1; ++j)
			for (unsigned p = 0; p < maxDigit; ++p)
				std::cout << ' ';
		unsigned iter = i;
		el = 1;
		for (unsigned j = 0; j <= i; ++j)
		{
			std::cout.width(maxDigit);
			std::cout << el;
			for (unsigned p = 0; p < maxDigit; ++p)
				std::cout << ' ';
			el *= iter;
			--iter;
			el /= (j + 1);

		}
		std::cout << std::endl;
	}
}

int main()
{
	/*
	int n=-2;
	float a=3.4, b=3.41;
	std::cout << "absValue: " << absValue(n) << '\n';
	std::cout << "min: " << min(n, b) << '\n';
	std::cout << "equal: " << equal(b + 1e-8, b, 1e-6) << '\n';
	std::cout << "Factorial: " << factorial(6) << std::endl;
	std::cout << "Tiple factorial: " << TripleFactorial(8) << std::endl;
	std::cout << "Number to the power of number: " << pow(2.34, 5) << std::endl;
	std::cout << "Fibonacci number: " << Fibonacci(10) << std::endl;
	std::cout << "Decimal to binary: ";
	Binary(59);
	*/
	std::cout << "GCD: " << GCD(200, 168) << std::endl;
	char s1[] = "Hello", s2[] = "Helly";
	std::cout << "Comparing strings: " << StringCompare(s1, s2) << std::endl;
	std::cout << "The Pascal triangle: \n";
	Pascal(16);
	return 0;
}