#include <iostream>  
#include <conio.h>
#include <string>
using namespace std;

enum enGameChoice { Stone = 1, Papper = 2, Sicssors = 3 };
enum enWinner {Player=1, Computer=2, Draw=3};

struct stRoundinfo {
	short Round=0;
	enGameChoice PlayerChoice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string WinnerName = ""; 

};

struct stGameResult {
	short RoundNumber = 0;
	short PlayerWin = 0;
	short ComputerWin = 0;
	short Draw = 0;
	enWinner Winner;
	string WinnerName = "";
};


stGameResult StartGame() {

}





int main() {
	srand((unsigned)time(NULL));
	StartGame();
}