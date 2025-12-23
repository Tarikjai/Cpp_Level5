#include <iostream>   
using namespace std;

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

void PrintArray(int arr[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void copyArray(int arr[100], int arr2[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++) {
        arr2[i] = arr[i];
        // cout << arr2[i] << " ";
    }

    cout << "\n";

}




int main() {

    srand((unsigned)time(NULL));

    int arr[100];

    int arrLength;


    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\nArray Elements: ";
    PrintArray(arr, arrLength);

    int arr2[100];
    copyArray(arr, arr2, arrLength);

    cout << "\nArray 2 elements after copy : ";


    PrintArray(arr2, arrLength);
    return 0;  // Return 0 to indicate successful program execution.
}