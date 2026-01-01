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

void ReadArray(int arrSource[100], int& Sourcelength) {


    cin >> Sourcelength;
    for (int i = 0; i < Sourcelength; i++) {
        arrSource[i] = RandomNumber(-100, 100);
    }
}


void PrintArray(int arrSource[100], int Sourcelength) {
    for (int i = 0; i < Sourcelength; i++) {
        cout << arrSource[i] << " ";
    }
}

int checkNegativeNumbers(int arrSource[100], int Sourcelength) {
    int counter = 0;
    for (int i = 0; i < Sourcelength; i++) {
        if (arrSource[i] < 0)
            counter++;
    }
    return counter;


}

int main() {

    int arrSource[100];
    int Sourcelength;

    srand((unsigned)time(NULL));

    ReadArray(arrSource, Sourcelength);


    cout << "Array elements : ";

    PrintArray(arrSource, Sourcelength);

    cout << "\nNegative Numbers count is: " << checkNegativeNumbers(arrSource, Sourcelength);


    cout << endl;
}