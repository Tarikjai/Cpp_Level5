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


string ChoiceName(enGameChoice choice) {
	string choiceName[3] = { "Stone", "Paper", "Scissors" };
	return choiceName[choice - 1];
}

string WinnerName(enWinner Winner) {
	 
	string WinnerName[3] = { "Player win", "Computer win", "No Winner" };
	return WinnerName[Winner - 1];
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
	cout << Tab(2) << "               +++ G a m e    O v e r +++\n";
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

enWinner WhoWonTheRound(stRoundInfo RoundInfo) {
	if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
		return enWinner::Draw;
		
	switch(RoundInfo.Player1Choice) {

		case enGameChoice::Paper:
			if (RoundInfo.ComputerChoice == enGameChoice::Scissors) {
				return enWinner::ComputerWin;
			}
			break;
		case enGameChoice::Stone:
			if (RoundInfo.ComputerChoice == enGameChoice::Paper) {
				return enWinner::ComputerWin;
			}
			break;
		case enGameChoice::Scissors:
			if (RoundInfo.ComputerChoice == enGameChoice::Stone) {
				return enWinner::ComputerWin;
			}
			break;
	}
	return enWinner::PlayerWin;
}

void  SetWinnerScreenColor(enWinner Winner) {
	switch (Winner ) {
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

enWinner WhoWonTheGame(short PlayerWin, short ComputerWin) {
	if (PlayerWin > ComputerWin) {
		return enWinner::PlayerWin;
	}
	else if (ComputerWin > PlayerWin  ) {
		return enWinner::ComputerWin;
	}
	else {
		return enWinner::Draw;
	}
}

StGameResult  FillGameResults(short RoundNumber, short PlayerWin , short ComputerWin , short Draw) {
	StGameResult  GameResult;
	GameResult.Rounds = RoundNumber;
	GameResult.PlayerWin = PlayerWin;
	GameResult.ComputerWin = ComputerWin;
	GameResult.Draw = Draw;
	GameResult.GameWinner = WhoWonTheGame(PlayerWin, ComputerWin);
	GameResult.WinnerName = WinnerName(GameResult.GameWinner);

	return GameResult;
}

void PrintRoundResult(stRoundInfo RoundInfo) {
	cout << "__________________Round ["<< RoundInfo.Round <<"]_________________\n" ;
	cout << "Player1 Choice   : " << ChoiceName(RoundInfo.Player1Choice) << endl;
	cout << "Computer Choice  : " << ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Round Winner     : " << RoundInfo.NameWinner << endl;
	cout << "____________________________________________\n";
	
}

StGameResult playGame(short HowManyRound) {

	stRoundInfo RoundInfo;

	short PlayerWin = 0, ComputerWin = 0, Draw = 0;

		for (short GameRound = 1; GameRound <= HowManyRound;  GameRound++) {
			cout <<"\nRound [" << GameRound << "] begins:\n";
			RoundInfo.Round = GameRound;
			RoundInfo.Player1Choice = PlayerChoice();
			RoundInfo.ComputerChoice = ComputerChoice();
			RoundInfo.Winner = WhoWonTheRound(RoundInfo);
		 	RoundInfo.NameWinner = WinnerName(RoundInfo.Winner);

			if (RoundInfo.Winner == enWinner::PlayerWin)
				PlayerWin++;
			else if (RoundInfo.Winner == enWinner::ComputerWin)
				ComputerWin++;
			else
				Draw++;
			SetWinnerScreenColor(RoundInfo.Winner);
			PrintRoundResult(RoundInfo);
		}
		
		return   FillGameResults(HowManyRound, PlayerWin, ComputerWin, Draw);
}

void showFinalGameResult(StGameResult GameResult) {
	cout << Tab(2) << "Player 1 won times : " << GameResult.PlayerWin << "\n";
	cout << Tab(2) << "Computer won times : " << GameResult.ComputerWin << "\n";
	cout << Tab(2) << "Draw times         : " << GameResult.Draw << "\n";
	cout << Tab(2) << "Final Winer        : " << GameResult.WinnerName << "\n";
	cout << Tab(2) << "_________________________________________________________\n";
	cout << endl;

}

void StartGame() {
	string StartGame = "Y";
	do {
		ResetScreen();
		StGameResult GameResult = playGame(HowManyRound());
		ShowGameOverScreen();
		showFinalGameResult(GameResult);

		SetWinnerScreenColor(GameResult.GameWinner);
		 
		cout << Tab(2) << "Do you want to play again? Y/N?";
		cin >> StartGame;

	} while (StartGame == "Y" || StartGame == "y");

}


int main() {
	srand((unsigned)time(NULL));

	StartGame();
}