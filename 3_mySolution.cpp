#include <iostream>
#include <string>
using namespace std;

enum enDevide { Devide = 1, NotDevide = 2 };

int getPositiveNumber() {
    int number = 0;
    while (number <= 0) {
        cout << "Please insert Number: " << endl;
        cin >> number;
    }
    return number;
}

int sumOfDivisors(int number) {
    int sum = 0;
    for (int i = 1; i < number; i++) {
        if (number % i == 0) {
            sum += i;
        }
    }
    return sum;
}

enDevide isPerfectNumber(int number) {
    if (number == sumOfDivisors(number))
        return enDevide::Devide;
    else
        return enDevide::NotDevide;
}

void displayNumberStatus(int number) {
    if (isPerfectNumber(number) == enDevide::Devide)
        cout << number << " Is perfect" << endl;
    else
        cout << number << " Is Not perfect" << endl;
}

int main() {
    displayNumberStatus(getPositiveNumber());
}

