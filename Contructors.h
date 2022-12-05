#pragma once
#include "util.h"

class student2 {
public:
	student2();
	student2(const char* s, int c = 0, bool x = false);
	~student2();
	void change_age(int i) { age_ = i; }
	void print() const;

private:
	char* name_;
	int age_;
	bool is_male_;
};