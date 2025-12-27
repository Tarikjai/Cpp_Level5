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


void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    arrLength++;
    arr[arrLength - 1] = Number;
}

void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;

    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}

void PrintArray(int arr[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void CopyPrimeNumbers(int arr[100], int arr2[100], int arrLength, int& arr2Length)
{

    for (int i = 0; i < arrLength; i++) {
        if (checkPrime(arr[i]) == enPrimeNotPrim::Prime) {
            AddArrayElement(arr[i], arr2, arr2Length);

        }
    }
    cout << "\n";
}


int main() {
    srand((unsigned)time(NULL));

    int arr[100];
    int arrLength = 0;

    FillArrayWithRandomNumbers(arr, arrLength);
    int arr2[100];
    int arr2Length = 0;

    CopyPrimeNumbers(arr, arr2, arrLength, arr2Length);

    cout << "\nArray Elements: ";
    PrintArray(arr, arrLength);

    cout << "\nArray 2 Prime numbers : ";
    PrintArray(arr2, arr2Length);


}