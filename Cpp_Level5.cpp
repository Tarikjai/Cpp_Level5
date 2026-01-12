#include <iostream>  
#include <conio.h>
#include <string>
using namespace std;
enum enGameChoice {	Stone = 1, Papper = 2, Scissors = 3};
enum enWinner { Player = 1, Computer = 2, Draw = 3 };

struct stGameResult {};
struct stRoundResult {};


stGameResult playGame() {

}





void startGame() {

	string PlayGame = "Y";
	do {
		playGame();


	} while (PlayGame == "Y" || PlayGame == "y");


}



int main() {

	startGame();
}