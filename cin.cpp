#include <iostream>
#include <string>

using namespace std;

int main(){
	string song("Falling inlove with you");
	string elvis("Elvis");
	string singer;

	cout << song + "to song singer is";
	cout << "(hint : first charecter is " << elvis[0] << ")?";

	getline(cin,singer);
	if(singer == elvis)
		cout << "correct";
	else
		cout << "not answer ." + elvis << endl;
}
