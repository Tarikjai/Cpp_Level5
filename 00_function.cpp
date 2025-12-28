
#include <iostream>   
using namespace std;

enum enPrimeNotPrim { Prime = 1, NotPrime = 2 };

enPrimeNotPrim checkPrime(int Number) {
    int M = round(Number / 2);

    for (int counter = 2; counter <= M; counter++)
    {
        if (Number % counter == 0)
            return enPrimeNotPrim::NotPrime;
    }
    return enPrimeNotPrim::Prime;
}

int getPositiveNumber() {

    int number = 0;
    while (number <= 0) {
        cout << "Please insert Number: " << endl;
        cin >> number;
    }
    return number;
}

int RandomNumber(int From, int To) {
    int RandomNumber = rand() % (To - From + 1) + From;                // génère un entier pseudo-aléatoire
    return RandomNumber;
}

void ReadArray(int arr[100], int Number) {
    cout << "Enter array elements: \n";
    for (int i = 0; i < Number; i++) {
        cout << "Element [" << i + 1 << "] : ";
        cin >> arr[i];
    }

}

void PrintArray(int arr[100], int Number) {

    for (int i = 0; i < Number; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}




int main() {
    srand((unsigned)time(NULL));

    getPositiveNumber();

}