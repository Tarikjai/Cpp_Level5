#include <iostream>
#include "ColorLib.h";
#include "InputLib.h";

using namespace std;

enum enOperationType { Add = 1, Sub = 2, Multi = 3, Divid = 4, MixOp = 5 };
enum enLevelType { Easy = 1, Medium = 2, Hard = 3, MixLevel = 4 };


struct stQuestion {
	int Num1 = 0;
	int Num2 = 0;
	enOperationType  OperationType;
	enLevelType LevelType;
	int CorrectAnswer = 0;
	int PlayerAnswer = 0;
	bool AnswerResult = false;
};
struct stQuiz {
	stQuestion QuestionList[10];
	enOperationType  OperationsType;
	enLevelType LevelsType;
	int NumberOfQuestions;
	int NumberOfCorrectAnswer = 0;
	int NumberOfWrongAnswer = 0;
	bool isPass = false;
};

enLevelType QuestionsLevel() {
	int QuestionsLevel;
	do {
		cout << "Enter Questions Level [1] Easy, [2] Medium, [3] Hard, [4] Mix ? ";
		cin >> QuestionsLevel;
	} while (QuestionsLevel < 1 || QuestionsLevel >4);
	return (enLevelType)QuestionsLevel;
}
enOperationType OperationsType() {
	int OperationsType;
	do {
		cout << "Enter Operations Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
		cin >> OperationsType;
	} while (OperationsType < 1 || OperationsType >5);
	return (enOperationType)OperationsType;
}

stQuestion GenerateQuizQuestion(enOperationType OpType, enLevelType LevelType) {

}



void GenerateQuizQuestion(stQuiz& Quiz) {
	for (int QuestionNumber = 0; QuestionNumber <= Quiz.NumberOfQuestions; QuestionNumber++) {
		Quiz.QuestionList[QuestionNumber] = GenerateQuizQuestion(Quiz.OperationsType, Quiz.LevelsType);
	}
}

void PlayGame() {
	stQuiz Quiz;
	
	Quiz.NumberOfQuestions = InputLib::QuestionNumber();
	Quiz.OperationsType =  OperationsType();
	Quiz.LevelsType = QuestionsLevel();

	GenerateQuizQuestion(Quiz)

}

void StartGame() {

	string Play= "Y";
	do {
		ColorLib::clear();
		PlayGame();
		cout << "\nDo you want to play again? ";
		cin >> Play;
	} while (Play == "Y" || Play == "y");


}

int main() {

	srand((unsigned)time(NULL));
	StartGame();

}