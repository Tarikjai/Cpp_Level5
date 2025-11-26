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
   
    for (char i = number + 64; i >= 65; i--) {
        for (char j =   number - i ; j <= number -65 ; j++) {
            cout << i  ;
          
        }
        cout << endl;
    }
    
    cout << endl;

}


int main() {
    int positiveNumber = getPositiveNumber("Please insert Number: ");
    printInvertedPattern(positiveNumber);


}