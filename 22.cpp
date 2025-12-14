#include <iostream>
#include <string>
using namespace std;
#include <cstdlib>  // pour rand() et srand()
#include <ctime>    // pour time()

int ReadPositiveNumber(string Message) {
	int input;
	do {
		cout << Message;
		cin >> input;
	} while (input <= 0);
	return input;
}

void ReadArray(int arr[10], int& length) {

	cout << "Enter Number of elements: :\n";
	cin >> length;
	cout << endl;

	cout << "Enter Array elements: " << endl;

	for (int i = 0; i < length; i++) {
		cout << "Element [" << i + 1 << "] : ";
		cin >> arr[i];
	}
	cout << endl;
}

void PrintArray(int arr[10], int length) {

	cout << "\nOriginal array : ";
	for (int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


int checkFrequency(int arr[10], int length, int NumberToCheck) {
	int frequency = 0;

	for (int i = 0; i < length; i++) {

		if (NumberToCheck == arr[i]) {
			frequency++;
		}
	}
	return frequency;
}

int main() {
	int arr[10];
	int length;
	int NumberToCheck;

	ReadArray(arr, length);


	NumberToCheck = ReadPositiveNumber("Enter the nuumber you want to check :\n");

	PrintArray(arr, length);

	cout << NumberToCheck << " is repeated " << checkFrequency(arr, length, NumberToCheck) << " time(s)";


}
