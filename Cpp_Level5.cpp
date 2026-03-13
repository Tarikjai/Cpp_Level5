#include <iostream>  
#include <conio.h>
#include <string>
using namespace std;

enum enQuestionsLevel { Easy=1, Medium=2, Hard=3, MixLevel=4};
enum enOperationsType { Add = 1, Sub = 2, Mul = 3, Div=4, MixOperation=5 };

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
	short NumberOfQuestions ;
	 enQuestionsLevel  QuestionsLevel;
	 enOperationsType OperationsType;
	short NbrCorrectAnswers = 0;
	short NbrWrongAnswers = 0;
	bool IsPass = false;
};

/*
RandomNumber(51, 100);
RandomNumber(21, 50);
RandomNumber(11, 20);
RandomNumber(1, 10);
*/

void PrintColor(stQuiz  Quizz, short QuestionNumber) {
	if (Quizz.QuestionList[QuestionNumber].AnswerResult == true) {
		system("color  2F");
	} 
	else  {
		system("color  4F");
	}
	 
}

bool FinalResult(stQuiz  Quizz) {
	if (Quizz.NbrCorrectAnswers > Quizz.NbrWrongAnswers) {
		return Quizz.IsPass = true;
	}
	else if (Quizz.NbrCorrectAnswers < Quizz.NbrWrongAnswers) {
		return Quizz.IsPass = false;
	}
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
	string arr[5] = { "+", "-", "*", "/"," MIX "};
	return  arr[OperationSigne - 1];
}
 
string OperationSignName(short OperationSignName) {
	string arr[5] = { "+", "-", "*", "/", "Mix" };
	return  arr[OperationSignName - 1];
}

enOperationsType GetRandomOperationType() {
	short OperationType =  RandomNumber(1, 4);
	return (enOperationsType)OperationType;
}

int SimpleCaluclator(int Num1, int Num2, enOperationsType OpType) {

	if (OpType == enOperationsType::Add) {
		return Num1 + Num2;
	}
	else  if (OpType == enOperationsType::Sub) {
		return Num1 - Num2;
	}
	else  if (OpType == enOperationsType::Mul) {
		return Num1 * Num2;
	}
	else  if (OpType == enOperationsType::Div) {
		return Num1 / Num2;
	}
}

StQuestion GenerateQuizQuestion(enQuestionsLevel QuestionLevel, enOperationsType OpType) {
	StQuestion Question;

	if (QuestionLevel == enQuestionsLevel::MixLevel) {

		QuestionLevel = (enQuestionsLevel) RandomNumber(1, 3);
	}
	if (OpType == enOperationsType::MixOperation) {
		OpType = GetRandomOperationType();
	}
	Question.OperationType = OpType;

	switch (QuestionLevel) {
	case enQuestionsLevel::Easy:
		Question.Num1 = RandomNumber(1, 10);
		Question.Num2 = RandomNumber(1, 10);
		Question.CorrectAnswer = SimpleCaluclator(Question.Num1, Question.Num2, Question.OperationType);
		Question.QuestionLevel = QuestionLevel;
		return Question ;
	 
	case enQuestionsLevel::Medium:
		Question.Num1 = RandomNumber(11, 50);
		Question.Num2 = RandomNumber(11, 50);
		Question.CorrectAnswer = SimpleCaluclator(Question.Num1, Question.Num2, Question.OperationType);
		Question.QuestionLevel = QuestionLevel;
		return Question;
	 
	case enQuestionsLevel::Hard:
		Question.Num1 = RandomNumber(51, 100);
		Question.Num2 = RandomNumber(51, 100);
		Question.CorrectAnswer = SimpleCaluclator(Question.Num1, Question.Num2, Question.OperationType);
		Question.QuestionLevel = QuestionLevel;
		return   Question;
	}
	return   Question;
}

void GenerateQuizQuestions(stQuiz& Quizz) {

	for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestions ; QuestionNumber++) {
		Quizz.QuestionList[QuestionNumber] = GenerateQuizQuestion(Quizz.QuestionsLevel , Quizz.OperationsType);
	}

}

void PrintQuestion(stQuiz Quizz, short QuestionNumber) {

	cout << "Question [" << QuestionNumber  << "/" << Quizz.NumberOfQuestions << "]\n\n";
	cout << Quizz.QuestionList[QuestionNumber].Num1 << "\n";
	cout << Quizz.QuestionList[QuestionNumber].Num2 << "  ";
	cout << OperationSignName(Quizz.QuestionList[QuestionNumber].OperationType) << "\n";
	cout << "-----------\n" ;
}

int PlayerAnswer() {
	int answer;
	cin >> answer;
	return answer;
}

void CorrectTheQuestionAnswer(stQuiz& Quizz, short QuestionNumber) {

		if (Quizz.QuestionList[QuestionNumber].PlayerAnswer != Quizz.QuestionList[QuestionNumber].CorrectAnswer) {

			  Quizz.QuestionList[QuestionNumber].AnswerResult = false;
			  cout << "Wrong Answer :-)\n";
			  cout << "The right answer is: " << Quizz.QuestionList[QuestionNumber].CorrectAnswer << "\n\n\n";
			  Quizz.NbrWrongAnswers++;
		  
		}
		else {
			Quizz.QuestionList[QuestionNumber].AnswerResult = true;
			cout << "Right Answer :-)\n\n\n";
			Quizz.NbrCorrectAnswers++;
		}
	PrintColor(Quizz, QuestionNumber);
}

void AskAndCorrectQuestionListAnswer(stQuiz& Quizz) {

	for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestions; QuestionNumber++) {

		PrintQuestion(Quizz, QuestionNumber);
		Quizz.QuestionList[QuestionNumber].PlayerAnswer = PlayerAnswer();
		
		CorrectTheQuestionAnswer(Quizz, QuestionNumber);
	}

	Quizz.IsPass = Quizz.NbrCorrectAnswers > Quizz.NbrWrongAnswers;

}

string checkWinner(stQuiz Quizz) {
	if (Quizz.IsPass){
		return " You WIN";
	}
	else {
		return " You loose";
	}

}

void PrintFinalResult(stQuiz Quizz) {

	cout << "\n\n----------------------------------------------------------\n\n";
	cout << "Final Result is " << checkWinner(Quizz) <<  "\n";
	cout << "\n\n----------------------------------------------------------\n";
	cout << "\nNumber Of Question:" << Quizz.NumberOfQuestions  << "\n";
	cout << "Questions Level: " << LevelName(Quizz.QuestionsLevel) << "\n";
	cout << "Op Type : " << OperationSign(Quizz.OperationsType) << "\n";
	cout << "Number of Right Answers :" << Quizz.NbrCorrectAnswers << "\n";
	cout << "Number of Wrong Answers :" << Quizz.NbrWrongAnswers << "\n";
	cout << "\n----------------------------------------------------------\n";
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