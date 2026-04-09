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
enOperationType GetOperationType() {
	int opType= InputLib::RandomNumber(1, 4);
	return (enOperationType)opType;
}

int simpleCalculator(int Num1, int Num2, enOperationType OpType) {
	if (OpType == enOperationType::Add) {
		return Num1 + Num2;
	}
    if (OpType == enOperationType::Sub) {
		return Num1 - Num2;
	}
	if (OpType == enOperationType::Multi) {
		return Num1 * Num2;
	}
	if (OpType == enOperationType::Divid) {
		return Num1 / Num2;
	}
}

stQuestion GenerateQuizQuestion(enOperationType OpType, enLevelType LevelType) {
	stQuestion Question;

	if (LevelType == enLevelType::MixLevel) {
		LevelType = (enLevelType)InputLib::RandomNumber(1, 3);
	}
	if (OpType == enOperationType::MixOp) {
		OpType = GetOperationType();
	}
	Question.OperationType = OpType;

	switch (LevelType) {
	case enLevelType::Easy:
		Question.Num1 = InputLib::RandomNumber(1, 10);
		Question.Num2 = InputLib::RandomNumber(1, 10);
		Question.CorrectAnswer = simpleCalculator(Question.Num1, Question.Num2, OpType);
		Question.LevelType = LevelType;
		return Question;
	case enLevelType::Medium:
		Question.Num1 = InputLib::RandomNumber(11, 50);
		Question.Num2 = InputLib::RandomNumber(11, 50);
		Question.CorrectAnswer = simpleCalculator(Question.Num1, Question.Num2, OpType);
		Question.LevelType = LevelType;
		return Question;
	case enLevelType::Hard:
		Question.Num1 = InputLib::RandomNumber(51, 100);
		Question.Num2 = InputLib::RandomNumber(51, 100);
		Question.CorrectAnswer = simpleCalculator(Question.Num1, Question.Num2, OpType);
		Question.LevelType = LevelType;
		return Question;
	}
	return Question;
}

void GenerateQuizQuestion(stQuiz& Quiz) {
	for (int QuestionNumber = 0; QuestionNumber < Quiz.NumberOfQuestions; QuestionNumber++) {
		Quiz.QuestionList[QuestionNumber] = GenerateQuizQuestion(Quiz.OperationsType, Quiz.LevelsType);
	}
}

void PrintQuestion(stQuiz Quiz, int QuestionNumber) {
	cout << "\nQuestion [" << QuestionNumber + 1 << "/" << Quiz.NumberOfQuestions << "]" << endl;
	cout << "\n";
	cout << Quiz.QuestionList[QuestionNumber].Num1 << "\n";
	cout << Quiz.QuestionList[QuestionNumber].Num2 << " " << InputLib::GetOperationName(Quiz.QuestionList[QuestionNumber].OperationType) << "\n";
	cout << "______________\n";
}

void Checkanswer(stQuiz& Quiz, int QuestionNumber) {
	if (Quiz.QuestionList[QuestionNumber].PlayerAnswer != Quiz.QuestionList[QuestionNumber].CorrectAnswer) {
		cout << "Wrong Answer :-(\n";
		cout << "The right Answer is : " << Quiz.QuestionList[QuestionNumber].CorrectAnswer << endl;
		Quiz.QuestionList[QuestionNumber].AnswerResult = false;
		Quiz.NumberOfWrongAnswer++;

	}
	else {
		cout << "Right Answer :)\n";
		Quiz.QuestionList[QuestionNumber].AnswerResult = true;
		Quiz.NumberOfCorrectAnswer++;
	}
	ColorLib::DisplayColor(Quiz.QuestionList[QuestionNumber].AnswerResult);
}

void AskAndCorrectAnswer(stQuiz& Quiz) {
	for (int QuestionNumber = 0; QuestionNumber < Quiz.NumberOfQuestions; QuestionNumber++) {

		PrintQuestion(Quiz, QuestionNumber);
		Quiz.QuestionList[QuestionNumber].PlayerAnswer = InputLib::PAnswer();
		Checkanswer(Quiz, QuestionNumber);
	}
	Quiz.isPass = (Quiz.NumberOfCorrectAnswer > Quiz.NumberOfWrongAnswer);
}
void PrintFinalResult(stQuiz Quiz) {
	ColorLib::DisplayColor(Quiz.isPass);
	cout << "\n\n----------------------\n";
	cout << "Final Results is "	<< InputLib::FinalResult(Quiz.isPass)  << endl;
	cout << "Number of Questions    : " << Quiz.NumberOfQuestions << endl;
	cout << "Question Level         : " << InputLib::GetLevelName(Quiz.LevelsType) << endl;
	cout << "OpType                 : " << InputLib::GetOperationName(Quiz.OperationsType) << endl;
	cout << "Number of Right Answers: " << Quiz.NumberOfCorrectAnswer << endl;
	cout << "Number of Wrong Answers: " << Quiz.NumberOfWrongAnswer << endl;
	cout << "_____________________________________________\n";
}

void PlayGame() {
	stQuiz Quiz;
	
	Quiz.NumberOfQuestions = InputLib::QuestionNumber();
	Quiz.OperationsType =  OperationsType();
	Quiz.LevelsType = QuestionsLevel();

	GenerateQuizQuestion(Quiz);
	AskAndCorrectAnswer(Quiz);
	PrintFinalResult(Quiz);
}

void StartGame() {

	string Play= "Y";
	do {
		ColorLib::clear();
		PlayGame();
		cout << "\nDo you want to play again? ";
		cin >> Play;
		cout << "\n";
	} while (Play == "Y" || Play == "y");


}

int main() {

	srand((unsigned)time(NULL));
	StartGame();

}