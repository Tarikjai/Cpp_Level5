#include <iostream>  
using namespace std;



void FillArray(int arrSource[100], int& Sourcelength) {
    Sourcelength = 6;

    arrSource[0] = 10;
    arrSource[1] = 20;
    arrSource[2] = 30;
    arrSource[3] = 30;
    arrSource[4] = 20;
    arrSource[5] = 10;
}





void PrintArray(int arrSource[100], int Sourcelength) {
    for (int i = 0; i < Sourcelength; i++) {
        cout << arrSource[i] << " ";
    }
}

bool IsPalindromeArray(int arrSource[100], int Sourcelength) {
    for (int i = 0; i < Sourcelength; i++) {
        if (arrSource[i] != arrSource[Sourcelength - i - 1]) {
            return false;
        }
    }
    return true;


}

int main() {

    int arrSource[100];
    int Sourcelength;
 


    FillArray(arrSource, Sourcelength);
    
   
    cout << "Array elements : ";

    PrintArray(arrSource, Sourcelength);


   

    cout << "\n";
    if (IsPalindromeArray(arrSource, Sourcelength)!= 0)
        cout << "\nYes , array is a Palindrome.\n";
        
    else
        cout << "\nNo , it is NOT a Palindrome number.\n";    
    


    cout << endl;





}