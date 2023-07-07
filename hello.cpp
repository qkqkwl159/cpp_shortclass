#include <iostream>
//#include <stdio.h>

using namespace std;

//int add() {return 0;}
//
//int add(int num1){
//	return num1;
//}
//
//int add(int a, int b){
//	return a + b;
//}


int add(int num1 = 0, int num2 = 0){
	return num1 + num2;
}


int main(int argc, char* argv[]){

//	cout << "Hello World\n";

	int value = add();
	cout << value << endl;
	value = add(10);
	cout << value << endl;
	value = add(10,40);
	cout << value << endl;



	return 0;

}
