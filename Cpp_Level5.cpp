#include <iostream>  
#include <conio.h>
#include <string>
using namespace std;

enum enQuestionsLevel { Easy=1, Medium=2, Hard=3, MixLevel=4};
enum enOperationsType { Add = 1, Sub = 2, Mul = 3, Div=4, MixOperation=5 };

struct StQuestion {
	int Num1 = 0;
	int Num2 = 0;
	int QuestionNumber=0 ;
	enum enQuestionsLevel  QuestionLevel;
	enum enOperationsType OperationType;
	int CorrectAnswer = 0;
	int WrongAnswer = 0;
	bool Answer;
};

struct stQuiz {
	StQuestion Question;
	short NumberOfQuestions = 0;
	enum enQuestionsLevel  QuestionsLevel;
	enum enOperationsType OperationsType;
	short NbrCorrectAnswers = 0;
	short NbrWrongAnswers = 0;
	bool FinalResult;
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

void clearScreen() {
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

enQuestionsLevel QuestionsLevel() {
	short Operationlevel;
	do {
		cout << "Enter Questions Level [1] Easy, [2] Medium, [3] Hard, [4] Mix ? ";
		cin >> Operationlevel;
	} while (Operationlevel < 1 || Operationlevel >4);
	return (enQuestionsLevel)Operationlevel;
}

string LevelName(short LevelName) {
	string arr[4] = { "Easy", "Medium", "Hard", "Mix" };
	return  arr[LevelName - 1];
}

enOperationsType OperationType() {
	short OperationType;
	do {
		cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix  ? ";
		cin >> OperationType;
	} while (OperationType < 1 || OperationType >5);
	return (enOperationsType)OperationType;
}

string OperationSign(short OperationSigne) {
	string arr[5] = { "+", "-", "*", "/"," MIX "};
	return  arr[OperationSigne - 1];
}
 
string OperationSignName(short OperationSignName) {
	string arr[5] = { "+", "-", "*", "/", "Mix" };
	return  arr[OperationSignName - 1];
}



void PLayMathGame() {
	stQuiz Quiz;

	Quiz.NumberOfQuestions = HowManyQuestion();
	Quiz.QuestionsLevel = QuestionsLevel();
	Quiz.OperationsType = OperationType();



}

/*
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
*/

void StartGame() {
	string playGame = "Y";
	do {
		clearScreen();
		PLayMathGame();

		cout << "\nDo you want to play again? Y/N: ";
		cin >> playGame;
	} while (playGame == "Y" || playGame == "y");
}

int main() {
	srand((unsigned)time(NULL));
	StartGame();
}