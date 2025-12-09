#include <iostream>
#include <string>
using namespace std;

#include <cstdlib>  // pour rand() et srand()
#include <ctime>    // pour time()

int ReadPositiveNumber(string Message) {
	int input;
	do {
		cout << Message;
		cin >> input ;
	} while (input <= 0);
	return input;
}


int FrequencyCheck(int number, int digit) {

    int reminder = 0;
    int FrequencyCounter = 0;

    while (number > 0) {


        reminder = number % 10;
        number = number / 10;

        if (reminder == digit) {
            FrequencyCounter++;
        }
    }
    return  FrequencyCounter;
}


int main() {

	srand((unsigned)time(NULL));
	 

	PrintKeys(ReadPositiveNumber("How Much keys you want to generate? ")) ;

}                                                                  