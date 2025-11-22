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



bool IsPalindromeNumber(int number) {
    return number == ReverseNumber(number);
}

void PrintResult(int number) {
    if (IsPalindromeNumber(number))
        cout << "Yes, it's a Palindrome number" << endl;
    else
        cout << "No, it is Not a Palindrome number" << endl;
}

int main() {

    int positiveNumber = getPositiveNumber("Please insert Number: ");
    int ReversedNumber = ReverseNumber(positiveNumber);
    PrintResult(positiveNumber);



}