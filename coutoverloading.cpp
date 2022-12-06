#include "coutoverloading.h"


//instead of wirting print function we will overload the '<<' cout operator here. 
//We use ostream& beacuse we don't want to invoke the copy constructor that's why we used reference here.
//operator<< is used instead of using print keyword here. ostream is a class name for cout that we will return 
//in this function. fration& a is the object that will be returned

ostream& operator<<(ostream& o, const fraction& a)
{
	o << a.numerator_ << "/" << a.denominator_ << endl;  // --> overloaded the '<<' cout operator
	// TODO: insert return statement here
	return o;
}


int main() {
	int y = 89;
	cout << y << endl;

	fraction x(3,8);
	cout << x;

	return 0;
}