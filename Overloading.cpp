#pragma warning(disable : 6386)
#pragma warning(disable : 6385)
#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

static void f(const char* n, int m, int b = 0, char g = ' ') { // function overloading with default parameteres
	cout << "Name: " << n << " | Marks: " << m + b << " | Bonus : " << b << " | Grade: " << g << endl;
}

void f(int i) {
	cout << "In f(int) : " << i << endl;
}

void f(double i) {
	cout << "In f(double) : " << i << endl;
}

void f(bool i) {
	cout << "In f(bool) : " << i << endl;
}

//double f(int i) {             -->>  Cannot overload functions with same name same parameters but different return type 
//  
//	return 0.0;
//}

// MAIN FUNCTION //
int main() {

	f("Kay", 70);
	f("May", 60, 20, 'B');
	f(10);
	int i = 125456378;
	f(i);
	f(214.233524);
	f(true);
	f(false);

	return 0;
}