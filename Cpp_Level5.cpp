#include <iostream>
#include <string>
using namespace std;

int getPositiveNumber(string Message) {
    int number = 0;
    do {
        cout << Message << endl;
        cin >> number;
    } while (number <= 0);
    return number;
}



int FrequencyCheck(int number, int digit) {
    int reminder = 0;
    int FrequencyCounter = 0;
    while (number > 0) {
        reminder = number % 10;
        number = number / 10;
        if (reminder == digit) {
            FrequencyCounter++;
         }
    }
    return  FrequencyCounter;
}



void printResult(int number) {
    
    for (int i = 0; i <= 9; i++) {
        if (FrequencyCheck(number, i) > 0) {
            cout << "Digit " << i << " Frequency is " << FrequencyCheck(number, i) << " Time(s)" << endl;
        }
       
    }
}
 

int main() {

    int number = getPositiveNumber("Please enter the Number: ");
    printResult(number);



}