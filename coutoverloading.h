#pragma once
#include "util.h"

class fraction {
public:
	fraction(int n = 0, int d = 1) : numerator_(n), denominator_(d) {
		cout << "In fraction constructor \n";
	}

	~fraction() {
		cout << "In fraction destructor \n";
	}

	int numerator() const {
		return numerator_;
	}

	int denominator() const {
		return denominator_;
	}

	friend ostream& operator<<(ostream& o, const fraction& a); // friend functions can access all the private members of a class without jusing class instance

private:
	int numerator_;
	int denominator_;
	fraction(const fraction& a);
	fraction& operator=(const fraction& rhs);
};