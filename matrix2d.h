#pragma once
#include "util.h"

class matrix2d {
public:
	void init(int a = 0, int b = 0, int c = 0);
	void init(const char* s);
	void print(const char* t) const;
	void fini();
	matrix2d add(matrix2d a);
	matrix2d mult(matrix2d a);
	bool isEqual(const matrix2d& a) const;
	bool isEmpty() const;

private:
	int row_;
	int col_;
	int val_;
	int** m_;

	void set_(int v);
};