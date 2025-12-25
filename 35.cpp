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

short FindNumberPositionInArray(int arr[100], int arrLength, int digit) {
    for (int i = 0; i < arrLength; i++) {
        if (digit == arr[i]) {

            return   i;
        }

    }
    return -1;

}

bool IsNumberInArray(int arr[100], int arrLength, int digit) {

    return FindNumberPositionInArray(arr, arrLength, digit) != -1;

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


    if (IsNumberInArray(arr, arrLength, digit)) {


        cout << "\nYes The number is  found :-)\n";
    }
    else {

        cout << "\nNo The number is not found :-(\n";
    }


    return 0;
}