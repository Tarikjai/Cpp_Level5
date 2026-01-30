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

string Tabs(short Number) {
	string t = "\t";
	for (int i = 0; i <= Number; i++) {
		t = t + t;
	}
	return t;
}

short HowManyRound() {
	short RoundNumber = 0;
	do {
		cout << "How Many Rounds"
	} while (RoundNumber < 0 || RoundNumber> 10);

	return RoundNumber
}
stGameResult playgame(enGameChoice choice) {

	short PlayerWin = 0, ComputerWin = 0, Draw = 0;

	for (int round =0 ,  )

}





stGameResult StartGame() {
	string playGame = "Y";
	do {

		stGameResult gameResult = playgame();

		cout << "Do you want to play again? Y/N";
		cin >> playGame;
	} while (playGame == "Y" || playGame == "y");


}





int main() {
	srand((unsigned)time(NULL));
	StartGame();
}