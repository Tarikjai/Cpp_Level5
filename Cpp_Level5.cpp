#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string to use std::string (though not used in this example).
#include <cstdlib>    // Include cstdlib for rand() and srand() functions.
#include <ctime>      // Include ctime for the time() function.
using namespace std;


int ReadPositiveNumber(string Message){
    int number = 0;
    while (number <= 0) {
        cout << Message << endl;
        cin >> number;
    }
    return number;
}

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum; 
}


void ReadElement(int arr[100], int& length) {
   
    for (int i = 0; i <= length -1 ; i++) {
        arr[i] = RandomNumber(1, 100);
    }
     
}

void printarray(int arr[100], int& length) {
    cout << "Array Element: ";
    for (int i = 0; i <= length - 1; i++) {
       cout << arr[i] << " ";
    }
    
}



int main() {

    int arr[100];
    int length = ReadPositiveNumber("How much element in the array: ");

    srand((unsigned)time(NULL));

    ReadElement(arr, length);
    printarray(arr, length);
   
    return 0;  
}