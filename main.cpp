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
string WhoWonTheGame(short PlayerWin, short ComputerWin) {
	if (PlayerWin > ComputerWin)
		return "Player";
	else if (PlayerWin < ComputerWin)
		return "Computer";
	else {
		return "Draw";
	}
}


enGameChoice PlayerChoice() {
	short choice;
	do {
		cout << "\nYour choice : [1]: Stone , [2]: Paper, [3]: Scissors ? ";
		cin >> choice;
	} while (choice < 1 || choice > 3);
	return (enGameChoice)choice;
}
enGameChoice ComputerChoice() {
	return (enGameChoice)RandomNumber(1, 3);
}

string Tabs(short tabs) {
	string t = "";
	for (int i=0; i < tabs; i++) {
		t = t + "\t";
	}
	return t; 
}

string WinnerName(short WinnerName) {
	string arr[3] = { "Player", "Computer", "Draw" };
	return  arr[WinnerName - 1];
}
string ChoiceName(short choice) {
	string arr[3] = { "Stone", "Paper", "Scissors" };
	return  arr[choice - 1];
}

void  SetWinnerScreenColor(enWinner Winner) {
	switch (Winner) {
	case  enWinner::PlayerWin:
		system("color 2F");
		break;
	case enWinner::ComputerWin:
		system("color 4F");
		break;
	case enWinner::Draw:
		system("color 6F");
		break;
	}
};

void resetScreen() {
	system("cls");
	system("color 07");
};

short HowManyRound() {
	short HowManyRound;
	do {
		cout << "How many Rounds 1 to 10 ? ";
		cin >> HowManyRound;
	} while (HowManyRound < 1 || HowManyRound > 10);

	return HowManyRound;
}

void printRoundResult(stRoundInfo RoundInfo) {

	cout << "\n______________Round [" << RoundInfo.Round << "]______________\n" << endl;;
	cout << "Player1 Choice: " << ChoiceName(RoundInfo.Player1Choice) << endl;
	cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Round Winner : " << WinnerName(RoundInfo.Winner) << endl;
	cout << "_____________________________________\n" << endl;

	
}


StGameResult FillInfo(short HowManyRound, short PlayerWin, short ComputerWin, short Draw) {
	
	StGameResult GameResult;
	GameResult.Rounds = HowManyRound;
	GameResult.PlayerWin = PlayerWin;
	GameResult.ComputerWin = ComputerWin;
	GameResult.Draw = Draw;
	GameResult.WinnerName = WhoWonTheGame(PlayerWin, ComputerWin);

	return GameResult;
}




StGameResult PlayGame(short HowManyRound) {

	stRoundInfo RoundInfo;
	short PlayerWin = 0, ComputerWin = 0, Draw = 0;

	for (short Round= 1; Round <= HowManyRound; Round++) {

		cout << "\nRound [" << Round << "] begins:\n";
		RoundInfo.Round = Round;
		RoundInfo.Player1Choice = PlayerChoice();
		RoundInfo.ComputerChoice = ComputerChoice();
		RoundInfo.Winner = WhoWonTheRound(RoundInfo);
		RoundInfo.NameWinner = WinnerName(RoundInfo.Winner);

		if (RoundInfo.Winner == enWinner::PlayerWin) {
			PlayerWin++;
		}
		else if (RoundInfo.Winner == enWinner::ComputerWin) {
			ComputerWin++;
		}
		else  {
			Draw++;
		}

		SetWinnerScreenColor(RoundInfo.Winner);
		printRoundResult(RoundInfo);
	}

	return  FillInfo(HowManyRound, PlayerWin, ComputerWin,  Draw);
}

void GameoverScreen() {
	cout << Tabs(2) << "____________________________________________________" << endl;
	cout << Tabs(2) << "             +++ G a m e  O v e r +++" << endl;
	cout << Tabs(2) << "____________________________________________________" << endl;
}

void PrintGameResult(StGameResult GameResult) {
	cout << Tabs(2) << "______________[Game Results]______________\n" << endl;;
	cout << Tabs(2) << "Game Rounds         :" << GameResult.Rounds << endl;
	cout << Tabs(2) << "Player1 won times   :" << GameResult.PlayerWin << endl;
	cout << Tabs(2) << "Computer won times  :" << GameResult.ComputerWin << endl;
	cout << Tabs(2) << "Draw times          :" << GameResult.Draw << endl;
	cout << Tabs(2) << "Final Winner        :" << GameResult.WinnerName << endl;
	cout << Tabs(2) << "_____________________________________\n" << endl;

	
}

void StartGame() {

	string Play = "Y";

	do {
		resetScreen();
		StGameResult GameResult = PlayGame(HowManyRound());
		GameoverScreen();
		PrintGameResult(GameResult),

			SetWinnerScreenColor(GameResult.GameWinner);
		cout << Tabs(2) << "Do you want to play again? Y/N? ";
			cin >> Play;
	} while(Play == "Y" || Play == "y");

	

}


int main() {
	srand((unsigned)time(NULL));

	StartGame();
}