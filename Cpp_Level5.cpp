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
    cout << endl;


    for (int i = number + 65;   i <= 90; i--) {
        cout <<  char(i)  << endl;
    }
    cout << endl;
    //cout << char(66);

}


int main() {
    int positiveNumber = getPositiveNumber("Please insert Number: ");
    printInvertedPattern(positiveNumber);


}