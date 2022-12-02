#include "Class3.h"

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

void allocating_on_heap1() {
	cout << "ALLOCATING ON HEAP 1" << endl;
	cout << "----------------------" << endl;
	student* s = new student; // Creating a pointer pointing to object on heap
	s->init("May", 27, true);   //  '->' this notatiion is used when pointer is pointing on object created on HEAP
	(*s).print();  // (*s).func() can use this notation also. This means getting object 's' pointer then calling the function

	student* a = new student; // Creating a pointer pointing to object on heap
	a->init("Ashley", 25, false);
	a->print();

	student* c = new student[5]; // Creating a pointer pointing to object on heap
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
	s->fini();
	a->fini();  // --> removing space allocated to name_ variable from heap
	cout << endl << endl;
}

void allocating_on_heap2() {
	cout << "ALLOCATING ON HEAP 2" << endl;
	cout << "----------------------" << endl;
	student* s = new student; // Read from right new student creates space for student object on heap all garbage
							// then s is created on stack which is pointing to the space created on heap
	s->init("May", 27, true); // init is called "May" is in heap and name_ is pointing to it 
								//  '->' this notatiion is used when pointer is pointing on object created on HEAP
	(*s).print();  // (*s).func() can use this notation also. This means getting object 's' pointer then calling the function

	student* a = new student; // Creating a pointer pointing to object on heap
	a->init("Ashley", 25, false);
	a->print();

	student** c = new student*[5]; // Creating a pointer to the pointer pointing to object on heap
	for (int i = 0; i < 5; i++) {
		char n[10];
		strcpy(n, "student");
		char p[2];
		p[0] = i + '0';
		p[1] = '\0';

		strcat(n, p);

		c[i] = new student;
		c[i]->init(n, 20 + i, (i % 2) ? true : false);
	}
	for (int i = 0; i < 5; i++) {
		c[i]->print();
		c[i]->fini();
		delete c[i];
	}
	delete[] c;
	s->fini();
	a->fini();
	delete s;
	delete a; 
}

int main() {

	allocating_on_heap1();
	allocating_on_heap2();
	return 0;
}