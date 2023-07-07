#include<iostream>
//#include<conio.h>

using namespace std;

//#define LEFT = 75;
//#define RIGHT = 77;



class CoinCase{
	private:
		int coin;

//	CoinCase::CoinCase(){
//		coin = 0;
//	}

	public:
		void insert(int amount){
			coin += amount;

		}
		void use(){
			coin--;
		}

};



class Drinks{
	public:
		void monster(){
			cout << "Monsert out!\n";
		}
		void coke(){
			cout << "Coke out!\n";
		}
};

class Interface{
	private:
		int curitem;
	public:
		void basic(int lonum){
			cout << "---------------------\n";
			cout << "| 1 | 2 | 3 | 4 | 5 | \n";
			cout << "---------------------\n";
			cout << "---------------------\n";
			switch(lonum){
				case 1:
					location1();
					break;
				case 2:
					location2();
					break;
				case 3:
					location3();
					break;
				case 4:
					location4();
					break;
				case 5:
					location5();
					break;
				case 6:
					select(curitem);
					cout << "---------------------\n";
					break;
			}
			cout << "---------------------\n";
		}

		void location1(){
			cout << "| 0 |   |   |   |   |\n";
			curitem = 1;
		}
		void location2(){
			cout << "|   | 0 |   |   |   |\n";
			curitem = 2;
		}
		void location3(){
			cout << "|   |   | 0 |   |   |\n";
			curitem = 3;
		}
		void location4(){
			cout << "|   |   |   | 0 |   |\n";
			curitem = 4;
		}
		void location5(){
			cout << "|   |   |   |   | 0 |\n";
			curitem = 5;
		}
		void select(int itemnum){
			switch(itemnum){
				case 1:
					cout << "1 item\n";
					break;
				case 2:
					cout << "2 item\n";
					break;
				case 3:
					cout << "3 item\n";
					break;
				case 4:
					cout << "4 item\n";
					break;
				case 5:
					cout << "5 item\n";
					break;
				}
			}

};


class Move{
	private:
		Interface interface;
	public:
		void mv(int leri){
			if(leri == 'l')
				cout << "l\n";
			else if(leri == 'r')
				cout << "r\n";
			else if(leri == 's')
				cout << "s\n";
			else
				cout << "Error!\n";
		}

};



class VendingMachine{
	private:
		CoinCase coinCase;
		Drinks drink;
		Interface interface;
		Move move;
	public:

		void run(){
			cout << "Machine runs" << endl; 
		}

		void insertCoin(int amount){
			cout << "Conin inserted: " << amount<< endl;
			coinCase.insert(amount);
		}

		void useCoin(int coin){
			cout << "use coin\n";
			coinCase.use();


			drink.monster();
		}
		void printscr(int selectItem){
			interface.basic(selectItem);
		}

		void mvtest(int movepara){
			move.mv(movepara);
		}
};

int main(int argc, char* argv[]){

	int coin = 0;

	int move;

	VendingMachine vm;

	cout << "Plz input Coin : ";
	cin >> coin;

	vm.insertCoin(coin);
	while(coin > 0){
		cout << "Move  1,2,3,4,5 : num , s : select\n";
		cin >> move;
		vm.printscr(move);
		vm.useCoin(coin);

	}
	cout << "Zero Coin\n";

	vm.mvtest(move);

	return 0;
}
