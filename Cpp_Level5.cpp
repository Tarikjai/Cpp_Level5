#include <iostream>
#include <string>
using namespace std;
 
enum enPerfectNotPerfect {Perfect=2 , NotPerfect=2};

int readNumber(string Message) {
	int Number;
	do {
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

int main()
{
	readNumber("Merci d'inserer votre nombre: ");
}
