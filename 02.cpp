#include <iostream>
#include <string>
using namespace std;

enum enPrimeNotPrim { Prime = 1, NotPrime = 2 };

int readNumber() {
	int Number;
	do {
		cout << "Please input a number: " << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}


enPrimeNotPrim checkPrime(int Number) {
	int M = round(Number / 2);

	for (int counter = 2; counter <= M; counter++)
	{
		if (Number % counter == 0)
			return enPrimeNotPrim::NotPrime;
	}
	return enPrimeNotPrim::Prime;
}

void printPrime(int Number) {
	for (int i = 1; i <= Number; i++) {
		switch (checkPrime(i)) {
		case  enPrimeNotPrim::Prime:
			cout << i << endl;
		}
	}
}


int main()
{
	printPrime(readNumber());

}
