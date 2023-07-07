#include <iostream>
#include "calcul.h"

using namespace std;

Calculator::Calculator(){
	cout << "두 수 입력 >>";
	cin >> op1 >> op2;
}

void Calculator::Subtractor(){
	cout << op1 - op2 << "::" << endl;
}
