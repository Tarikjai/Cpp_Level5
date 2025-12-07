#include <iostream>
#include <string>
using namespace std;

#include <cstdlib>  // pour rand() et srand()
#include <ctime>    // pour time()


int RandomNumber(int From, int To) {

	int RandomNumber = rand() % (To - From + 1) + From;                // génère un entier pseudo-aléatoire
	return RandomNumber;
}



int main() {


	srand((unsigned)time(NULL));

	cout << RandomNumber(55, 85) << endl;

}