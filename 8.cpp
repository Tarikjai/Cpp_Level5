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



int main() {

    int number = getPositiveNumber("Please enter the Number: ");
    int digit = getPositiveNumber("Please enter the frequency ");

    cout << "Digit " << digit << " Frequency is " << FrequencyCheck(number, digit) << " Time(s)";



}