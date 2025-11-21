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

int checkDigit(int number) {
    int digit;
    int reminder = 0;
  
    FrequencyCheck(int number, int digit)

}



void printResult(int number) {

    int digit = 0;

    for (int i = 0; number > 0; i++) {
        cout << "Digit " << digit << " Frequency is " << FrequencyCheck(number, digit) << " Time(s)";
    }
    
}
 

int main() {

    int number = getPositiveNumber("Please enter the Number: ");
    printResult(number)


}