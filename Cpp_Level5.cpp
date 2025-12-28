#include <iostream>   
using namespace std;

void Fillarray(int arrSource[10], int& SourceLength) {
    SourceLength = 10;
    arrSource[0] = 10;
    arrSource[1] = 10;
    arrSource[2] = 10;
    arrSource[3] = 50;
    arrSource[4] = 50;
    arrSource[5] = 70;
    arrSource[6] = 70;
    arrSource[7] = 70;
    arrSource[8] = 70;
    arrSource[9] = 90;
}

void PrintArray(int arr[100], int arrLength){
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

short FindNumberPositionInArray(int Number, int arrSource[100], int& SourceLength) {
    for (int i = 0; i < SourceLength; i++) {
        if (arrSource[i] == Number)
            return i;
    }
    return -1;
}

void AddArrayElement(int Number, int arrSource[100], int& SourceLength)
{
    SourceLength++;
    arrSource[SourceLength - 1] = Number;
}

bool checkPresence(int Number, int arrSource[100], int& SourceLength) {
    return FindNumberPositionInArray(Number, arrSource, SourceLength) != -1;
}
 
void CopyDistinctNumbersToArray(int arrSource[100], int& SourceLength,
    int arrDestination[100], int& DestinationLength) {

    for (int i = 0; i < SourceLength; i++) {
        if (!checkPresence(arrSource[i], arrDestination, DestinationLength)) {
            AddArrayElement(arrSource[i], arrDestination, DestinationLength);
        }
    }
}

    

int main() {
    srand((unsigned)time(NULL));

    int arrSource[100];
    int SourceLength = 0;

    Fillarray(arrSource, SourceLength);

    int arrDestination[100];
    int DestinationLength = 0;

    CopyDistinctNumbersToArray(arrSource, SourceLength, arrDestination, DestinationLength);

    cout << "\nArray 1 Elements: ";
    PrintArray(arrSource, SourceLength);

    cout << "\nArray 2 Distinct Elements : ";
    PrintArray(arrDestination, DestinationLength);


}