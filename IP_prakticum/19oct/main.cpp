#include <iostream>
#include <cmath>
using namespace std;

int main() {
	
	//Task 1
	/*int a;
	cin >> a;
	cout << a << " is";
	if (a % 3 && a % 5){cout << " not divisible by 3 or 5" << endl; return 0;}
	cout<< " divisible by";
	if (!(a % 3) && !(a % 5))cout << " 3 and 5";
	else {
		if (!(a % 3))cout << " 3";
		else cout << " 5";
	}
	cout << endl;
	*/

	//Task 2
	/*float x, y;
	const float EPS=0.0001;
	cin >> x >> y;
	if(abs(x)<EPS&&abs(y)<EPS)cout<<"It's the center point!";
	else if(abs(x)<EPS)cout<<"Lies on the y axis!";
	else if(abs(x)<EPS)cout<<"Lies on the x axis!";
	bool posx=(x>=-EPS);
	bool posy=(y>=-EPS);
	if (posx&&posy)cout << 1 << endl;
	if (!posx && !posy)cout << 3 << endl;
	if (posx)cout << 4 << endl;
	if (posy)cout << 2 << endl;
	*/

	//Task 3
	/*char c;
	cin >> c;
	if (c >= 'a' && c <= 'z')cout << "Lowercase" << endl;
	else if (c >= 'A' && c <= 'Z')cout << "Uppercase" << endl;
	else if (c >= '0' && c <= '9')cout << "Digit" << endl;
	else cout << "Other symbol" << endl;
	*/

	//Task 4
	/*short d;
	cin >> d;
	if (d == 1)cout << "Monday" << endl;
	else if (d == 2)cout << "Tuesday" << endl;
	else if (d == 3)cout << "Wednesday" << endl;
	else if (d == 4)cout << "Thursday" << endl;
	else if (d == 5)cout << "Friday" << endl;
	else if (d == 6)cout << "Saturday" << endl;
	else (d == 7)cout << "Sunday" << endl;
	*/

	//Task 5
	/*int a;
	cin >> a;
	cout << int(log2(a)) + 1 << endl;
	*/

	//Task 6
	/*float x, y, a;
	*const float EPS=0.00001;
	cin >> x >> y >> a;
	a /= 2;
	cout << "A(" << x << "," << y<<") is ";
	if (	(	abs(abs(x)-a)<=EPS && abs(y)-a <= EPS)
			|| abs(abs(y)-a)<=EPS && abs(x)-a <= EPS)
		cout << "ON";
	else if (abs(x)-a <-EPS && abs(y)-a < EPS)cout << "INSIDE";
	else cout << "OUTSIDE";
	cout <<" the rectangle"<<endl;
	*/

	//Task 7
	/*int h, m;
	char c;
	cin >> h >> c >> m;
	if (c != ':' || (h < 0 || h>23) || (h == 24 && m) || (m < 0 || m>59))
		cout << "Wrong time!";
	else if (h < 11)cout << "Good morning!";
	else if (h < 19)cout << "Good day!";
	else cout << "Good night!";
	*/

	//Task 8
	/*double a, b;
	char op;
	cin >> a >> op >> b;
	if (op == '+')cout << a + b << endl;
	else if (op == '-')cout << a - b << endl;
	else if (op == '/')cout << a / b << endl;
	else if (op == '*')cout << a * b << endl;
	*/

	//Task 9
	/*int month;
	cin >> month;
	if (month == 1 ||
		month == 3 ||
		month == 5 ||
		month == 7 ||
		month == 8 ||
		month == 10 ||
		month == 12)cout << "31" << endl;
	else if (month == 4 ||
		month == 6 ||
		month == 9 ||
		month == 11)cout << "30" << endl;
	else cout << "God knows!" << endl;
	*/

	//Task 10
	/*int astarthour, astartmin, aendhour, aendmin;
	int bstarthour, bstartmin, bendhour, bendmin;
	char c;
	cin >> astarthour >> c >> astartmin>>aendhour>>c>>aendmin;
	cin >> bstarthour >> c >> bstartmin >> bendhour >> c >> bendmin;
	int astarttime = 60 * astarthour + astartmin;
	int bstarttime = 60 * bstarthour + bstartmin;
	int aendtime = 60 * aendhour + aendmin;
	int bendtime = 60 * bendhour + bendmin;

	if (astarttime > bendtime || bstarttime > aendtime)cout << "No meeting!" << endl;
	else if (astarttime > bstarttime) {
		cout << astarthour << c;
		cout.fill('0');
		cout.width(2);
		cout << astartmin;
	}
	else cout << bstarthour << c;
	cout.fill('0');
	cout.width(2);
	cout<< bstartmin;
	*/

	//Task 11
	unsigned int egn;
	int add=1900;
	cin >> egn;
	unsigned int m = (egn / 1000000) % 100,month=m;
	if (month > 40  && month < 53) {
		month -= 40; add = 2000;
	}
	else if (month > 20 && month < 33) {
		month -= 20; add = 1800;
	}
	else if (!(month > 0 && month < 13)) {cout << "Invalid ID" << endl; return 0;}

	unsigned int year = egn / 100000000;
	unsigned int day = (egn / 10000) % 100;

	if ((month == 1 ||
		month == 3 ||
		month == 5 ||
		month == 7 ||
		month == 8 ||
		month == 10 ||
		month == 12) && day >31 ){cout << "Invalid ID"; return 0; }
	else if ((month == 4 ||
		month == 6 ||
		month == 9 ||
		month == 11) && day > 30){cout << "Invalid ID"; return 0; }
	else if(month==2 && 29-year%4<day) { cout << "Invalid ID"; return 0; }
	int S = 0;
	S += ((year / 10 - day % 10) * 2 +
		(year % 10 - (egn / 1000) % 10) * 4 +
		(m / 10 - (egn / 100) % 10) * 8 +
		(m % 10 - ((egn / 10) % 10)) * 5 -
		(day / 10)
		);
	S %= 11;S %= 10;
	if(S!=egn%10) { cout << "Invalid ID"; return 0; }
	cout << "Birthday: " << day << '/' << month << '/' << year + add << endl;
	cout << "Gender: " << (((egn / 10) % 10) % 2 ? "Female" : "Male") << endl;

	return 0;
}