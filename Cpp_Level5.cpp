#include <iostream>
#include <string>
using namespace std;
#include <cstdlib>  // pour rand() et srand()
#include <ctime>    // pour time()




int  readPositiveNumber() {
	int number;
	do {
		cin >> number;
	} while (number < 0);
	return number;
}



void printTable(int number ) {
	
	int result = number % 10;

	cout << result;

 
}


int main() {
	 
	
	printTable(readPositiveNumber());
}
 