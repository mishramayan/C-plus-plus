#include "Class2.h"

void student::init(const char* s, int a, bool m) {
	age_ = a;
	//strcpy(name_, s); --> This can't be done as name_ is just a pointer pointing to some space we've to allocate definite space to fill
	name_ = new char[strlen(s) + 1];
	strcpy(name_, s); // --> Now this will copy the parameter to name_ variable
	is_male_ = m;
}

void student::print() const {
	cout << "Name : " << name_ << " | Age : " << age_ << " | Gender : "; 
	cout << (is_male_ ? "Male" : "Female") << endl;
}

void allocating_on_stack() {
	student s;
	s.init("May", 27, true);
	s.print();

	student a;
	a.init("Ashley", 25, false);
	a.print();

	student c[5];
	for (int i = 0; i < 5; i++) {
		char n[10];
		strcpy(n, "student");
		char p[2];
		p[0] = i + '0';
		p[1] = '\0';

		strcat(n, p);
		c[i].init(n, 20 + i, (i % 2) ? true : false);
	}
	for (int i = 0; i < 5; i++) {
		c[i].print();
		c[i].fini();
	}
	s.fini();
	a.fini();  // --> removing space allocated to name_ variable from heap
}

int main() {

	allocating_on_stack();
	return 0;
}