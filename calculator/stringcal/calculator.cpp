#include <iostream>
#include <string>
#include "calculator.h"

using namespace std;

Calculator::Calculator(){
	sum = 0;
}

void Calculator::run(int sum){
	stringparser.parser(sum);
}
