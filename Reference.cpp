//REFERENCE

#pragma warning(disable : 4996)
#include <iostream>
using namespace std;


const char* a[] = { "MIT", "UCB" };

void f1(const char* d) {
	cout << "add d - " << &*d << endl;
	d = a[1];
	cout << "d = " << d << endl;
}

void f1(const char** d) {
	*d = a[1];
	cout << "d = " << *d << endl;
}

void f2(const char*& d) {
	d = a[1];
	cout << "d = " << d << endl;
}

void swap1(int i, int j) {
	int t = i;
	i = j;
	j = t;
	cout << "Pass By Value" << endl;
	cout << "---------------------------" << endl;
	cout << "Case 1 (Inside SWAP function) : x = " << i << " y = " << j << endl;
}

void swap2(int* i, int* j) {
	int temp = *i;
	*i = *j;
	*j = temp;
	cout << "Pass By Address/Pointers" << endl;
	cout << "---------------------------" << endl;
	cout << "Case 2 (Inside SWAP function) : x = " << *i << " y = " << *j << endl;
}

void swap3(int& i, int& j) {
	int temp = i;
	i = j;
	j = temp;
	cout << "Pass By Reference" << endl;
	cout << "---------------------------" << endl;
	cout << "Case 3 (Inside SWAP function) : x = " << i << " y = " << j << endl;
}

void f(int x, int& y, int* p) {
	x = 20;
	*p = 80;
	y = 40;
	x = 700;
	//*p = 0;
	//y = 1;
}

int main() {
	{
		const char p1[4] = "MIT";
		char* p = new char[4];
		strcpy(p, "NPU");
		cout << p << endl;
		p[0] = 'L';

		////Can't be updated as p1 is const and cannot be changed
		////p1[0] = 'K';
		cout << p << endl;

		int i = 40;
		int& y = i;

		int j = 30;
		int* q = &j;

		y = 10;

		cout << "i = " << i << " & y = " << y << endl;
		cout << "j = " << j << " & q = " << *q << endl;
		*q = 60;

		cout << "j = " << j << " & q = " << *q << endl << endl;
	}

	{
		int x = 10;
		f(x, x, &x);
		cout << x << endl << endl;
	}


	//Pass By Value
	{
		int x = 10;
		int y = 20;
		cout << "Original : x = " << x << " y = " << y << endl << endl;
		swap1(x, y);
		cout << "Case 1 (Outside SWAP function) : x = " << x << " y = " << y << endl << endl;
	}

	//Pass By Address/Pointer
	{
		int x = 10;
		int y = 20;
		swap2(&x, &y);
		cout << "Case 2 (Outside SWAP function) : x = " << x << " y = " << y << endl << endl;
	}

	//Pass By Reference
	{
		int x = 10;
		int y = 20;
		swap3(x, y);
		cout << "Case 3 (Outside SWAP function) : x = " << x << " y = " << y << endl << endl;
	}

	{
		const char* c = a[0];
		cout << &c << endl;
		cout << "c1 = " << c << endl;
		f1(c);
		cout << "c2 = " << c << endl;
		cout << "---------------------------" << endl;
		cout << "c3 = " << c << endl;
		f1(&c);
		cout << "c4 = " << c << endl;
		cout << "---------------------------" << endl;
		c = a[0];
		cout << "c5 = " << c << endl;
		f2(c);
		cout << "c6 = " << c << endl;
		cout << "---------------------------" << endl;
	}


	return 0;
}