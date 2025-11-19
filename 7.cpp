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


int print(int number) {

    int reminder = 0;
    int Reversednumber = 0;



    while (number > 0) {


        reminder = number % 10;
        number = number / 10;

        Reversednumber = Reversednumber * 10 + reminder;

    }
    return  Reversednumber;
}


int main() {

    cout << "\nReversed is  = " << print(getPositiveNumber("Please insert Number: ")) << "\n";



}