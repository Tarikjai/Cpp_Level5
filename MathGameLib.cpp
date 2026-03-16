#include <iostream>

using namespace std;


void clear() {
	system("cls");
	system("color 0F");
}

void PlayGame() {

}

void StartGame() {

	string Play= "Y";
	do {
		clear();
		PlayGame();
	} while (Play == "Y" || Play == "y");


}


int main() {

	srand((unsigned)time(NULL));
	StartGame();

}