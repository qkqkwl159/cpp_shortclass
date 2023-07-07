#include <iostream>

using namespace std;

class A{
	public:
		A(){ cout << "construc A" << endl;}
		A(int x){
			cout << "매개변수 생성자 A : " << x << endl;
		}
		~A() { cout << "deconstruct A" <<endl; }
};


class B : public A{
	public:
		B(){ cout << "construc B" << endl;}
		B(int x): A(x){
			cout << "매개변수 생성자 B : " << x << endl;
		}
		~B() { cout << "deconstruct B" <<endl; }
};

class C :public B{
	public:
		C(){ cout << "construc C" << endl;}
		~C() { cout << "deconstruct C" <<endl; }
};

int main(int argc, char *argv[]){
	B b(5);

	return 0;

}
