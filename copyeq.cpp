#include "copyeq.h"

book::book(const char* s, int c, bool x) : name_(nullptr), cost_(c), in_(x)
{
	cout << "In book constructor " << s << endl;
	int l = strlen(s) + 1;
	name_ = new char[l];
	strcpy(name_, s);
}

book::~book()
{
	cout << "In book destructor " << name_ << endl;
	release();
}

book::book(const book& b)
{
	cout << "In copy constructor " << b.name_ << endl;
	copy(b);
}

void book::release()
{
	cout << name_ << endl;
	delete[] name_;
}

book& book::operator=(const book& rhs)
{
	cout << "In equal operator " << rhs.name_ << endl;
	if (this != &rhs) {
		release();  // Since obj already exist so we have to clear its memory to copy other object's value
		copy(rhs);  // after releasing the memory now we will copy the value from desired object to this object
	}
	// TODO: insert return statement here
	return *this;
}

void book::print() const
{
	cout << "Name of the Book : " << name_ << " | Cost of the Book : " << cost_ << " | Is available : " << (in_ ? "YES" : "NO") << endl << endl;
}

void book::copy(const book& from)
{
	int l = strlen(from.name_) + 1;
	name_ = new char[l+1];

	strcpy(name_, from.name_);
	cost_ = from.cost_;
	in_ = from.in_;
}


