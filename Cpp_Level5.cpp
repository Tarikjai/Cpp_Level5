#include <iostream>  
using namespace std;

int ReadNumber(string Message) {
    int number = 0;
   // while (number <= 0) {
        cout << Message << endl;
        cin >> number;
   // }
    return number;
}

int AddArrayElement(int number ,int arr[100], int& arrLength) {
    arrLength++;
    arr[arrLength-1]= number ;
   
    return number;
}

void InputUserNumbersInArray(int arr[100], int& arrLength) {
    
    
    bool AddMore = true ;

    do {
        AddArrayElement(ReadNumber("Please enter a number: "), arr,  arrLength);
       
        cout << "Do you want to add more numbers? [0]:No, [1]:Yes ? ";
        cin >> AddMore;
    } while (AddMore) ;
     
  
}

void PrintArray(int arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
   

    int arr[100];
    int arrLength=0;

    InputUserNumbersInArray(arr, arrLength);
    cout << "\nArray lenght: " << arrLength;
    cout << "\nArray elements: ";
   
    PrintArray(arr, arrLength);
    cout << "\n ";
}
