#pragma once
#include "util.h"

class book1 {
public:
	book1();
	book1(const char* s, int c = 0, bool x = false);
	~book1();
	void print() const;

private:
	char* name_;
	int cost_;
	bool in_;
};