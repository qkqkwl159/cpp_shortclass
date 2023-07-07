#ifndef STRINGPARSER_H
#define STRINGPARSER_H

#include <iostream>
#include <string>

using namespace std;

class StringParser{
	string s;
	string part;
	int startIndex;
	int fIndex;

	public:
		StringParser();
		void parser(int sum);
};

#endif
