#include <iostream>  
#include <conio.h>
#include <string>
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
	short Rounds = 0;
	short PlayerWin = 0;
	short ComputerWin = 0;
	short Draw = 0;
	enWinner GameWinner;
	string WinnerName = "";
};

int RandomNumber(int From, int To) {
	int RandomNumber = rand() % (To - From + 1) + From;
	return RandomNumber;
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo) {
	;

	if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice) {
		return enWinner::Draw;
	}
	 
	switch (RoundInfo.Player1Choice) {
	case enGameChoice::Paper:
		if (RoundInfo.ComputerChoice == enGameChoice::Scissors) {
			return  enWinner::ComputerWin;
		}
		break;
	case enGameChoice::Scissors:
		if (RoundInfo.ComputerChoice == enGameChoice::Stone) {
			return  enWinner::ComputerWin;
		}
		break;
	case enGameChoice::Stone:
		if (RoundInfo.ComputerChoice == enGameChoice::Paper) {
			return  enWinner::ComputerWin;
		}
		break;
	}
	return  enWinner::PlayerWin;
}

enGameChoice PlayerChoice() {
	short choice;
	do {
		cout << "Pleace make a choice : Stone = 1, Paper = 2, Scissors = 3 ";
		cin >> choice;
	} while (choice < 1 || choice > 3);
	return (enGameChoice)choice;
}
enGameChoice ComputerChoice() {
	return (enGameChoice)RandomNumber(1, 3);
}

string WinnerName(short WinnerName) {
	string arr[3] = { "Player", "Computer", "Draw" };
	return  arr[WinnerName - 1];
}

short HowManyRound() {
	short RoundNumber;
	do {
		cout << "Hom much roundto play? ";
		cin >> RoundNumber;
	} while (RoundNumber < 1 || RoundNumber > 10);

	return RoundNumber;
}

StGameResult FillInfo(short HowManyRound, short PlayerWin, short ComputerWin, short Draw) {

}

StGameResult PlayGame(short HowManyRound) {
	stRoundInfo RoundInfo;
	short PlayerWin = 0, ComputerWin = 0, Draw = 0;

	for (short Roundnumber = 1; Roundnumber < HowManyRound; Roundnumber++) {
		RoundInfo.Round = Roundnumber;
		RoundInfo.Player1Choice = PlayerChoice();
		RoundInfo.ComputerChoice = ComputerChoice();
		RoundInfo.Winner = WhoWonTheRound(RoundInfo);
		RoundInfo.NameWinner = WinnerName(RoundInfo.Winner);

	}
	return FillInfo(HowManyRound, PlayerWin, ComputerWin,  Draw);
}



void StartGame() {

	string Play = "Y";

	do {
		StGameResult GameResult = PlayGame(HowManyRound());

	} while(Play == "Y" || Play == "y");


}


int main() {
	srand((unsigned)time(NULL));

	StartGame();
}