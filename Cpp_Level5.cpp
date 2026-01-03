#include <iostream>  
using namespace std;


 


int MyCeilResult(float number) {

    if (number > 0) {
        return int(number);
    }
    else {
        return number -1 ;
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
  
   
    cout << "My ceil Resut : " << MyCeilResult(number);

   // PrintArray(arrSource, Sourcelength);

    cout << "\nC++ ceil Result: " << ceil(number);


    cout << endl;
} 