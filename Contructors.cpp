#include "Contructors.h"

student2::student2() {
}

student2::student2(const char* s, int c, bool x) : name_(nullptr), age_(c), is_male_(x) {
	
	auto l = strlen(s);

	name_ = new char[l];
	strcpy(name_, s);

	cout << "In student2 Constructor " << name_ << endl;
}

student2::~student2() {
	cout << "In student2 Destructor " << name_ << endl << endl;
	//delete[] name_;
}

void student2::print() const {
	cout << "Name of the Student : " << name_ << " | Age of the Student : " << age_ << " | Gender : " << (is_male_ ? "Male" : "Female") << endl << endl;
}

void pass_by_value(student2 o) {
	o.print();
	o.change_age(40);
	o.print();
} // Destructor for 'may' will be invoked here

void pass_by_value_test() {
	student2 may("May", 27, 1);
	pass_by_value(may);
	may.print(); // Program will crash here because name_ is already deleted after above function and here it will try to print something that does not exist
}

student2 return_by_value() {
	student2 ash("Ashley", 25, 0); // Calls the constructor
	return ash;
}

void return_by_value_test() {
	student2 k = return_by_value();
	k.print();
}

int main() {

	pass_by_value_test();
	return_by_value_test();
	return 0;
}