#include <iostream>

using namespace std;

class A{
	public:
		A(){ cout << "construc A" << endl;}
		~A() { cout << "deconstruct A" <<endl; }
};


class B : public A{
	public:
		B(){ cout << "construc B" << endl;}
		~B() { cout << "deconstruct B" <<endl; }
};

class C :public B{
	public:
		C(){ cout << "construc C" << endl;}
		~C() { cout << "deconstruct C" <<endl; }
};

int main(int argc, char *argv[]){

	C c;
	return 0;

}
