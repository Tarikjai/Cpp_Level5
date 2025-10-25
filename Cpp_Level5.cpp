#include <iostream>
#include <string>
using namespace std;

void PrintHeader() {
	cout << "\t\t\tMultiplication Table From 1 to 10\t\t\t" << endl;
	cout << endl;

	for (int i = 1; i <= 10; i++) {
		cout << "\t" << i ;
	}
	cout << endl;
	cout << "------------------------------------------------------------------------------------"<< endl;
}

string Column(int i) {
	if ( i < 10) 
		return " |";
	else
		return "|";
}

void printTable() {
	for (int i = 1; i <= 10; i++) {
		 
		cout << i << " " << Column(i);
		for (int j = 1; j <= 10; j++) {
		 
			cout << "\t" << i * j  ;
			 
		}
		cout << endl;
	}
}

int main()
{

	PrintHeader();
	printTable();
}
