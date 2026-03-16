#pragma once
#include <iostream>

using namespace std;

namespace InputLib
{
	int QuestionNumber() {
		int QuestionNumber;
		do {
			cout << "How Many Questions do you want to answer? ";
			cin >> QuestionNumber;
		} while (QuestionNumber < 1 || QuestionNumber >10);
		return QuestionNumber;
	}

	int RandomNumber(int From, int To) {
		int RandomNumber = rand() % (To - From + 1) + From;
		return RandomNumber;
	}

	string GetOperationName(int Optype) {

		string arr[5] = { "+", "-", "*", "/", "Mix" };

		return arr[Optype - 1];
	}


	string GetLevelName(int LevelName) {

		string arr[4] = { "Easy", "Medium", "Hard", "Mix"};

		return arr[LevelName - 1];
	}

	int PAnswer() {
		int answer;
		cin>> answer;
		return answer;
	}

	string FinalResult(bool result) {

		if (result) {
			return "PASS";
		}
		else {
			return "FAIL";
		}
	}



}