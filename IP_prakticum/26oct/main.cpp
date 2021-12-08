#include <iostream>
#include <cmath>

int main() {
	//Task 1
	/*
	for (int i = 0; i <= 10; i++)
		std::cout << i << std::endl;
	*/

	//Task 2
	/*
	unsigned int N;
	std::cin >> N;
	for (int i = 0; i <= N; i++)
		std::cout << i << std::endl;
	*/

	//Task 3
	/*int N, M;
	std::cin >> N >> M;
	for (int i = N; i <= M; i++)
		std::cout << i << std::endl;
	*/

	//Task 4
	/*
	for (unsinged char i = 0; i<128; i++)
		std::cout << i << " -> " << i << std::endl;
	*/

	//Task 5
	/*
	int N, M,S=0;
	std::cin >> N >> M;
	for (int i = N; i <= M; i++)S += i;
	std::cout << S << std::endl;
	*/

	//Task 6
	/*
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)std::cout << '#';
	std::cout << std::endl;
	for (int i = 0; i < n - 2; i++) {
		std::cout << '#';
		for (int j = 0; j < n - 2; j++)std::cout << ' ';
			std::cout << '#';
			std::cout << std::endl;
	}
	if(n>1)for (int i = 0; i < n; i++)std::cout << '#';
	*/

	//Task 7
	/*
	int num = 0, min = 0, max = 0, c = 0;
	float S = 0;
	char separator;
	do {
		std::cin >> num;
		if (!c)min = max = num;
		if (min >num)min = num;
		if (max < num)max = num;
		S += num;
		c++;
		std::cin >> separator;
	} while (separator == ',');
	std::cout << "min -> " << min << std::endl;
	std::cout << "max -> " << max << std::endl;
	std::cout << "mean -> " << S / (float)c << std::endl;
	*/

	//Task 8
	/*
	unsigned int N=0;
		int num,max;
		std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> num;
		if (!i || num > max)max = num;
	}
	std::cout << max << std::endl;
	*/

	//Task 9
	/*
	unsigned int N = 0;
	float S = 0;
	int num;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> num;
		S += num;
	}
	std::cout << S/(float)N << std::endl;
	*/

	//Task 10
	/*
	int N,c=1;
	std::cin >> N;
	if (!N) {
		std::cout << "infinitely many!" << std::endl;
		return 0;
	}
	else if(N==1)std::cout << "2" << std::endl;
	N = abs(N);
	for (int i = 2; i <= sqrt(N); i++)
		if (N % i == 0)c++;
	std::cout << 4 * c << std::endl;
	*/

	//Task 11
	/*
	unsigned int N, c = 1;
	std::cin >> N;
	int spaceCount=(int)(log10(N*N+N)-log10(2))+1;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= i; j++){
			std::cout << c;
			for(int k=0;k<spaceCount-(int)log10(c);k++)std::cout<<' ';
			c++;
		}
		std::cout << std::endl;
	}
	*/

	//Task 12
	/*
	unsigned int limit;
	int d1, d2, d3;
	std::cin >> limit >> d1 >> d2 >> d3;
	for (int i = 0; i <= limit; i++)
		if (i % d1 == 0 && i % d2 == 0 && i % d3 == 0)
			std::cout << i << std::endl;
	*/
	
	//Task 13
	/*
	int P = 1,N;
	unsigned int M;
	std::cin >> N >> M;
	for (int i = 0; i < M; i++)P *= N;
	std::cout << "N^M = " << P << std::endl;
	*/
	
	//Task 14
	/*
	int n;
	std::cin >> n;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0) {
			std::cout << "false" << std::endl;
			return 0;
		}
	std::cout << "true" << std::endl;
	*/

	//Task 15
	/*
	unsigned int N,i=2,c=0;
	bool f;
	std::cin >> N;
	while (c++ < N-1) {
		std::cout << i << std::endl;
		do {
			if (i == 2)i++; else i += 2;
			f = true;
			for (int j = 2; j <= sqrt(i); j++)
				if (i % j == 0) {
					f = false;
					j = sqrt(i) + 1;
				}
		} while (!f);
	}
	std::cout << i << std::endl;
	*/

	//Task 16
	/*
	unsigned int N;
	unsigned long long P = 1;
	std::cin >> N;
	for (int i = 2; i <= N; i++)P *= i;
	std::cout << P << std::endl;
	*/

	//Task 17
	/*
	int N;
	std::cin >> N;
	int a = 1, b = 1;
	for (int i = 0; i < N; i++)
	{
		std::cout << a << std::endl;
		b = b + a;
		a = b - a;
	}
	*/

	//Task 18
	/*
	unsigned M, N;
	std::cin >> M >> N;
	while (M != N)
	{
		if (M > N)M -= N;
		else N -= M;
	}
	std::cout << M << std::endl;
	*/

	//Task 19
	/*
	unsigned int N,S=0;
	std::cin >> N;
	while (N > 0) {
		S += N % 10;
		N /= 10;
	}
	std::cout << S << std::endl;
	*/

	//Task 20
	/*
	int n,decN=0,i=0,pow2i=1;
	std::cin >> n;
	while (n > 0) {
		decN += (n % 10) * pow2i;
		n /= 10;
		pow2i *= 2;
	}
	std::cout << decN << std::endl;
	*/

	//Task 21
	/*
	unsigned int N, dc = 0, prod8 = 1;
	std::cin >> N;
	dc = int(log10(N) / log10(8));
	for (int i = 0; i < dc; i++)prod8 *= 8;
	for (int i = 0; i <= dc; i++) {
		std::cout << N/prod8; 
		N %= prod8;
		prod8 /= 8;
	}
	std::cout << std::endl;
	*/
	
	//Task 22
	/*
	unsigned long int N, bigPow10 = 1, smallPow10 = 1;
	int left=0, right=0;
	std::cin >> N;
	int dc = (int)log10(N);
	for (int i = 0; i < dc; i++) bigPow10 *= 10;
	while(bigPow10>=smallPow10) {
		left = (N / bigPow10)% 10;
		bigPow10 /= 10;
		right = (N / smallPow10) % 10;
		smallPow10 *= 10;
		if (left != right) {
			std::cout << "Not a palindrome" << std::endl;
			return 0;
		}
	}
	std::cout << "Palindrome" << std::endl;
	*/

	//Task 23
	/*int a, b, diff, prime1 = 1, prime2;
	bool possibleSol=false;
	std::cin >> a >> b;
	diff = (a > b ? a - b : b - a);
	prime2 = diff - prime1;
	do {
		if (prime1 > 2)prime1++; prime1++;
		prime2 = diff - prime1;
		possibleSol = true;
		for (int i = 2; i <= sqrt(prime1); i++)
			if (prime1 % i == 0) {
				possibleSol = false;
				i = sqrt(prime1) + 1;
			}
		if (possibleSol) {
			for (int i = 2; i <= sqrt(prime2); i++)
				if (prime2 % i == 0) {
					possibleSol = false;
					i = sqrt(prime2) + 1;
				}
		}
	} while (!possibleSol&&prime1<prime2);
	if (possibleSol)std::cout << prime1 << " and " << prime2 << std::endl;
	else std::cout << "No such sum of primes" << std::endl;
	*/

	//Task 24
	unsigned int N,spCount=0;
	std::cin >> N;
	 int starCount = N;
	do {
		for (int i = 0; i < spCount; ++i)std::cout << ' ';
		for (int i = 0; i < starCount; ++i)std::cout << '*';
		for (int i = 0; i < spCount; ++i)std::cout << ' ';
		std::cout << std::endl;
		++spCount;
		starCount -= 2;
	} while (starCount > 0);
	starCount = (starCount ? 3 : 4);
	spCount -= 2;
	do {
		for (int i = 0; i < spCount; ++i)std::cout << ' ';
		for (int i = 0; i < starCount; ++i)std::cout << '*';
		for (int i = 0; i < spCount; ++i)std::cout << ' ';
		std::cout << std::endl;
		--spCount;
		starCount += 2;
	} while (starCount <=N);

	return 0;
}