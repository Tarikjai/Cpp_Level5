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
	short Num1 = 0;
	short Num2 = 0;
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
	short level;
	do {
		cout << "Enter Questions Level [1] Easy, [2] Medium, [3] Hard, [4] Mix ? ";
		cin >> level;
	} while (level < 1 || level >4);
	return (enQuestionLevel)level;
}

operationType Operation() {
	short Operation;
	do {
		cout << "Enter Operation Type [1] Add, [2] Dub, [3] Mul, [4] Div, [5] Mix  ? ";
		cin >> Operation;
	} while (Operation < 1 || Operation >4);
	return (operationType)Operation;
}

 
short Operation(short Num1, short Num2) {
	return Num1 + Num2;

}

stGameResult PlayGame(short HowManyQuestion) {
	stRoundInfo RoundInfo;

	RoundInfo.QuestionLevel = level();
	RoundInfo.OperationType = Operation();

	short NbrCorrectAnswers = 0, NbrWrongAnswers = 0;


	for (int Question = 1; Question <= HowManyQuestion; Question++) {
		cout << "Question [" << Question << "/" << HowManyQuestion << "]\n";


		RoundInfo.Num1 = RandomNumber( 1,100);
		RoundInfo.Num2 = RandomNumber(1, 100);
		cout << Operation(RoundInfo.Num1, RoundInfo.Num2);
		cout << "_________\n";
	}

}

stGameResult FillResult() {

}

stGameResult StartGame() {
	string playGame = "Y";
	do {
		clear();
		stGameResult  GameResult = PlayGame(HowManyQuestion());

		cout << "Do you want to play again? Y/N";
		cin >> playGame;
	} while (playGame == "Y" || playGame == "y");

	return FillResult();

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