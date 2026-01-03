#include <iostream>  

using namespace std;



float fractionNumber(float number) {

    return number - (int(number));
}


int MyCeilResult(float number, float fraction) {


    if (abs(fraction) > 0) {

        if (number > 0)
            return int(number) + 1;
        else
            return number;

    }
    else {
        return number;
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
    float fraction = fractionNumber(number);

    cout << "My ceil Resut : " << MyCeilResult(number, fraction);



    cout << "\nC++ ceil Result: " << ceil(number);


    cout << endl;
}