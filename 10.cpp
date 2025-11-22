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


int ReverseNumber(int number) {
    int reminder = 0;
    int Reversednumber = 0;

    while (number > 0) {
        reminder = number % 10;
        number = number / 10;
        Reversednumber = Reversednumber * 10 + reminder;
    }
    return  Reversednumber;
}

void PrintDigits(int Reversednumber) {

    int reminder = 0;

    while (Reversednumber > 0) {

        reminder = Reversednumber % 10;
        Reversednumber = Reversednumber / 10;
        cout << reminder << endl;
    }


}

int main() {

    int positiveNumber = getPositiveNumber("Please insert Number: ");
    PrintDigits(ReverseNumber(positiveNumber));



}