#include <iostream>
#include <string>
using namespace std;

#include <cstdlib>  // pour rand() et srand()
#include <ctime>    // pour time()

int ReadPositiveNumber(string Message) {
	int input;
	do {
		cout << Message;
		cin >> input ;
	} while (input <= 0);
	return input;
}

enum enChartype { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

int GenerateCharacter(int From, int To) {
	 
	int Rand = rand() % (To - From + 1) + From;
	return  Rand;
}

char  checkLetter(enChartype chartype) {
	switch (chartype) {
	case(enChartype::SmallLetter):
		return GenerateCharacter(97, 122);
		break;
	case(enChartype::CapitalLetter):
		return GenerateCharacter(65, 90);
		break;
	case(enChartype::SpecialCharacter):
		return GenerateCharacter(34, 47);
		break;
	case(enChartype::Digit):
		return GenerateCharacter(48, 57);
		break;
	}
}

string GenrateWord(enChartype chartype, short length) {
	 string Word = "";

	 for (int i = 1; i <= length; i++) {
		 Word += checkLetter(enChartype::CapitalLetter);
	 }
	 return Word; 
}

string GenerateKey() {
	string Key = "";

	Key = GenrateWord(enChartype::CapitalLetter, 4) + "-";
	Key = Key + GenrateWord(enChartype::CapitalLetter, 4) + "-";
	Key = Key + GenrateWord(enChartype::CapitalLetter, 4) + "-";
	Key = Key + GenrateWord(enChartype::CapitalLetter, 4);
	return Key;
}

void PrintKeys(int input) {

	for (int i = 1;  i <= input; i++) {
		cout << "Key [" << i << "] : " << GenerateKey() << endl;
	}
}


int main() {

	srand((unsigned)time(NULL));
	 

	PrintKeys(ReadPositiveNumber("How Much keys you want to generate? ")) ;

}                                                                  