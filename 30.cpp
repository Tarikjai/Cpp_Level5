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



int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{


    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++) {
        cout << arr[i] << " ";
    }
}

void sumArrays(int arr[100], int arr2[100], int arrLength, int SumArr[100]) {
    for (int i = 0; i < arrLength; i++) {
        SumArr[i] = arr[i] + arr2[i];
        cout << SumArr[i] << " ";
    }

}



int main() {
    srand((unsigned)time(NULL));

    int arr[100];
    int arr2[100];
    int SumArr[100];

    int arrLength = getPositiveNumber(" ");

    FillArrayWithRandomNumbers(arr, arrLength);
    FillArrayWithRandomNumbers(arr2, arrLength);

    //CopyOnlyPrimeNumbers(arr, arr2, arrLength, arr2Length);


    cout << "\nArray 1 Elements: ";
    PrintArray(arr, arrLength);
    cout << "\nArray 2 Elements: ";
    PrintArray(arr2, arrLength);
    cout << "  " << endl;

    cout << "\nSum of array1 and array2 elements: ";
    cout << "  " << endl;
    sumArrays(arr, arr2, arrLength, SumArr);
    return 0;
}