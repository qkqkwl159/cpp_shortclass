#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <vector>

using namespace std;

class GameObject{
	public:
		int x;
		int y;
		virtual void Draw() { }
		virtual bool Update() { return true; }
};

class Player : public GameObject {
	public:
		int x;
		int y;
		Player() { x = 10, y = 10;}
		void Draw(){
			move(y,x);
			printw(" * ");
			move(y+1,x);
			printw("=-=");
		}
		void KeyboardHandler(int key){
			switch(key){
				case 'k' : y--; break;
				case 'j' : y++; break;
				case 'h' : x--; break;
				case 'l' : x++; break;
			}
		}
};



class Missle : public GameObject{
	int x;
	int y;
	public:
		void Draw(){
			move(y,x);
			printw(" * ");
		}
		bool Update(){
			y--;
			if (y< 0){
				return false;
			}
			return true;
		}

		Missle(Player *player){
			this->x = player->x;
			this->y = player->y;
		}

};
class GameEngine{
	private:

// 미사일누르면 객체생성 객체를담는 백터가 있어야하고 -> 미사일 백터 for문에서 하나씩 draw
		bool isPlaying;
		Player *player;
		vector<GameObject*> GameObjvec;
		void fire(){
			GameObjvec.push_back(new Missle(player));
		}
		void DrawGameObject(){
			for(int i = 0; i< GameObjvec.size();i++)
				GameObjvec[i]->Draw();
		}
					
		void DrawPlayer() { player->Draw(); }
		void DrawMissile() {
			for(int i = 0; i< GameObjvec.size() ; i++)
				GameObjvec[i]->Draw();
		}
		void EngineKeyboardHandler(int key){
			if(key == 'q')
				isPlaying = false;
			else if (key == 'f')
				fire();
		}
//			if(key == 'q')
//				isPlaying = false;
//			else
		//
			
		void UpdateGameObject(){
			for(int i = 0; i< GameObjvec.size() ; i++){
				if(GameObjvec[i]->Update() == false){
				}
			}
				//GameObjvec[i]->Draw();
		}
		void HandleKeyboard() {
			int key = getch();
			EngineKeyboardHandler(key);
			player->KeyboardHandler(key);
		}
	public:
		GameEngine() { 
			isPlaying = true; 
			player = new Player();
		}
		void Run(){
			while(isPlaying){
					clear();
					UpdateGameObject();
					DrawGameObject();
					HandleKeyboard();
					refresh();
			}
		}

};

class Game{
	GameEngine *engine;
	public:
		Game(){ engine = new GameEngine(); }
		~Game() { delete engine; }
		void Run() { engine->Run(); }
};

void game(){
	Game *game= new Game;
	game->Run();
	delete game;
};

void initCurses() {
	initscr();
	curs_set(0);
}

void endCurses(){
	endwin();
}

int main(int argc, char* argv[]){

	initCurses();

	game();

	endCurses();
	return 0;
}
