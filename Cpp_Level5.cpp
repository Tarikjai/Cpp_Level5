#include <iostream>
#include <string>
using namespace std;
 

void printHeader() {
	cout << "\t\t\t\tMultiplication Table From 1 to 1 " << endl;
	cout << endl;
	for (int i = 1; i <= 10; i++) {
		cout << " \t " << i ;
	}
	cout << endl;
	cout << "____________________________________________________________________________________ " << endl;

}

void printTable() {
	 

	for (int i = 1;i <= 10; i++) {

			if (i < 10)
			cout << i << "     |  " ;
			else 
				cout << i << "    |  ";
			for (int j = 1;j <= 10; j++) {
				cout << i * j << " \t ";
				
			}
			cout << endl;
	

		
	}
	

}


int main() {
	printHeader();
	printTable();
}

































//enum enPerfectNotPerfect {Perfect=2 , NotPerfect=2};
//
//int readNumber(string Message) {
//	int Number;
//	do {
//		cout << Message << endl;
//		cin >> Number;
//	} while (Number <= 0);
//	return Number;
//}
//
//int main()
//{
//	readNumber("Merci d'inserer votre nombre: ");
//}
