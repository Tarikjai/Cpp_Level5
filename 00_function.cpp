
#include <iostream>   
using namespace std;

int getPositiveNumber() {

    int number = 0;
    while (number <= 0) {
        cout << "Please insert Number: " << endl;
        cin >> number;
    }
    return number;
}


int RandomNumber(int From, int To) {
    int RandomNumber = rand() % (To - From + 1) + From;                // génère un entier pseudo-aléatoire
    return RandomNumber;
}

int main() {
    srand((unsigned)time(NULL));

    getPositiveNumber();

}