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

void swapFunction(int& A, int& B) {
    int temp;

    temp = A;
    A = B;
    B = temp;
}

void fillNumber1toN(int arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++) {
        arr[i] = i + 1;
    }
}

void ShuffleArray(int arr[100], int arrLength) {
    int arr1Index, arr2Index;
    for (int i = 0; i < arrLength; i++) {

        arr1Index = RandomNumber(1, arrLength) - 1;
        arr2Index = RandomNumber(1, arrLength) - 1;

        swapFunction(arr[arr1Index], arr[arr2Index]);
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

    fillNumber1toN(arr, arrLength);

    cout << "\nArray Elements before shuffle: ";
    PrintArray(arr, arrLength);


    ShuffleArray(arr, arrLength);

    cout << "\nArray Element after shuffles: ";
    PrintArray(arr, arrLength);
    cout << "  " << endl;

    return 0;
}