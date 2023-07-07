#include "sub.h"

Subtrecter::Subtrecter(int x, int y){
	op1 = x;
	op2 = y;
}

int Subtrecter::process(){
	result = op1 - op2;
	return result;
}
	
