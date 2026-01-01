#include <iostream>  
using namespace std;





int MyFloorResult(float number) {

    if (number > 0) {
        return int(number);
    }
    else {
        return number - 1;
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


    cout << "My Floor Resut : " << MyFloorResult(number);

    // PrintArray(arrSource, Sourcelength);

    cout << "\nC++ Floor Result: " << floor(number);


    cout << endl;
}