  #include <iostream>  
#include <conio.h>
#include <string>
using namespace std;



int RandomNumber(int From, int To) {
	int RandomNumber = rand() % (To - From + 1) + From;                // génère un entier pseudo-aléatoire
	return RandomNumber;
}


short HowManyRound(short QuestionNumber) {
	
	do {
		cout << "How Many QSu\n";
	} while (RoundNumber < 1 || RoundNumber >9);
	return RoundNumber;
}


void PrintFinalResultScreen() {
	cout << Tabs(2) << "_______________________________________________________\n";
	cout << Tabs(2) << "               +++ G A M E     O V E R++++\n";
	cout << Tabs(2) << "_______________________________________________________\n";
}





void StartGame() {
	string playGame = "Y";
	do {
		clear();
		
	
		cout  << "Do you want to play again? Y/N";
		cin >> playGame;
	} while (playGame == "Y" || playGame == "y");
}





int main() {
	srand((unsigned)time(NULL));
	StartGame();
}