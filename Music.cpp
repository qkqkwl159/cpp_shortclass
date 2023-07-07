#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


class MusicInfo{
	string song[3];
	string answer[3];
	int index;

	public:
	  MusicInfo(){
			srand(time(0));
			index = rand() % 3;
			song[0] = "Falling inlove with you";
			song[1] = "OMG";
			song[2] = "Oasis";
		  answer[0] ="Elvis"; 
		  answer[1] ="NewJeans";
			answer[2] = "Crush";
		}
		string getAnswer(){
			return answer[index];
		}

		void printMusicInfo(){
			cout << song[index] + " 를 부른 가수는\n" ;
			cout << "(HINT : First Character is " << answer[index][0] <<")? ";

		}
};


class CheckMusic{
	MusicInfo info;
	string singer;
	string musicAnswer;
	public:
	  void checkMusicRun(){
			info.printMusicInfo();
			check();
		}
		void check(){
			musicAnswer = info.getAnswer();
			getline(cin,singer);
			if(singer == musicAnswer){
				cout << "Correct\n";
			}
			else{
				cout << "Not Answer.\n";
				cout << "Answer is "<< musicAnswer << endl;
			}
		}
};


int main(){
	CheckMusic cm;
	cm.checkMusicRun();
	return 0;
}


