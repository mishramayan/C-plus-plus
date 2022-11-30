#include "Class1.h"


void group::set_age(int a) {
	age_ = a;
}

void group::set_name(const char* s) {
	strcpy(name_, s);
}

void group::set_male() {
	is_male_ = true;
}

void group::set_female() {
	is_male_ = false;
}

bool group::is_male() const {
	return is_male_;
}

int group::age() const {
	return age_;
}

void group::print() const{
	// age_ = 18; -->> Won't be able to change anything as the function is defined as const. Nothing can be changed within it 
	cout << "Name : " << name_ << " | Age : " << age_ << " | Is Male : " << is_male_ << endl;
}


void accessing_private_elements_of_a_class() {
	group g;
	//g.age_ = 17; --> This won't work here as we're trying to access private member  
	g.set_age(17); 
	g.set_name("May");
	g.set_male();
	g.print();

}
 
int main() {

	accessing_private_elements_of_a_class();
	return 0;
}