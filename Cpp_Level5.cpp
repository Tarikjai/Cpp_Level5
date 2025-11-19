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


void printResult(int number, int FrequencyCounter) {
     
    cout << "Digit " << number << " Frequency is " << FrequencyCounter << " Time(s)";

}

int main() {

    int number = getPositiveNumber("Please enter the Number: ");
    int digit = getPositiveNumber("Please enter the frequency ");
   
    
    printResult(number, FrequencyCheck(number, digit));


}