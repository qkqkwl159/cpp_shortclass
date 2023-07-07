#include <iostream>
#include <string>
#include "stringparser.h"
#include "calculator.h"

using namespace std;

StringParser::StringParser(){
	getline(cin, s, '\n');
	startIndex = 0;
}

void StringParser::parser(int sum){
	while(true){
		fIndex = s.find('+', startIndex);
		if(fIndex == -1){
			part = s.substr(startIndex);
			if(part == "") break;
			cout << part << endl;
			sum += stoi(part);
			break;
		}
		int count = fIndex - startIndex;
		string part = s.substr(startIndex, count);
		cout << part << endl;
		sum += stoi(part);
		startIndex = fIndex + 1;
	}
	cout << "숫자들의 합은 " << sum << endl;
}

