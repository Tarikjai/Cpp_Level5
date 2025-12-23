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


int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;
    
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}



void CopyOnlyPrimeNumbers(int arr[100], int arr2[100], int arrLength, int& arr2Length)
{
    
    for (int i = 0; i < arrLength; i++) {
       
        if (checkPrime(arr[i])== enPrimeNotPrim::Prime) {
            arr2[arr2Length] = arr[i];
            arr2Length++;
        } 
    }
    cout << "\n";
}



void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

}


void PrintPrimeArray(int arr2[100], int arr2Length)
{
    cout << "\nPrime Numbers in Array2 : ";
    for (int i = 0; i < arr2Length; i++) {

        cout << arr2[i] << " ";

    }
    cout << "\n";
}



int main() {

    srand((unsigned)time(NULL));

    int arr[100];
    
    int arrLength;


    FillArrayWithRandomNumbers(arr, arrLength);

    

    int arr2[100];
    int arr2Length=0;

    CopyOnlyPrimeNumbers(arr, arr2, arrLength, arr2Length);


    cout << "\nArray 1 Elements: ";
    PrintArray(arr, arrLength);
    cout << "\nArray 2 Elements: ";
    PrintArray(arr2, arr2Length);
    return 0;  
}