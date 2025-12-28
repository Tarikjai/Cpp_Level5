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



void ReadArray(int arr[100], int Number) {
    cout << "Enter array elements: \n";
    for (int i = 0; i < Number; i++) {
        cout << "Element [" << i+1  << "] : ";
        cin >> arr[i];
    }
    
}

void PrintArray(int arr[100], int Number) {

    for (int i = 0; i < Number; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int checkFrequency(int digit , int arr[100], int length) {
    int counter = 0;
    for (int i = 0; i < length; i++) {
        if (arr[i] == digit)
            counter++;
    }
    return counter;
}


int main() {
    
    srand((unsigned)time(NULL));

    int arr[100];

    int length = getPositiveNumber("");

    ReadArray(arr, length);

    int digit = getPositiveNumber("Enter the number you want to ckeck: ");
     

    cout << "Original array : ";
    PrintArray(arr, length);
   
    cout << digit << " is repeated " << checkFrequency(digit, arr, length) << " time(s)";


}