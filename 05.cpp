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


void print(int number) {

    int reminder = 0;

    while (number > 0) {

        reminder = number % 10;
        number = number / 10;
        cout << reminder << endl;
    }


}


int main() {

    print(getPositiveNumber("Please insert Number: "));
}