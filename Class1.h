#pragma once
#include "util.h"

class group {
private:
	int age_;
	char name_[100];
	bool is_male_;

public:
	void set_age(int a);
	int age() const;
	void set_male();
	void set_female();
	bool is_male() const;
	void set_name(const char* s);
	const char* name() const;
	void print() const;
};