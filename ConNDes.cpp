#include "ConNDes.h"

book1::book1()
{
	cout << "In book1 Default Constructor" << endl;
}

book1::book1(const char* s, int c, bool x) : name_(nullptr), cost_(c), in_(x) // Baseline initialization
{
	cout << "In book1 Constructor" << endl;

	auto l = strlen(s) + 1;
	this->name_ = new char[l];

	strcpy(name_, s);
}

book1::~book1() // Destructor automatically called
{
	cout << "In book1 Destructor " << name_ << endl;
	delete[] name_;
}

void book1::print() const
{
	cout << "Name of the Book : " << name_ << " | Cost of the Book : " << cost_ << " | Is available : " <<  (in_ ? "YES" : "NO") << endl << endl;
}



int main() {
	//book1 b; --> Calls default constructor
	book1 b1("C++");
	b1.print();
	book1 b2("Algo", 49, true);
	b2.print();
	book1 b3("JAVA", 19.99, false);
	b3.print();
	book1* b4 = new book1("Python", 289, 1);
	(*b4).print();/*
	b4->print();*/ // Both are correct way of calling
	delete b4;
	return 0;
}