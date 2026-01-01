#include <iostream>  
using namespace std;



int getNumber() {

    int number = 0;
    //  while (number <= 0) {
    cout << "Please insert Number: " << endl;
    cin >> number;
    //  }
    return number;
}


int MyAbsResult(int number)
{
    if (number < 0)
    {
        number *= -1;
    }
    return number;
}
int main() {

    int number = getNumber();


    cout << "My abs Resut : " << MyAbsResult(number);

    // PrintArray(arrSource, Sourcelength);

    cout << "\nC++ abs Result: " << abs(number);


    cout << endl;
}