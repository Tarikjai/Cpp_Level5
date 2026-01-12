#include <iostream>  
#include <conio.h>
#include <string>
using namespace std;
enum enGameChoice {	Stone = 1, Papper = 2, Scissors = 3};
enum enWinner { Player = 1, Computer = 2, Draw = 3 };

struct stGameResult {};
struct stRoundResult {};

string Tab(short Numbert) {
	string t = "\t";
	for (int i = 0; i < Numbert; i++) {
		t = t + "\t";
	}
	return t;
}

stGameResult playGame() {



}





void startGame(stGameResult GameResutl) {

	string PlayGame = "Y";
	do {
		playGame();


		cout << Tab(2) << "Do You want to play again Y/N?";
		cin >> PlayGame;

	} while (PlayGame == "Y" || PlayGame == "y");


}



int main() {

	startGame();
}