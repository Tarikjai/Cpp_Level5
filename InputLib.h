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

}