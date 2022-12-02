#pragma once
#pragma once
#include "util.h"

class student {
private:
	int age_;
	char* name_;
	bool is_male_;

public:
	void print() const;
	void init(const char* name, int age, bool m = true);  // --> Constructor (explanation)
	void fini() {  // --> Destructor (explanation)
		delete[] name_;  // --> Deleting this memory allocated from HEAP
	}
	void change_age(int i) { age_ = i; };
	void pass_by_value(student t);
};