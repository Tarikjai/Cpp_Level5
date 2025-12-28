#include <iostream>   
using namespace std;

 
int getPositiveNumber(string Message) {
    int Number;
    do {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

int RandomNumber(int From, int To) {
    int RandomNumber = rand() % (To - From + 1) + From;                // génère un entier pseudo-aléatoire
    return RandomNumber;
}
 
void FillArrayWithRandomNumbers(int arrSource[100], int& Sourcelength) {
    for (int i =0; i < Sourcelength; i++) {
        arrSource[i] = RandomNumber(1, 100);
    }
}
 
void copyInReversedOrder(int arrSource[100], int arrSource2[100], int Sourcelength) {
    for (int i = 0; i < Sourcelength; i++) {
        arrSource2[i] = arrSource[Sourcelength-i-1] ;
         
    }
}

void PrintArray(int arrSource[100], int Number) {
    for (int i = 0; i < Number; i++) {
        cout << arrSource[i] << " ";
    }
    cout << "\n";
}
 


int main() {
    srand((unsigned)time(NULL));

    int arrSource[100];
    int Sourcelength = getPositiveNumber("");
    int arrSource2[100];   

    FillArrayWithRandomNumbers(arrSource, Sourcelength);
 
    cout << "Array 1 elements : ";
    PrintArray(arrSource, Sourcelength);
  
    cout << "\nArray 2 elements after copying array1 in reversed order : ";
    copyInReversedOrder(arrSource, arrSource2, Sourcelength);
   
    PrintArray(arrSource2, Sourcelength);
    cout << "\n";
}