  #include <iostream>  
#include <conio.h>
#include <string>
using namespace std;


enum enQuestionLevel { Easy=1, Medium=2, Hard=3, MixLevel=4};
enum operationType { Add = 1, Sub = 2, Mul = 3, Div=4, MixOperation=5 };


struct stRoundInfo {
	short QuestionNumber = 0;
	string QuestionLevel = "";
	string OperationType = "";
};

struct stGameResult {
	short NumberOfQuestions = 0;
	short NbrCorrectAnswers = 0;
	short NbrWrongAnswers = 0;
};

void clear() {
	system("cls");
	system("System 0F");
}

int RandomNumber(int From, int To) {
	int RandomNumber = rand() % (To - From + 1) + From;                // génère un entier pseudo-aléatoire
	return RandomNumber;
}



short HowManyQuestion() {
	short QuestionNumber = 0;
	do {
		cout << "How Many questions do you want to answer ? \n";
		cin >> QuestionNumber;
	} while (QuestionNumber < 1 || QuestionNumber >9);
	return QuestionNumber;
}

enQuestionLevel level() {
	do {

	} 
}

/*
operationType Operation() {
	int Result = 0;
	switch (c)
	RandomNumber(1, 100) ; 
}*/

stGameResult PlayGame(short HowManyQuestion) {
	stRoundInfo RoundInfo;


	short NbrCorrectAnswers = 0, NbrWrongAnswers = 0;


	for (int Question = 1; Question <= HowManyQuestion; Question++) {
		cout << "Question [" << Question << "/" << HowManyQuestion << "]\n";

		cout << "_________\n";
	}

}


stGameResult StartGame() {
	string playGame = "Y";
	do {
		clear();
		stGameResult  GameResult = PlayGame(HowManyQuestion());
	
		cout  << "Do you want to play again? Y/N";
		cin >> playGame;
	} while (playGame == "Y" || playGame == "y");
}


void PrintFinalResultScreen() {
	cout << "_______________________________________________________\n";
	cout << "               Final Result is \n";
	cout << "_______________________________________________________\n";
}




int main() {
	srand((unsigned)time(NULL));
	StartGame();
}