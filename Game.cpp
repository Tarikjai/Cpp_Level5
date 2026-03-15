#include <iostream>  
#include <conio.h>
#include <string>
using namespace std;

enum enQuestionsLevel { Easy = 1, Medium = 2, Hard = 3, MixLevel = 4 };
enum enOperationsType { Add = 1, Sub = 2, Mul = 3, Div = 4, MixOperation = 5 };

struct StQuestion {
	int Num1 = 0;
	int Num2 = 0;
	enQuestionsLevel  QuestionLevel;
	enOperationsType OperationType;
	int CorrectAnswer = 0;
	int PlayerAnswer = 0;
	bool AnswerResult = false;
};

struct stQuiz {
	StQuestion QuestionList[100];
	short NumberOfQuestions;
	enQuestionsLevel  QuestionsLevel;
	enOperationsType OperationsType;
	short NbrCorrectAnswers = 0;
	short NbrWrongAnswers = 0;
	bool IsPass = false;
};

void PrintColor(stQuiz  Quiz, short QuestionNumber) {
	if (Quiz.QuestionList[QuestionNumber].AnswerResult == true) {
		system("color  2F");
	}
	else {
		system("color  4F");
	}

}

int PlayerAnswer() {
	int Answer;
	cin >> Answer;
	return Answer;
}

void clearScreen() {
	system("cls");
	system("color  0F");
}

short RandomNumber(int From, int To) {
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
		cout << "Enter Operation Type [1]   Add, [2] Sub, [3] Mul, [4] Div, [5] Mix  ? ";
		cin >> OperationType;
	} while (OperationType < 1 || OperationType >5);
	return (enOperationsType)OperationType;
}

string OperationSign(short OperationSigne) {
	string arr[5] = { "+", "-", "*", "/"," MIX " };
	return  arr[OperationSigne - 1];
}
enOperationsType GetRandomOperationType() {
	short rand = RandomNumber(1, 4);
	return enOperationsType(rand);
}


int SimpleCalculator(int Num1, int Num2, enOperationsType OpType) {
	if (OpType == enOperationsType::Add) {
		return Num1 + Num2;
	}
	if (OpType == enOperationsType::Sub){
		return Num1 - Num2;
	}
	if (OpType == enOperationsType::Mul) {
		return Num1 * Num2;
	}
	if (OpType == enOperationsType::Div) {
		return Num1 / Num2;
	}
}

StQuestion GenerateQuizQuestion(enQuestionsLevel QuestionLevel, enOperationsType OpType ) {
	
	StQuestion Question;
	
	if (QuestionLevel == enQuestionsLevel::MixLevel) {
		QuestionLevel = (enQuestionsLevel)RandomNumber(1, 3);
	}
	if (OpType == enOperationsType::MixOperation) {
		OpType = GetRandomOperationType();
	}

	Question.OperationType = OpType;

	switch (QuestionLevel) {
	case enQuestionsLevel::Easy:
		Question.Num1 = RandomNumber(1, 10);
		Question.Num2 = RandomNumber(1, 10);
		Question.CorrectAnswer = SimpleCalculator(Question.Num1, Question.Num2, OpType);
		Question.QuestionLevel = QuestionLevel;
		return Question;
	
	case enQuestionsLevel::Medium:
		Question.Num1 = RandomNumber(11, 50);
		Question.Num2 = RandomNumber(11, 50);
		Question.CorrectAnswer = SimpleCalculator(Question.Num1, Question.Num2, OpType);
		Question.QuestionLevel = QuestionLevel;
		return Question;
	
	case enQuestionsLevel::Hard:
		Question.Num1 = RandomNumber(51, 100);
		Question.Num2 = RandomNumber(51, 100);
		Question.CorrectAnswer = SimpleCalculator(Question.Num1, Question.Num2, OpType);
		Question.QuestionLevel = QuestionLevel;
		return Question;
	}
	return Question;
}


void GenerateQuizQuestions(stQuiz& Quiz) {

	for (int Question = 0; Question < Quiz.NumberOfQuestions; Question++) {

		Quiz.QuestionList[Question] = GenerateQuizQuestion(Quiz.QuestionsLevel , Quiz.OperationsType);
	}

}

void PrintOperation(stQuiz Quiz, int Question) {

	cout << "\nQuestion [" << Question + 1 << "/" << Quiz.NumberOfQuestions << "]\n";
	cout << Quiz.QuestionList[Question].Num1 <<"\n" ;
	cout << Quiz.QuestionList[Question].Num2 << " " << OperationSign(Quiz.QuestionList[Question].OperationType) << "\n";
	cout << "-----------" <<"\n";
}

void CheckAnswerResult(stQuiz& Quiz, int Question) {

	if (Quiz.QuestionList[Question].CorrectAnswer != Quiz.QuestionList[Question].PlayerAnswer) {
		Quiz.QuestionList[Question].AnswerResult = false;
		cout << "Wrong Answer :-)\n";
		Quiz.NbrWrongAnswers++;
		PrintColor(Quiz, Question);
	}
	else {
		Quiz.QuestionList[Question].AnswerResult = true;
		cout << "Right Answer :-)\n";
		Quiz.NbrCorrectAnswers++;
		PrintColor(Quiz, Question);
	}

	

}

void AskAndCorrectQuestionListAnswer(stQuiz& Quiz) {

	for (int Question = 0; Question < Quiz.NumberOfQuestions; Question++) {
		PrintOperation(Quiz, Question);
		Quiz.QuestionList[Question].PlayerAnswer = PlayerAnswer();
		CheckAnswerResult(Quiz, Question);
	}
	Quiz.IsPass = (Quiz.NbrCorrectAnswers > Quiz.NbrWrongAnswers);


}


void PrintFinalResult(stQuiz Quiz) {
	cout << "\n_________________________\n";
	cout << "\nFinal Results is " << endl;
	cout << "_________________________\n";
	cout << "\nNumber of Questions  : " << Quiz.NumberOfQuestions << "\n";
	cout << "Questions Level        : " << LevelName(Quiz.QuestionsLevel) << "\n";
	cout << "OpType                 : " << OperationSign(Quiz.OperationsType) << "\n";
	cout << "Number of Right Answers: " << Quiz.NbrCorrectAnswers << "\n";
	cout << "Number of wrong Answers: " << Quiz.NbrWrongAnswers << "\n";
	cout << "_________________________\n";
}

void PLayMathGame() {
	stQuiz Quiz;

	Quiz.NumberOfQuestions = HowManyQuestion();
	Quiz.QuestionsLevel = QuestionsLevel();
	Quiz.OperationsType = OperationType();

	GenerateQuizQuestions(Quiz);
	AskAndCorrectQuestionListAnswer(Quiz);
	PrintFinalResult(Quiz);
}

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

