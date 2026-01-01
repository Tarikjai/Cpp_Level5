#include <iostream>  
using namespace std;


float getFraction(float number) {

    return  number - (int(number));
}


int MyRoundResult(float number) {

    float fractionNumber = getFraction(number);
    int intNumber = int(number);


    if (abs(fractionNumber) >= 0.5) {
        if (number > 0) {
            return ++intNumber;
        }
        else {
            return --intNumber;
        }
    }
    else {
        return intNumber;
    }
}


float ReadNumber() {

    float number = 0;
    //  while (number <= 0) {
    cout << "Please insert Number: " << endl;
    cin >> number;
    //  }
    return number;
}


int main() {

    float number = ReadNumber();


    cout << "My Round Resut : " << MyRoundResult(number);

    // PrintArray(arrSource, Sourcelength);

    cout << "\nC++ Round Result: " << round(number);


    cout << endl;
}