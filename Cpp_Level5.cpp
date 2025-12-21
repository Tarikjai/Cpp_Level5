#include <iostream>
#include <string>
using namespace std;

/*
int getPositiveNumber(string Message) {
    int number = 0;
    do {
        cout << Message << endl;
        cin >> number;
    } while (number <= 0);
    return number;
}
*/



void print() {
    for (int i = 65; i <= 90; i++) {
       for (int j = 65; j <= 90 ; j++) {
           for (int j = 65; j <= 90; j++) {
               cout << char(i);
           }
       }
       cout << endl;
    }
}


int main() {
    print();
}

//65   90