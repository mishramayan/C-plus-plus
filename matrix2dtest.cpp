
#include "matrix2d.h"
/*----------------------------------------------------------------
test init (Constructor) and fini (Destructor)
-----------------------------------------------------------------*/
static void test_init_fini() {
	matrix2d a;
	a.init();
	a.print("Matrix a");
	matrix2d b;
	b.init(3, 4);
	b.print("Matrix b");
	matrix2d c;
	c.init(2, 0, 7);
	c.print("Matrix c");
	matrix2d d;
	d.init(0, 10, 7);
	d.print("Matrix d");
	matrix2d e;
	e.init(3, 10, 7);
	e.print("Matrix e");
	matrix2d f;
	f.init("1 2|3 4|5 6");
	f.print("Matrix e");
	matrix2d g;
	g.init(" 1 2 |3 4 |5 6  ");
	g.print("Matrix g");
	assert(f.isEqual(g));
	assert(g.isEqual(f));
	matrix2d h;
	h.init(" 1 2 |3 4 |5 6 8 ");
	h.print("Matrix h");
	assert(h.isEmpty());
	assert(!f.isEqual(h));
	a.fini();
	b.fini();
	c.fini();
	d.fini();
	e.fini();
	f.fini();
	g.fini();
}
/*----------------------------------------------------------------
test add1
-----------------------------------------------------------------*/
static  void test_add1(const char* as, const char* bs, const char* anss) {
	matrix2d a;
	a.init(as);
	a.print("Matrix a");
	matrix2d b;
	b.init(bs);
	b.print("Matrix b");
	matrix2d s = a.add(b);
	s.print("matrix s");
	matrix2d ans;
	ans.init(anss);
	ans.print("matrix expected ans");
	assert(s.isEqual(ans));
	assert(ans.isEqual(s));
	a.fini();
	b.fini();
	s.fini();
	ans.fini();
}
///*----------------------------------------------------------------
//test add
//-----------------------------------------------------------------*/
static  void test_add() {
	test_add1("7 9 11|13 15 17 ", " 6 8 10| 12 14 16 ", "13 17 21 | 25 29 33");
	test_add1("1 2 3|4 5  6 ", "1 2  ", "");
}
///*----------------------------------------------------------------
//test mult1
//-----------------------------------------------------------------*/
static void test_mult1(const char* as, const char* bs, const char* anss) {
	matrix2d a;
	a.init(as);
	a.print("Matrix a");
	matrix2d b;
	b.init(bs);
	b.print("Matrix b");
	matrix2d s = a.mult(b);
	s.print("matrix s");
	matrix2d ans;
	ans.init(anss);
	ans.print("matrix expected ans");
	assert(s.isEqual(ans));
	assert(ans.isEqual(s));
	a.fini();
	b.fini();
	s.fini();
	ans.fini();
	cout << "----------------------------------\n";
}
///*----------------------------------------------------------------
//test mult
//-----------------------------------------------------------------*/
static void test_mult() {
	test_mult1("1 2 3", " 2 1 3 | 3 3 2| 4 1 2  ", "20 10 13");
	test_mult1("3 4 2", "13 9 7 15|8 7 4 6| 6 4 0 3 ", "83 63 37 75");
	test_mult1("3", "5 2 11|9 4 14", "15 6 33|27 12 |42");
	const char* a = "3 9 0 2 2 9 5 2|0 2 2 1 9 6 6 8|7 5 6 1 4 9 8 9|3 3 2 9 2 1 7 4|1 9 0 1 2 9 5 2 | 4 2 0 3 7 3 9 1 | 5 9 0 6 6 7 8 2 | 9 3 4 6 8 4 9 1" ;
	const char* b = "6 1 6 0 8 3 0 0|6 8 9 0 6 6 7 2|4 8 2 0 5 4 6 7|2 4 4 2 2 6 9 8|4 8 2 2 4 6 4 1 | 1 5 5 6 4 7 5 5 | 7 4 6 5 0 6 5 3 | 2 3 7 0 1 3 8 5";
	const char* s = "132 170 200  87 128 186 175 106|122 186 166  86  92 182 195 123|197 235 267 104 179 243 253 178 | 128 140 164  63  86 162 194 140 | 118 164 184  85 110 174 166  98 | 138 142 144  83  91 162 137  82 | 187 222 244 106 160 244 232 141 | 201 212 210  97 171 230 204 142";
	test_mult1(a, b, s);
	test_mult1("7 3|2 5 | 6 8| 9 0", "8 14 0 3 1|7 11 5 91 3|8 4 19 5 57", "");
}
/*----------------------------------------------------------------
test bed
-----------------------------------------------------------------*/
static void testbed() {
	cout << "CONSTRUCTOR AND DESTRUCTORS CALL" << endl;
	cout << "--------------------------------" << endl;
	test_init_fini();
	cout << endl << endl;
	cout << "ADDITION OF TWO 2-D MATRIX" << endl;
	cout << "--------------------------" << endl;
	test_add();
	cout << endl << endl;
	cout << "MULTIPLICATION OF TWO 2-D MATRIX" << endl;
	cout << "--------------------------------" << endl;
	test_mult();
}
/*----------------------------------------------------------------
main
matrix2d
-----------------------------------------------------------------*/
int main() { //mainintmatrix1
#ifdef _WIN32
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	testbed();
	return 0;
}