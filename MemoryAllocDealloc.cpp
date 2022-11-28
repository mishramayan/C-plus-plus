#pragma warning(disable : 6386)
#pragma warning(disable : 6385)
#pragma warning(disable : 4996)
#include <iostream>
using namespace std;


void f(int n) {
	//int a[n] = { 1, 2 }; --> This won't work as it is expecting a constant value here instead of 'n'
	int a[2] = { 1, 2 };

	int* b = new int[n];

	b[0] = 1;
	b[1] = 2;

	cout << b[0] << " " << b[1] << endl << endl;

	delete[] b; //deleting the array from heap memory
}

void f() {
	int* p = new int(27);
	cout << "address of p : " << p << " value of p : " << *p << endl;
	delete(p);

	char* q = new char('M');
	cout << "value of q : " << *q << endl << endl;
	delete(q);
}

void test_obj(int n) {
	class student {
	public:
		int age;
		char* id;
	};
	student* a = new student;
	(* a).age = 27; //does same this as a->age
	a->age = 25;

	(*a).id = new char[6];
	a->id = new char[12];
	strcpy(a->id, "NU001546926");
	cout << "Student id : " << a->id << " Student age : " << a->age << endl << endl;

	delete[] a->id;
	delete(a);
}

void q(int* x) {
	*x = 20;
	cout << *x << endl;
	//delete(x); // if I delete the pointer here in main x won't be pointing to a memory which will give error
}


// Two dimensional Array //

void print_(const char* s, int R, int C, int x[][2]) {
	cout << s << endl;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
}

void update(int R, int C, int x[][2], int m) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			x[i][j] += m;
		}
	}
}

// STATIC 2D ARRAY - STATIC ROW AND STATIC COL//
void tdarray() {
	cout << "STATIC 2D ARRAY - STATIC ROW AND STATIC COL" << endl;
	const int R = 3;
	const int C = 2;
	int x[R][C] = { {1, 2}, {13, 14}, {25, 26} };

	cout << "Size of array x - " << sizeof(x) << endl;
	print_("Before : ", R, C, x);
	update(R, C, x, 5);
	print_("After : ", R, C, x);
}

void fill(int x[][2]) {
	cout << "Into fill func." << endl;
	int R = 3;
	int C = 2;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			x[i][j] = i+j;
		}
	}
}

// DYNAMIC 2D ARRAY - DYNAMIC ROW BUT STATIC COL//
void dynamic_array_2d(int R) {
	cout << "DYNAMIC 2D ARRAY - DYNAMIC ROW BUT STATIC COL" << endl;
	const int C = 2;
	int(*x)[C] = new int[R][C];
	fill(x);
	cout << "Size of array x - " << sizeof(x) << endl;
	print_("Before : ", R, C, x);
	update(R, C, x, 5);
	print_("After : ", R, C, x);
	delete[] x;  /*--> Because x is a pointer pointing to memory created on heap*/
}

void fills(int** a, int R, int C) {
	int x[3][2] = { {0,1}, {2,3}, {4,5} };
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {

			a[i][j] = x[i][j];
		}
	}
}


void print_(const char* s, int R, int C, int** x) {
	cout << s << endl;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
}

void update(int R, int C, int** x, int m) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			x[i][j] += m;
		}
	}
}


// DYNAMIC 2D ARRAY - DYNAMIC ROW AND DYNAMIC COL//
void dynamic_array_2d(int R, int C) {
	cout << "DYNAMIC 2D ARRAY - DYNAMIC ROW AND DYNAMIC COL" << endl;
	int** x = new int* [R]; // Creating 'R' number of spaces in heap. Storing pointers to arrays  
	
	cout << "Size of array x - " << sizeof(x) << endl;
	for (int i = 0; i < R; i++) {
		x[i] = new int[C];
	}
	fills(x, R, C);
	print_("Before : ", R, C, x);
	update(R, C, x, 5);
	print_("After : ", R, C, x);

	for (int i = 0; i < R; i++) {
		delete[] x[i];
	}

	delete[] x;
}

// MAIN FUNCTION //
int main() {
	int n = 2;
	f(n);
	f();
	tdarray();
	cout << endl;
	test_obj(10);
	int* x = new int(10);
	q(&*x);
	cout << *x << endl << endl;
	dynamic_array_2d(3);
	cout << *x << endl << endl;
	dynamic_array_2d(3, 2);
	return 0;
}