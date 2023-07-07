#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <iostream>
#include <vector>

using namespace std;

class GameObject {
	public:
		int x;
		int y;
		virtual void Draw() { }
		virtual bool Update() { return true;}
};

class Enemy :public GameObject {
	public:
		Enemy() { x = 10; y = 0;}
		virtual void Draw() {
			move(y,x);
			printw("X");
		}
		virtual bool Update() {
			y++;
			if (y > 100) {
				return false;
			}
			return true;
		}

};

class Player :public GameObject {
	public:
		Player() { x = 10; y = 10;}
		virtual void Draw() {
			move(y,x);
			printw(" ^ ");
			move(y+1,x);
			printw("=-=");
		}
		void KeyboardHandler(int key) {
			switch(key) {
				case 'j': x--; break;
				case 'l': x++; break;
				case 'i': y--; break;
				case 'k': y++; break;
			}
		}
};

enum BOMB_STATE {BOMB_PHASE1, BOMB_PHASE2, BOMB_PHASE3, BOMB_PHASE4} ;
class Bomb : public GameObject {
	private:
		BOMB_STATE state;
		int stateStep = 0;
	public:

		virtual void Draw() {
			switch(state) {
				case BOMB_PHASE1:
					move(y,x);
					printw("o");
					stateStep++;
					if (stateStep == 3) {
						state = BOMB_PHASE2;
						stateStep = 0;
					}
					break;
				case BOMB_PHASE2:
					move(y,x-stateStep);
					printw("o");
					move(y,x+stateStep);
					printw("o");
					stateStep++;
					if (stateStep == 3) {
						state = BOMB_PHASE3;
						stateStep = 3;
					}
					break;

				case BOMB_PHASE3:
					move(y,x-stateStep);
					printw("o");
					move(y,x+stateStep);
					printw("o");
					stateStep--;
					if (stateStep == 0) {
						state = BOMB_PHASE4;
						stateStep = 0;
					}
					break;


				case BOMB_PHASE4:
					move(y,x);
					printw("o");
					break;
			}
		}
		virtual bool Update() {
			y = y-1;
			if (y < 0) {
				return false;
			}
			return true;
		}
		Bomb(Player *player) {
			state = BOMB_PHASE1;
			this->x = player->x;
			this->y = player->y;
		}
};


class Missle : public GameObject {
	public:
		virtual void Draw() {
			move(y,x);
			printw(" ^ ");
		}
		virtual bool Update() {
			y--;
			if (y < 0) {
				return false;
			}
			return true;
		}
		Missle(Player *player) {
			this->x = player->x;
			this->y = player->y;
		}
};

class GameEngine {
	private:
		bool isPlaying;
		Player *player;
		vector<GameObject*> gameObjVec;

		void fire(char type) {
			switch(type) {
				case 'f': gameObjVec.push_back(new Missle(player)); break;
				case 'b': gameObjVec.push_back(new Bomb(player)); break;
			}
		}

		void DrawGameObject() {
			for(int i = 0 ; i < gameObjVec.size() ; i++)
				gameObjVec[i]->Draw();
		}

		void EngineKeyboardHandler(int key) {
			if(key == 'q')
				isPlaying = false;
			else if(key == 'b' || key == 'f')
				fire(key);
		}

		void UpdateGameObject() {
			for(int i = 0 ; i < gameObjVec.size() ; i++){
				if(gameObjVec[i]->Update() == false) {
					// 여기서 i 번째 미사일을 지운다.
				}
			}
		}

		void HandleKeyboard() {
			int key = getch();
			EngineKeyboardHandler(key);
			player->KeyboardHandler(key);

		}

		void GenerateEnemy() {
			if (time % 3 == 0) {
				gameObjVec.push_back(new Enemy());
			}
		}

		int time ;
	public:
		GameEngine() {
			player = new Player();
			gameObjVec.push_back(player);
			isPlaying = true;
			time = 0;
		}
		~GameEngine() { delete player; }

		void Run() {
			while(isPlaying) {
				clear();
				GenerateEnemy();
				UpdateGameObject();
				DrawGameObject();
				HandleKeyboard();
				refresh();
				time++;
			}
		}
};

class Game {
	GameEngine *engine;
	public:
		Game() { engine = new GameEngine();		}
		~Game() { delete engine; }
		void Run() {
			engine->Run();
		}
};

void game() {
	Game *game = new Game();
	game->Run();
	delete game;
}


void initCurses() {
		initscr();
		curs_set(0);
}

void endCurses() {
		endwin();
}

int main() {
		initCurses();

		game();

		endCurses();
		return 0;
}

