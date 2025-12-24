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

void FillArray(int arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++) {
        arr[i] = RandomNumber(1, 100);
    }
}

void ReverseArrayOrder(int arr[100], int arr2[100], int arrLength) {

    for (int i = 0; i < arrLength; i++) {
        arr2[i] = arr[arrLength - 1 - i];

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
    int arr2[100];
    int arrLength = getPositiveNumber(" ");

    cout << "\nArray Elements before shuffle: ";

    FillArray(arr, arrLength);



    ReverseArrayOrder(arr, arr2, arrLength);

    PrintArray(arr, arrLength);
    cout << "\nArray 2 Element after copiyng array 1 in reversed order: ";

    PrintArray(arr2, arrLength);
    cout << "  " << endl;

    return 0;
}