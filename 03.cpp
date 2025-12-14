#include <iostream>
#include <string>
using namespace std;

int getPositiveNumber(string Message) {
    int number = 0;
    while (number <= 0) {
        cout << Message << endl;
        cin >> number;
    }
    return number;
}

bool  isPerfectNumber(int number) {
    int sum = 0;
    for (int i = 1; i < number; i++) {
        if (number % i == 0) {
            sum += i;
        }
    }
    return sum == number;
}

void displayNumberStatus(int number) {
    if (isPerfectNumber(number))
        cout << number << " Is perfect" << endl;
    else
        cout << number << " Is Not perfect" << endl;
}

int main() {
    displayNumberStatus(getPositiveNumber("Please insert Number: "));
}