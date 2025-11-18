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


int Sum(int number) {
    int reminder = 0;
    int sum = 0;

    while (number > 0) {
        reminder = number % 10;
        number = number / 10;
        sum += reminder;
    }
    return sum;
}



int main() {

    cout << "\nSum of Digits = " << Sum(getPositiveNumber("Please insert Number: ")) << "\n";

}