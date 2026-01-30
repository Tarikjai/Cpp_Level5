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

void clear() {
	system("cls");
	system("color 0F");
}

int RandomNumber(int From, int To) {
	int RandomNumber = rand() % (To - From + 1) + From;                // génère un entier pseudo-aléatoire
	return RandomNumber;
}

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
		cout << "How Many Rounds 1 to 10 ? \n";
		cin >> RoundNumber;
	} while (RoundNumber < 0 || RoundNumber> 10);

	return RoundNumber;
}


stGameResult playgame(short RoundNUmber) {
	stGameResult  GameResult;

	short PlayerWin = 0, ComputerWin = 0, Draw = 0;

	for (int round = 0; round <= RoundNUmber; round++) {

	}

	return GameResult;

}





stGameResult StartGame() {
	string playGame = "Y";
	do {
		clear();
		stGameResult gameResult = playgame(HowManyRound());

		cout << "Do you want to play again? Y/N";
		cin >> playGame;
	} while (playGame == "Y" || playGame == "y");

	return gameResult;
}





int main() {
	srand((unsigned)time(NULL));
	StartGame();
}