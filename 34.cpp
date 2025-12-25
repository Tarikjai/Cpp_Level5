#include <iostream>  
using namespace std;

int getPositiveNumber(string Message) {
    int number = 0;
    while (number <= 0) {
        cout << Message << endl;
        cin >> number;
    }
    return number;
}

int RandomNumber(int From, int To) {
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}


short checkPosition(int arr[100], int arrLength, int digit) {
    for (int i = 0; i < arrLength; i++) {
        if (digit == arr[i]) {

            return   i;
        }

    }
    return -1;

}



void fillNumber(int arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++) {
        arr[i] = RandomNumber(1, 100);
    }
}



void PrintArray(int arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    srand((unsigned)time(NULL));

    int arr[100];

    int arrLength = getPositiveNumber(" ");

    fillNumber(arr, arrLength);

    cout << "\nArray 1 Elements: ";
    PrintArray(arr, arrLength);

    int digit = getPositiveNumber("\n\nPlease enter a number to search for ?");
    // ShuffleArray(arr, arrLength);

    cout << "\nNumber you are looking for is:  " << digit << "\n";

    short Positionn = checkPosition(arr, arrLength, digit);

    if (Positionn == -1) {
        cout << "\nNumber not found  :(  ";
    }
    else {
        cout << "\nNumber found  at position:  " << Positionn;
        cout << "\nNumber found  at order:  " << Positionn + 1 << "\n";
    }


    return 0;
}