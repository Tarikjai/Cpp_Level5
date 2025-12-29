#include <iostream>   
using namespace std;


enum enChartype { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

int getPositiveNumber(string Message) {
    int Number;
    do {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

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

void FillArrayWithRandomNumbers(string arrSource[100], int& Sourcelength) {
    for (char i =0; i < Sourcelength; i++) {
        arrSource[i] = GenerateKey();
    }
}


void PrintArray(string arrSource[100], int Number) {
    for (char i = 0; i < Number; i++) {
        cout <<"Array ["<<i+1 << "] : " << arrSource[i] << " \n" ;
    }
    cout << "\n";
}
 


int main() {
    srand((unsigned)time(NULL));

	string arrSource[100];
    int Sourcelength = getPositiveNumber("");
     
	FillArrayWithRandomNumbers( arrSource, Sourcelength);
 
    cout << "Array elements : \n\n";
    PrintArray(arrSource, Sourcelength);
  
   
    cout << "\n";
}