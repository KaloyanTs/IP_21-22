#include <iostream>
#include <cmath>
using namespace std;

int main() {
	//Task 1
	//int a, b;	cin >> a >> b;	cout << a - b << endl;

	//Task 2
	/*
	int a, b, c;
	cin >> a >> b >> c;
	cout << (a + b + c) / 3 << endl;
	*/

	//Task 3
	/*
	int a, b;
	cin >> a >> b;
	a = a + b;	b = a - b;	a = a - b;
	cout << a <<endl<< b << endl;
	*/
	

	//Task 4
	/*
	int a, b, c;
	cin >> a >> b >> c;
	cout << (a / 100) % 10 << (b / 100) % 10 << (c / 100) % 10 << endl;
	*/

	//Task 5
	/*
	int a;
	cin >> a;
	cout << a % 10 << (a / 10) % 10 << (a / 100) % 10 << a / 1000 << endl;
	*/

	//Taks 6
	/*
	int a;
	cin >> a;
	cout << char(a / 100 + 'a') << char((a / 10) % 10 + 'a') << char(a % 10 + 'a') << endl;
	return 0;
	*/

	//Task 7
	/*
	int a;
	cin >> a;
	cout << (a / 10000 == a % 10)&&((a / 1000) % 10 == (a / 10) % 10);
	cout << endl;	//???
	*/
	
	//Task 8
	/*
	int a;
	cin >> a;
	cout << (	!(a % 400)  ||	(!(a % 4) && (a % 100))	);
	cout << endl;
	*/
	

	//Task 9
	/*
	int a, b, c;
	cin >>a >> b >> c;
	cout << (-b + sqrt(b * b - 4 * a * c)) / 2 << endl;
	cout << (-b - sqrt(b * b - 4 * a * c)) / 2 << endl;
	*/

	//Task 10
	/*
	int a;
	cin >> a;
	int a1 = a / 100, a2 =a%100;
	int b1 = a / 10, b2 = a % 10;
	a1 = a1 * a2;
	b1 = b1 * b2;
	cout << ((a1 > b1) * a1 + (a1 <= b1) * b1) << endl;
	*/

	//Task 11
	/*
	int a1, a2, b1, b2, c1, c2;
	cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
	cout <<'('<< (
		((a1 < b1) && a1 < c1) * a1 +
		((b1 < a1) && b1 < c1) * b1 +
		((c1 < a1) && c1 < b1) * c1
			) <<','<< (
		((a2 < b2) && a2 < c2) * a2 +
		((b2 < a2) && b2 < c2) * b2 +
		((c2 < a2) && c2 < b2) * c2
		) <<')'<< endl;
	*/

	//Task 12
	
	int a1, a2,
		b1, b2,
		c1, c2,
		d1, d2,
		e1, e2;
	cin >> a1 >> a2 >>
		b1 >> b2 >>
		c1 >> c2 >>
		d1 >> d2 >>
		e1 >> e2;
	float a3 = sqrt(a1 * a1 + a2 * a2);
	float b3 = sqrt(b1 * b1 + b2 * b2);
	float c3 = sqrt(c1 * c1 + c2 * c2);
	float d3 = sqrt(d1 * d1 + d2 * d2);
	float e3 = sqrt(e1 * e1 + e2 * e2);
	float r = (a3 > b3 && a3 > c3 && a3 > d3 && a3 > e3) * a3 +
		(b3 > a3 && b3 > c3 && b3 > d3 && b3 > e3) * b3 +
		(c3 > a3 && c3 > b3 && c3 > d3 && c3 > e3) * c3 +
		(d3 > a3 && d3 > b3 && d3 > c3 && d3 > e3) * d3 +
		(e3 > a3 && e3 > b3 && e3 > d3 && e3 > c3) * e3;
	cout << (	(int(r)==r)*r+(int(r)!=r)*(int(r)+1)	);
	

	//Task 13
	/*
	int a;
	cin >> a;
	cout << int(log10(a))+1 << endl;
	cout << int(log10(a) / log10(2)) + 1 << endl;
	*/

	//Task 14
	/*
	int a, b, c;
	cin >> a >> b >> c;
	cout << int(log10(a)+ log10(b)+ log10(c)) + 1 << endl;
	*/

	return 0;
}