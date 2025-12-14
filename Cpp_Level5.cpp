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

 

void ArrayElement(int Element[100], int& length) {
    cout << "Enter array elements: " << endl;

    for (int i = 0 ; i < length ; i++) {
        cout << "Element [" << i + 1 << "] : ";
        cin >> Element[i];
    }
 
}

void printArray(int Element[100], int& length) {
    cout << "Original array: ";
    for (int i = 0; i < length; i++) {
        cout <<  Element[i] << " " ;
    }
    cout << endl;
 
}

 

int printFrequency(int Element[100],int length, int digit) {

    int frequency=0;
    for (int i = 0; i < length; i++) {
        if (Element[i] == digit) {
            frequency++;
        }
    }
    return frequency;
    
}

int main() {

	srand((unsigned)time(NULL));

    int Element[100], length = ReadPositiveNumber("Enter number of elements: ");
 
    ArrayElement(Element, length);
   

    int digit = ReadPositiveNumber("Enter the number you want to check: ");
    printArray(Element, length);

    cout << digit << " is repeated " << printFrequency(Element, length, digit) << " times";

}
