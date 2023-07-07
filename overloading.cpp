#include <iostream>


using namespace std;

class Base{
	public:
		virtual void f() { cout << "Base::f() called" << endl; }
};


class derived : public Base{
	public:
		call
		virtual void f() { cout << "call derived::f() called" << endl; }
};

int main(int argc, char *argv[]){

	derived d, *pder;
	pder = &d;
	pder->f();

	Base * pBase;
	pBase = pder;
	pBase->f();

	return 0;
}
