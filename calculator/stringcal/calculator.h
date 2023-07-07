#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <string>
#include "stringparser.h"

using namespace std;

class Calculator{
	int sum;
	StringParser stringparser;
	public:
		Calculator();
		void run(int sum);
};

#endif
