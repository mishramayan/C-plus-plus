#include <stdio.h>
#include <iostream>
using namespace std;

class base {
public:
	base(const string& s, int mid = 0, int final = 0){
		cout << "In BASE constructor" << endl;
	};
	~base() { cout << "In BASE destructor" << endl; };

private:
	char* name_;
};


class derived : public base {
public:
	derived(const string& s, const string& e, int m = 0, int f = 0, int p = 0) : base(s, m, f) /*initializing base constructor*/, _examName(e), _project(p) {
		cout << "In DERIVED constructor" << " " << e << endl;
		cout << s << " " << e << " " << m << " " << f << " " << p << endl;
	}
	~derived() { cout << "In DERIVED destructor" << endl; };

private:
	string _examName;
	int _project;

};


int main() {
	base b("Bob", 55, 100);
	derived d("May","Final", 55, 100, 50);
	return 0;
}