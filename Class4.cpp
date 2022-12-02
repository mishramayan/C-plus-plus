#include "Class4.h"

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

void pass_by_value(student t) {
	t.print();
	t.change_age(45);
	t.print();
	//t.fini(); -> code crash on line number 29because pointing to same memory on heap
}

void pass_by_value_test() {
	student s;
	s.init("May", 27, true);
	pass_by_value(s);
	s.print();
	s.fini();
	cout << endl << endl;
}

student return_by_value() {
	student t;
	t.init("May", 27, true);
	return t; // t will bbe phtocopied to k
}


//This code will run as a is pointing to the same memory on heap as t. But if we add t.fini func there the code will fail as it won't get anything to print and delete 

void return_by_value_test() {
	student a = return_by_value();
	a.print();
	a.fini();
	cout << endl << endl;
}

int main() {

	pass_by_value_test();
	return_by_value_test();
	return 0;
}



// OUTPUT
//Name : May | Age : 27 | Gender : Male -> First time we print directly through obj
//Name : May | Age : 45 | Gender : Male -> passed age as value so print 45
//Name : May | Age : 27 | Gender : Male -> again it will print 27 as the pass_by_value func ends and all the changes are reverted back with the closing braces