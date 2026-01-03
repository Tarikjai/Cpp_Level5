#include <iostream>  
using namespace std;


float MySQRT(float number) {

    return  pow(number, 0.5);
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


    cout << "My SQRT Resut : " << MySQRT(number);



    cout << "\nSQRT Result: " << sqrt(number);


    cout << endl;
}