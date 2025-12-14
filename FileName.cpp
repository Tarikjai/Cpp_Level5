#include <iostream>
#include <string>

using namespace std;

void ReadNumber(int arr[100], int& length){
	cout << "How many number you would like to enter: ";
	cin >> length;
	for (int i = 0; i <= length - 1; i++){
		cout << "Please enter the number [" << i + 1 << "]: " << endl;
		cin >> arr[i];
	}
}

void PrintNumber(int arr[100], int length){
	for (int i = 0; i <= length - 1; i++)
	{
		cout << "Number [" << i + 1 << "] = " << arr[i] << endl;
	}
}

int SumNumbers(int arr[100], int length){
	int Sum = 0;
	for (int i = 0; i <= length - 1; i++){
		Sum += arr[i];
	}
	return Sum;
}

int main() {

	int arr[100], length = 0;
	ReadNumber(arr, length);
	PrintNumber(arr, length);
	cout << "Sum of total numbers is : " << SumNumbers(arr, length) << endl;
	cout << "Average of total number  " << SumNumbers(arr, length) / length;
}