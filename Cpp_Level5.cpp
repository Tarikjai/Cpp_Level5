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


int RandomNumber(int From, int To) {
	int RandomNumber = rand() % (To - From + 1) + From;                // génère un entier pseudo-aléatoire
	return RandomNumber;
}


void ReadArray(int arr[100], int& length) {

	for (int i = 0; i < length; i++) {
		 arr[i] = RandomNumber(1, 100);
	}
	
}


void PrintArray(int arr[100], int& length) {
	cout << "Array Elements : ";
	for (int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


int CheckMAX(int arr[100], int& length) {
	
	int Max = 0;
	for (int i = 0; i < length; i++) {
		if (Max < arr[i]) {
			Max = arr[i];
		}
		
	}
	return Max ;
}



int main() {
	
	srand((unsigned)time(NULL));

	int arr[100];
	int length;

	length = ReadPositiveNumber("Enter the array size :\n");

	ReadArray(arr, length);
	PrintArray(arr, length);
   cout <<   "Max Number is: " <<  CheckMAX(arr, length);





}
 