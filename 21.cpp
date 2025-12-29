#include <iostream>
#include <string>
using namespace std;

#include <cstdlib>  // pour rand() et srand()
#include <ctime>    // pour time()


enum enChartype { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

int RandomNumber(int From, int To) {
	int RandomNumber = rand() % (To - From + 1) + From;                // génère un entier pseudo-aléatoire
	return RandomNumber;
}

char GetRandomCharachter(enChartype charType) {

	switch (charType)
	{
	case enChartype::SmallLetter:
		return char(RandomNumber(97, 122));

	case enChartype::CapitalLetter:
		return char(RandomNumber(65, 90));

	case enChartype::SpecialCharacter:
		return char(RandomNumber(33, 47));

	case enChartype::Digit:
		return char(RandomNumber(48, 57));

	}
}

int ReadPositiveNumber() {
	int Input;
	do {
		cout << "Please insert the number of keys nedded: ";
		cin >> Input;
	} while (Input <= 0);
	return Input;
}


string GenerateWord(enChartype charType, int length) {

	string Word;

	for (int i = 1; i <= length; i++) {

		Word = Word + char(GetRandomCharachter(charType));

	}
	return Word;
}


string GenerateKey() {
	string Key = "";

	Key = GenerateWord(enChartype::CapitalLetter, 4) + "-";
	Key = Key + GenerateWord(enChartype::CapitalLetter, 4) + "-";
	Key = Key + GenerateWord(enChartype::CapitalLetter, 4) + "-";
	Key = Key + GenerateWord(enChartype::CapitalLetter, 4);

	return Key;
 

}


void GenerateKey(short NumberOfKeys) {

	for (int i = 1; i <= NumberOfKeys; i++) {
		cout << "Key [" << i << "] : " << GenerateKey();



		cout << endl;
	}

}


int main() {

	srand((unsigned)time(NULL));


	GenerateKey(ReadPositiveNumber());

}