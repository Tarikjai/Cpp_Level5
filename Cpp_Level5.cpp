#include <iostream>  
#include <conio.h>
#include <string>
using namespace std;

enum enQuestionLevel { Easy=1, Medium=2, Hard=3, MixLevel=4};
enum operationType { Add = 1, Sub = 2, Mul = 3, Div=4, MixOperation=5 };

struct stRoundInfo {
	short QuestionNumber = 0;
	short QuestionLevel = 0;
	short OperationType = 0;
	short Num1 = 0;
	short Num2 = 0;
};

struct stGameResult {
	short NumberOfQuestions = 0;
	short NbrCorrectAnswers = 0;
	short NbrWrongAnswers = 0;
	string LevelName = "";
	string OpName = "";
};

/*
RandomNumber(51, 100);
RandomNumber(21, 50);
RandomNumber(11, 20);
RandomNumber(1, 10);
*/

void PrintColor(short correctAnswer, short WorngAnswer) {
	if (correctAnswer > WorngAnswer) {
		system("color  2F");
	} 
	else if (correctAnswer <  WorngAnswer) {
		system("color  4F");
	}
	else {
		system("color  0F");
	}
}

string FinalResult(short correctAnswer, short WorngAnswer) {
	if (correctAnswer > WorngAnswer) {
		return "Pass :-)";
	}
	else if (correctAnswer < WorngAnswer) {
		return "Fail :-(";
	}
	else {
		return "No Winner";
	}
}

void clear() {
	system("cls");
	system("color  0F");
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

string LevelName(short LevelName) {
	string arr[4] = { "Easy", "Medium", "Hard", "Mix" };
	return  arr[LevelName - 1];
}

operationType ChooseOperation() {
	short Operation;
	do {
		cout << "Enter Operation Type [1] Add, [2] Dub, [3] Mul, [4] Div, [5] Mix  ? ";
		cin >> Operation;
	} while (Operation < 1 || Operation >5);
	return (operationType)Operation;
}

string OperationSign(short OperationSigne) {
	string arr[4] = { "+", "-", "*", "/"};
	return  arr[OperationSigne - 1];
}
 
string OperationSignName(short OperationSignName) {
	string arr[5] = { "+", "-", "*", "/", "Mix" };
	return  arr[OperationSignName - 1];
}

 

short  Operation(stRoundInfo RoundInfo) {
	switch (RoundInfo.OperationType) {
	case operationType::Add:
		return RoundInfo.Num1 + RoundInfo.Num2;
		break;
	case operationType::Sub:
		return RoundInfo.Num1 - RoundInfo.Num2;
		break;
	case operationType::Mul:
		return RoundInfo.Num1 * RoundInfo.Num2;
		break;
	case operationType::Div:
		return RoundInfo.Num1 / RoundInfo.Num2;
		break;
	
	
}
}



char Operator() {
	char add = +;
}


stGameResult fillFinalResult(short NbrCorrectAnswers, short NbrWrongAnswers, short HowManyQuestion, stRoundInfo RoundInfo) {
	stGameResult GameResult;
	GameResult.NumberOfQuestions = HowManyQuestion;
	GameResult.NbrCorrectAnswers = NbrCorrectAnswers;
	GameResult.NbrWrongAnswers = NbrWrongAnswers;
	GameResult.LevelName = LevelName(RoundInfo.QuestionLevel);
	GameResult.OpName = OperationSignName(RoundInfo.OperationType);
	return GameResult;
}

void PrintFinalResult(stGameResult GameResult) {

	PrintColor(GameResult.NbrCorrectAnswers, GameResult.NbrWrongAnswers);

	cout << "\n\n----------------------------------------------------------\n\n";
	cout << "Final Result is " << FinalResult(GameResult.NbrCorrectAnswers, GameResult.NbrWrongAnswers);
	cout << "\n\n----------------------------------------------------------\n";
	cout << "\nNumber Of Question:" << GameResult.NumberOfQuestions  << "\n";
	cout << "Questions Level: " << GameResult.LevelName << "\n";
	cout << "Op Type :" << GameResult.OpName << "\n";
	cout << "Number of Right Answers :" << GameResult.NbrCorrectAnswers << "\n";
	cout << "Number of Wrong Answers :" << GameResult.NbrWrongAnswers << "\n";
	cout << "\n----------------------------------------------------------\n";
}

stGameResult PlayGame(short HowManyQuestion) {
	stRoundInfo RoundInfo;

	RoundInfo.QuestionLevel = level();
	RoundInfo.OperationType = ChooseOperation();

	short NbrCorrectAnswers = 0, NbrWrongAnswers = 0, answer=0, result=0;


	for (int Question = 1; Question <= HowManyQuestion; Question++) {
		cout << "\n\nQuestion [" << Question << "/" << HowManyQuestion << "]\n\n";

		RoundInfo.Num1 = RandomNumber(1, 100);
		RoundInfo.Num2 = RandomNumber(1, 100);
		result = Operation(RoundInfo);

		cout << RoundInfo.Num1 << "\n";
		cout << RoundInfo.Num2 << " " << OperationSign(RoundInfo.OperationType) << "\n";
				cout << "------------\n";
		cout << result << "\n";
		cout << "------------\n";
		cin >> answer;

		if (answer == result) {
			NbrCorrectAnswers++;
			system("color  2F");
			cout << "Right Answer :-)\n";
		}
		else {
			NbrWrongAnswers++;
			system("color  4F");
			cout << "Wrong Answer :-(\n";
			cout << "The right Answer is : " << result << "\n";
		}
	}
	return fillFinalResult(NbrCorrectAnswers, NbrWrongAnswers, HowManyQuestion, RoundInfo);
}

void StartGame() {
	string playGame = "Y";
	do {
		clear();
		stGameResult  GameResult = PlayGame(HowManyQuestion());
		PrintFinalResult(GameResult);

		cout << "\nDo you want to play again? Y/N: ";
		cin >> playGame;
	} while (playGame == "Y" || playGame == "y");
}

int main() {
	srand((unsigned)time(NULL));
	StartGame();
}