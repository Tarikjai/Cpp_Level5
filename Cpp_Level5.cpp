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

int SumArray(int arr[100], int arrLength)
{
    int Sum = 0;  // Initialize sum to zero.

    // Loop through each element of the array and add it to Sum.
    for (int i = 0; i < arrLength; i++)
    {
        Sum += arr[i];
    }

    return Sum;  // Return the calculated sum.
}


float AverageArray(int arr[100], int arrLength)
{

   

    return SumArray(arr, arrLength) / float(arrLength);

}


int main() {

    srand((unsigned)time(NULL));

    int arr[100];
    int arrLength;


    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\nArray Elements: ";
    PrintArray(arr, arrLength);


    cout << "\nAverage of all number is : ";
    cout << AverageArray(arr, arrLength) << endl;

    return 0;  // Return 0 to indicate successful program execution.
}