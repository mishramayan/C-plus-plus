#pragma once
#include "util.h"

class book {
public:
	book(const char* s, int c = 0, bool x = false);
	~book();
	book(const book& b);
	book& operator=(const book& rhs);
	void print() const;

private:
	void copy(const book& from);
	char* name_;
	int cost_;
	bool in_;
	void release();
};