#include <iostream>
#include <cmath>

bool ifContains(unsigned int n, int digit)
{
	bool noDuplicate = true;
	while (n > 0 && noDuplicate) {
		if (digit == n % 10) {
			noDuplicate = false;
		}
		n /= 10;
	}
	return !noDuplicate;
}

bool isPrime(unsigned int n) {
	bool prime = true;
	int sqrtN = sqrt(n);
	for (int i = 2; i <= sqrtN && prime; ++i) {
		if (n % i == 0)prime = false;
	}
	return prime&&n>1;
}

bool equal_sums(unsigned int n)
{
	int sum{ 0 }, digit{ 0 };
	while(n>0) {
		digit = n % 10;
		n /= 10;
		if (digit % 2)sum += digit;
		else sum -= digit;
	}
	return !sum;
}

bool predicate_1(unsigned int n) {
	int minDigit{ 9 }, maxDigit{ 0 }, curDigit{ 0 };
	while (n > 0) {
		curDigit = n % 10;
		n /= 10;
		if (curDigit >maxDigit)maxDigit=curDigit;
		if (curDigit < minDigit)minDigit = curDigit;
	}
	return (maxDigit - minDigit) == 3;
}

bool predicate_2(unsigned int n) {
	int sumDigits{ 0 }, curDigit{ 0 };
	while (n > 0) {
		sumDigits += (n%10);
		n /= 10;
	}
	return isPrime(sumDigits);
}

double cos3(double x, double eps) 
{	
	double sum{ 0 };
	double prevTerm,curTerm;
	int k{ 2 }, powerPart{ 12 };
	prevTerm = -6 * x * x;
	curTerm = prevTerm;
	sum += curTerm;
	do {
		
		prevTerm = curTerm;
		curTerm /= powerPart;
		powerPart = (powerPart - 3) * 9 + 3;
		k += 2;
		curTerm *= double(powerPart * (-1LL) * x * x);
		curTerm/= double((k - 1) * k);
		sum += curTerm;
	} while (abs(prevTerm - curTerm) > eps);
	return sum/4;
}

unsigned int furthest_point(int n)
{
	double x{ 0 }, y{ 0 }, maxdist{ 0 };
	int furthestIndex{ 0 };
	for (int i = 0; i < n; ++i) {
		std::cin >> x >> y;
		if (x * x + y * y > maxdist)
		{
			maxdist = x * x + y * y;
			furthestIndex = i;
		}
	}
	return furthestIndex;
}

bool alternating_number_in_range(int p, int q)
{
	bool greater = true, found=false;
	for (int i = p; i <= q && !found; ++i)
	{
		int bufI = i;
		greater = true;
		found = true;
		while (bufI > 9) {
			if (greater) {
				if (bufI % 10 <= (bufI / 10) % 10) {
					bufI = -1;
					found = false;
				}
			}
			else {
				if (bufI % 10 >= (bufI / 10) % 10) {
					bufI = -1;
					found = false;
				}
			}
			bufI /= 10;
			greater=1-greater;
		}
	}
	return found;
}

unsigned int find_smallest_cube_sum(int min, int diff)
{
	int n = min, sumOfCubes{0};
	int a = 1, b = diff + a;
	sumOfCubes = a * a * a + b * b * b;
	while (sumOfCubes < n) {
		++a; ++b;
		sumOfCubes = a * a * a + b * b * b;
	}
	return sumOfCubes;
}	

bool duplicate_digits(int n)
{
	bool has = false;
	while (n > 9 && !has) {
		if(ifContains(n/10,n%10)){
			has = true;
		}
		n /= 10;
	}
	return has;
}

unsigned int numberOfDivSmallerN(unsigned int num, int max)
{
	unsigned int count{ 1 };
	for (int i = 2; i < max && i <= num / 2; ++i)
		if (num % i == 0)++count;
	if (num < max)++count;
	return count;
}

unsigned int firstN(unsigned int n)
{
	unsigned int sum{ 0 }, i{ 0 }, j{ 2 };
	while (i < n) {
		if (isPrime(numberOfDivSmallerN(j, n))) {
			++i;
			sum += j;
			std::cout << j << '\n';
		}
		j++;
	}
	return sum;
}

bool isPower2(unsigned int n)
{
	unsigned int i{ 1 };
	while (i < n) i <<= 1;
	return n == i;
}

unsigned int largest_power_of_2(unsigned int n)
{
	unsigned int input{ 0 }, largestPower{ 1 };
	for (int i = 0; i < n; ++i)
	{
		std::cin >> input;
		if (isPower2(input) && input > largestPower)
		{
			largestPower = input;
		}
	}
	return largestPower;
}

int main()
{
	//Task 1
	/*std::cout << equal_sums(1223) << '\n';
	std::cout<<equal_sums(1234)<<'\n';
	*/

	//Task 2
	/*unsigned n;
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		if (predicate_1(i) && predicate_2(i))
			std::cout << i << std::endl;
	}
	*/

	//Task 4
	/*double eps;
	double x;
	std::cin >> x >> eps;
	std::cout << cos3(x, eps) << '\n';
	*/

	//Task 5
	/*int n;
	std::cin >> n;
	std::cout << furthest_point(n) << '\n';
	*/

	//Task 7
	/*int p{ 0 }, q{ 0 };
	std::cin >> p >> q;
	std::cout << alternating_number_in_range(p,q) << '\n';
	*/
	
	//Task 8
	/*unsigned int p, k;
	std::cin >> p >> k;
	std::cout << find_smallest_cube_sum(p, k) << '\n';
	*/

	//Task 9
	/*unsigned int n;
	std::cin >> n;
	std::cout << duplicate_digits(n) << '\n';
	*/

	//Task 10
	/*unsigned int n;
	std::cin >> n;
	std::cout << firstN(n) << '\n';
	*/

	//Task 12
	unsigned int n;
	std::cin >> n;
	std::cout << largest_power_of_2(n) << '\n';

	return 0;
}