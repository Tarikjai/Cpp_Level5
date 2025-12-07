#include <iostream>
#include <string>
using namespace std;

#include <cstdlib>  // pour rand() et srand()
#include <ctime>    // pour time()

int RandomNumber(int From, int To) {
	int RandomNumber = rand() % (To - From + 1) + From;                // génère un entier pseudo-aléatoire
	return RandomNumber;
}


enum enCharacter { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };


char printCharachter(enCharacter charcterType) {

	switch (charcterType)
	{
	case enCharacter::SmallLetter:
		return char(RandomNumber(97, 122));

	case enCharacter::CapitalLetter:
		return char(RandomNumber(65, 90));

	case enCharacter::SpecialCharacter:
		return char(RandomNumber(33, 47));

	case enCharacter::Digit:
		return char(RandomNumber(48, 57));

	}
}


int main() {

	srand((unsigned)time(NULL));

	cout << printCharachter(enCharacter::SmallLetter) << endl;
	cout << printCharachter(enCharacter::CapitalLetter) << endl;
	cout << printCharachter(enCharacter::SpecialCharacter) << endl;
	cout << printCharachter(enCharacter::Digit) << endl;
}