#include <iostream>
#include <cmath>

int main() {
	//Task 1
	/*
	int a, b, c;
	std::cin >> a >> b;
	a = (a > b ? a : b);
	std::cin >> c;
	a = (a > c ? a : c);
	std::cout << a << std::endl;
	*/

	//Task 2
	/*
	int a, b, c;
	std::cin >> a >> b >> c;
	const float EPS = 0.00001;
	int min,max,mid;
	min = (a > b ? b :a);
	min = (min > c ? c : min);
	max = (a > b ? a : b);
	max = (max > c ? max : c);
	mid = a + b + c - max - min;
	if (min+mid<=max||a<=0||b<=0||c<=0) { std::cout << "Invalid triangle"<<std::endl; return 0; }
	int cos=(min*min+mid*mid-max*max);
	if (!cos)std::cout << "Right-angled triangle" << std::endl;
	else if (cos >0)std::cout << "Acute-angled triangle" << std::endl;
	else std::cout << "Obtuse triangle" << std::endl;
	*/

	//Task 4
	/*
	int hage = 0;
	float dage = 0;
	std::cin >> hage;
	if (hage <= 2) dage = (float(hage) * 10.5);
	else dage = hage * 4 + 13;
	std::cout << dage << std::endl;
	*/

	//Task 11
	/*
	int month = 0, day = 0, daysLeft = 0;
	std::cin >> month >> day;
	if (month < 1 || month>12) { std::cout << "There's no such month" << std::endl; return 0; }
	if (day<1) { std::cout << "There's no such day" << std::endl; return 0; }
	switch (month) {
	case 1:
		if (day > 31) {
			std::cout << "There's no such day" << std::endl; 
			return 0;
		}
		daysLeft += (31 - day);
	case 2:
		if (day > 29 && !daysLeft) {
			std::cout << "There's no such day" << std::endl;
			return 0;
		}
		if (!daysLeft) { daysLeft += (29 - day); }
		else daysLeft += 29;
	case 3:
		if (day > 31 && !daysLeft) {
			std::cout << "There's no such day" << std::endl;
			return 0;
		}
		if (!daysLeft) { daysLeft += (31 - day); }
		else daysLeft += 31;
	case 4:
		if (day > 30 && !daysLeft) {
			std::cout << "There's no such day" << std::endl;
			return 0;
		}
		if (!daysLeft) { daysLeft += (30 - day); }
		else daysLeft += 30;
	case 5:
		if (day > 31) {
			std::cout << "There's no such day" << std::endl;
			return 0;
		}
		if (!daysLeft) { daysLeft += (31 - day); }
		else daysLeft += 31;
	case 6:
		if (day > 30 && !daysLeft) {
			std::cout << "There's no such day" << std::endl;
			return 0;
		}
		if (!daysLeft) { daysLeft += (30 - day); }
		else daysLeft += 30;
	case 7:
		if (day > 31 && !daysLeft) {
			std::cout << "There's no such day" << std::endl;
			return 0;
		}
		if (!daysLeft) { daysLeft += (31 - day); }
		else daysLeft += 31;
	case 8:
		if (day > 31 && !daysLeft) {
			std::cout << "There's no such day" << std::endl;
			return 0;
		}
		if (!daysLeft) { daysLeft += (31 - day); }
		else daysLeft += 31;
	case 9:
		if (day > 30 && !daysLeft) {
			std::cout << "There's no such day" << std::endl;
			return 0;
		}
		if (!daysLeft) { daysLeft += (30 - day); }
		else daysLeft += 30;
	case 10:
		if (day > 31) {
			std::cout << "There's no such day" << std::endl;
			return 0;
		}
		if (!daysLeft) { daysLeft += (31 - day); }
		else daysLeft += 31;
	case 11:
		if (day > 30 && !daysLeft) {
			std::cout << "There's no such day" << std::endl;
			return 0;
		}
		if (!daysLeft) { daysLeft += (30 - day); }
		else daysLeft += 30;
	case 12:
		if (day > 31) {
			std::cout << "There's no such day" << std::endl;
			return 0;
		}
		if (!daysLeft) { daysLeft += (31 - day); }
		else daysLeft += 31;
	}
	std::cout << daysLeft << std::endl;
	*/

	//Task 6
	int num,d;
	std::cin >> num>>d;
	short lastDig = num % 10;
	if (lastDig == d) {std::cout<<"true"<<std::endl; return 0; }
	num /= 10; lastDig = num % 10;
	if (lastDig == d) {std::cout<<"true"<<std::endl; return 0; }
	num /= 10; lastDig = num % 10;
	if (lastDig == d) {std::cout<<"true"<<std::endl; return 0; }
	num /= 10; lastDig = num % 10;
	if (lastDig == d) { std::cout <<"true"<< std::endl; return 0; }
	num /= 10; lastDig = num % 10;
	if (lastDig == d) {std::cout<<"true"<<std::endl; return 0; }
	std::cout << "false"<< std::endl;

	return 0;
}