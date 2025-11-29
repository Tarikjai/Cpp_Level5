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

void printInvertedPattern(int number) {


    cout << endl;
    cout << "Output: " << endl;

    for (int i = 65; i <= 65 + number; i++) {

        for (int j = 1; j <= number - (65 + number - 1 - i); j++) {
            cout << char(i);
        }


        cout << endl;
    }


}

int main() {
    int positiveNumber = getPositiveNumber("Please insert Number: ");
    printInvertedPattern(positiveNumber);
}