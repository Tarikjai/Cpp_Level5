#include <iostream>  
using namespace std;







void ReadArray(int arrSource[100], int& Sourcelength) {
    Sourcelength = 10;

    arrSource[0] = 10;
    arrSource[1] = 10;
    arrSource[2] = 10;
    arrSource[3] = 50;
    arrSource[4] = 50;
    arrSource[5] = 70;
    arrSource[6] = 70;
    arrSource[7] = 70;
    arrSource[8] = 70;
    arrSource[9] = 90;
}



short findNumberPosition(int Number, int arrSource[100], int& Sourcelength) {
    for (int i = 0; i < Sourcelength; i++) {
        if (arrSource[i] == Number) {
            return i;
       }
    }
     return -1;       
}

void AddItemmToArray(int Number, int arrSource[100], int& Sourcelength) {
    Sourcelength++;
    arrSource[Sourcelength - 1] = Number;
}



bool IsNumberInArray(int Number, int arrSource[100], int& Sourcelength) {
    return findNumberPosition( Number,  arrSource,  Sourcelength) != -1;
}


void copyDistantNumber(int arrSource[100], int Sourcelength, int arrDestination[100], int& Destinationlength) {
    for (int i = 0; i < Sourcelength; i++) {

        if (!IsNumberInArray(arrSource[i], arrDestination, Destinationlength)) {
            AddItemmToArray(arrSource[i], arrDestination, Destinationlength);
        }
        
    }
}

void PrintArray(int arrSource[100], int Sourcelength) {
    for (int i = 0; i < Sourcelength; i++) {
        cout << arrSource[i] << " ";
    }
}

int main() {

    int arrSource[100];
    int Sourcelength;
    int arrDestination[100];
    int Destinationlength = 0;


    ReadArray(arrSource, Sourcelength);
    
    copyDistantNumber(arrSource, Sourcelength, arrDestination, Destinationlength);

    cout << "Array elements : ";

    PrintArray(arrSource, Sourcelength);

    cout << "\nArray 2 : ";

    PrintArray(arrDestination, Destinationlength);
    cout << endl;





}