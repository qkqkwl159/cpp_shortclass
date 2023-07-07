#include <iostream>

using namespace std;

class Calculator{
	int op1;
	int op2;
	public:
		Calculator();
		void Printer();
		void Subtractor();
		void Adder();
};

Calculator::Calculator(){
	cout << "두 수 입력 >>";
	cin >> op1 >> op2;
}
void Calculator::Printer(){
	cout << op1 << " : " << op2;
}

void Calculator::Subtractor(){

	cout << op1 - op2 << "::" << endl;
}

void Calculator::Adder(){
	cout << op1 + op2 << "::" << endl;
}
int main(int argc, char *argv[]){

	Calculator cal;
	cal.Subtractor();
	cal.Adder();



	return 0;
}
