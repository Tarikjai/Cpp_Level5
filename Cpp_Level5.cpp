#include <iostream>  
#include <conio.h>
#include <string>
using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissor = 3 };
enum enWinner {PlayerWin=1, ComputerWin=2, Draw=3};

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

short HowManyRound() {
	short RoundNumber = 0;
	do {
		cout << "How Many Rounds 1 to 10 ? \n";
		cin >> RoundNumber;
	} while (RoundNumber < 0 || RoundNumber> 10);

	return RoundNumber;
}

int RandomNumber(int From, int To) {
	int RandomNumber = rand() % (To - From + 1) + From;                // génère un entier pseudo-aléatoire
	return RandomNumber;
}

string Tabs(short Number) {
	string t = "\t";
	for (int i = 0; i <= Number; i++) {
		t = t + "\t";
	}
	return t;
}

enGameChoice PlayerChoice() {
	short playerChoice = 0;
	do {
		cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
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

enWinner WhoWonTheRound(stRoundinfo RoundInfo) {
	if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice) {
		return enWinner::Draw;
	}

	switch (RoundInfo.PlayerChoice) {
		case (enGameChoice::Paper):
			if (RoundInfo.ComputerChoice == enGameChoice::Scissor) {
				return enWinner::ComputerWin;
			}
			break;
		case (enGameChoice::Scissor):
			if (RoundInfo.ComputerChoice == enGameChoice::Stone) {
				return enWinner::ComputerWin;
			}
			break;
		case (enGameChoice::Stone):
			if (RoundInfo.ComputerChoice == enGameChoice::Paper) {
				return enWinner::ComputerWin;
			}
			break;
	}

	return enWinner::PlayerWin;
}

string WinnerName(enWinner Winner) {
	string arr[3] = { "[Player]", "[Computer]", "[No Winner]" };

	return arr[Winner - 1];
}

void printRoundResult(stRoundinfo  RoundInfo) {
	cout << "____________Round [" << RoundInfo.Round << "]____________\n";
	cout << "Player1 choice: " << ChoiceName(RoundInfo.PlayerChoice) << "\n";
	cout << "Computer choice: " << ChoiceName(RoundInfo.ComputerChoice) << "\n";
	cout << "Round Winner choice: " << RoundInfo.WinnerName << "\n";
	cout << "________________________________\n";
}

string HoWonTheGame(short PlayerWin, short ComputerWin, short Draw) {
	if (PlayerWin == ComputerWin) {
		return "[No Winner]";
	}
	else if (PlayerWin  > ComputerWin) {
		return "[Player]";
	}
	else {
		return "[Computer]";
	}
	
}

void PrintGameOverScreen() {
	cout << Tabs(2) << "_______________________________________________________\n";
	cout << Tabs(2) << "               +++ G A M E     O V E R++++\n";
	cout << Tabs(2) << "_______________________________________________________\n";
}

void printGameResult(stGameResult GameResult) {
	cout << Tabs(2) << "_____________________[Game Result]_____________________\n";
	cout << Tabs(2) << "Game Rounds        :" << GameResult.RoundNumber <<  "\n";
	cout << Tabs(2) << "Players1 won times :" << GameResult.PlayerWin << "\n";
	cout << Tabs(2) << "Computer won times :" << GameResult.ComputerWin << "\n";
	cout << Tabs(2) << "Draw times         :" << GameResult.Draw << "\n";
	cout << Tabs(2) << "Final Winner       :" << HoWonTheGame(GameResult.PlayerWin, GameResult.ComputerWin, GameResult.Draw) << "\n";

}


stGameResult inputGameResult(short RoundNUmber, short PlayerWin, short ComputerWin, short Draw) {
	stGameResult GameResult;
	GameResult.RoundNumber = RoundNUmber;
	GameResult.PlayerWin = PlayerWin;
	GameResult.ComputerWin = ComputerWin;
	GameResult.Draw = Draw;
	return GameResult;
}


stGameResult playgame(short RoundNUmber) {
	stRoundinfo  RoundInfo;

	short PlayerWin = 0, ComputerWin = 0, Draw = 0;

	for (int round = 1; round <= RoundNUmber; round++) {
		RoundInfo.Round = round;
		cout << "\n\nRound [" << RoundInfo.Round << "] begins :\n";
		RoundInfo.PlayerChoice = PlayerChoice();
		RoundInfo.ComputerChoice = ComputerChoice();
		RoundInfo.Winner = WhoWonTheRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

		printRoundResult(RoundInfo);

		if (RoundInfo.Winner == enWinner::PlayerWin) {
			PlayerWin++;
		}
		else if (RoundInfo.Winner == enWinner::ComputerWin) {
			ComputerWin++;
		} 
		else {
			Draw++;
		}


	}
	 
	return inputGameResult(RoundNUmber, PlayerWin, ComputerWin, Draw);


}



void StartGame() {
	string playGame = "Y";
	do {
		clear();
		stGameResult gameResult = playgame(HowManyRound());
		PrintGameOverScreen();
		printGameResult(gameResult);
		cout << Tabs(2) << "Do you want to play again? Y/N";
		cin >> playGame;
	} while (playGame == "Y" || playGame == "y");
}





int main() {
	srand((unsigned)time(NULL));
	StartGame();
}