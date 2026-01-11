#include <iostream>  
#include <conio.h>
using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };
enum enWinner { PlayerWin = 1, ComputerWin = 2, Draw = 3 };

struct stRoundInfo {
	short Round = 0;
	enGameChoice Player1Choice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string NameWinner = "";
};

struct StGameResult {
	short PlayerWin = 0;
	short ComputerWin = 0;
	short Draw = 0;
	enWinner Winner;
	string GameWinner = "";
};

int RandomNumber(int From, int To) {
	int RandomNumber = rand() % (To - From + 1) + From;
	return RandomNumber;
}

enGameChoice PlayerChoice() {
	int choice  = 1;
	do {
		 cout << "\nYour Choice: [1]: Stone, [2]: Papper, [3]: Sissors ? \n";
		 cin >> choice;
	} while (choice < 1 || choice >3);
	return (enGameChoice)choice;
}
enGameChoice ComputerChoice() {
	return (enGameChoice)RandomNumber(1, 3);
}


void ResetScreen() {
	system("cls");
	system("color 07");
}

string Tab(short Number) {
	string t = "\t";
	for (int i = 0; i <= Number; i++) {
		t = t + "\t";
	}
	return t;
}
void ShowGameOverScreen() {
	cout << Tab(2) << "---------------------------------------------------------\n";
	cout << Tab(2) << "             +++ G a m e    O v e r +++\n";
	cout << Tab(2) << "_________________________________________________________\n";
}
short HowManyRound() {
	short RoundNumber;
	do {
		cout << "How many Rounds 1 to 10 ?\n";
		cin >> RoundNumber;
	} while (RoundNumber < 1 || RoundNumber >10);
	return RoundNumber;
}



stRoundInfo playRound(short RoundNumber) {
	stRoundInfo RoundInfo;

	short PlayerWin = 0, ComputerWin = 0, Draw = 0;

		for (short Round = 0; Round < RoundNumber;  Round++) {
			RoundInfo.Round = RoundNumber;
			RoundInfo.Player1Choice = PlayerChoice();
			RoundInfo.ComputerChoice = ComputerChoice();
			RoundInfo.Winner = ;
		}




	return RoundInfo;
}

void StartGame() {
	string StartGame = "Y";
	
	do {
		ResetScreen();
		stRoundInfo RoundInfo = playRound(HowManyRound());
		ShowGameOverScreen();

		cout << Tab(2) << "Do you want to play again? Y/N?";
		cin >> StartGame;

	} while (StartGame == "Y" || StartGame == "y");

}


int main() {
	srand((unsigned)time(NULL));

	StartGame();
}