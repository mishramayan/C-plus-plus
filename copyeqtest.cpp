#include "copyeq.h"

void test_copy_const_equal_oper() {

	book b1("algorithm"); // b1 in STACK and algorith in HEAP
	book b2("C++", 49); // b2 in STACK and C++ in HEAP
	book b3("JAVA", 168, true); // b3 in STACK and JAVA in HEAP
	book b4(b2); // calling Copy constructor. 
	book b5 = b1; // invoke copy constructor as b5 is newly created and we're copying b1 to b5
	b1.print();
	b2.print();
	b3.print();
	b4.print();
	b5.print();
	b1 = b3; // Invoke equal operator as b3 and b1 already exist. release b1 memory and then copy value from b3
	b1 = b2 = b4 = b3; // Equal operator from left to right
	b1.print();
	b2.print();
	b3.print();
	b4.print();

}

int main() {
#ifdef _WIN32
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	test_copy_const_equal_oper();
	return 0;
}