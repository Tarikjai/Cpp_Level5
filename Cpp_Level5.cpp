#include <iostream>  
#include <conio.h>
#include <string>
using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissor = 3 };
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

enGameChoice PlayerChoice() {
	short playerChoice = 0;
	do {
		cout << "Your Choice: [1]:Stone, [2]:¨Paper, [3]:Scissors ? ";
		cin >> playerChoice;
	} while (playerChoice < 1 || playerChoice>3);
	return (enGameChoice)playerChoice;
}

enGameChoice ComputerChoice() {
	return enGameChoice(RandomNumber(1, 3));
}

string ChoiceName(enGameChoice choice) {
	string arr[3] = {"Stone", "Paper", "Scissor"};
	return arr[choice-1];
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
	stRoundinfo  RoundInfo;
	short PlayerWin = 0, ComputerWin = 0, Draw = 0;

	for (int round = 1; round <= RoundNUmber; round++) {
		RoundInfo.Round = round;
		RoundInfo.PlayerChoice =
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

	return ;
}





int main() {
	srand((unsigned)time(NULL));
	StartGame();
}