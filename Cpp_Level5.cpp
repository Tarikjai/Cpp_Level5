#include <iostream>  
#include <conio.h>
using namespace std;

enum enChoices { Stone = 1, Paper = 2, Scissors = 3 };

struct StResult {
    int PlayerWin=0;
    int computerWin=0;
    int Draw=0;
  
};
string Tabs(short NumberOfTabs) {
    switch (NumberOfTabs) {
    case 1:
        return "Stone";
        break;
    case 2:
        return "Paper";
        break;
    case 3:
        return "Scissors";
        break;
    }
}

int RandomNumber(int From, int To) {
    int RandomNumber = rand() % (To - From + 1) + From;
    return RandomNumber;
}

string CheckRoundResult(int NumberOfTabs, int Computer) {
    if (NumberOfTabs == Computer) {
        return "[No Winner]";
    }
    else if (NumberOfTabs == 1 && Computer == 2 || NumberOfTabs == 2 && Computer == 3 || NumberOfTabs == 3 && Computer == 1) {
        return "[Computer win]";
    }
    else {
        return "[Player win]";
    }
}

string checkWinner(StResult& result) {
    if (result.PlayerWin > result.computerWin) {
        return "Player Win";
    }
    else if (result.PlayerWin < result.computerWin) {
        return "Computer";
    }
    else
        return "No Winner";
}

void ShowGameOverScreen(int RNumber) {
   
    cout << "\n\t\t---------------------------------------------------------";
    cout << "\n\t\t\t\t+++ G a m e    O v e r +++";
    cout << "\n\t\t_________________________________________________________\n";
    cout << "\t\t____________________ [ Game Results ] ___________________" << "\n" ;
    cout << "\t\tGame Round         : " << RNumber << "\n";
}

 

void ShowFinalGameResults(StResult& result) {
  
    cout << "\t\tPlayer 1 won times : "  << result.PlayerWin << "\n";
    cout << "\t\tComputer won times : "  << result.computerWin <<"\n";
    cout << "\t\tDraw times         : "  << result.Draw << "\n";
    cout << "\t\tFinal Winer        : " << checkWinner(result)  <<"\n";
    cout << "\n\t\t_________________________________________________________\n";
    cout << endl;
    cout << "\t\t" << "Do you want to play again? Y/N?";

   
}





short ReadHowManyRounds() {
    int RoundNuber;
    cout << "How Many Rounds 1 to 10 ? \n";
    cin >> RoundNuber;
    return RoundNuber;
}

void ResetScreen(){
}





void PlayRound(StResult& result) {
    int NumberOfTabs, Computer;
    Computer = RandomNumber(1, 3);

    cout << "\nYour Choice: [1]: Stone, [2]: Papper, [3]: Sissors ? \n";
    cin >> NumberOfTabs;
 
    cout << "\nPlayer1 Choice   : " << Tabs(NumberOfTabs) << endl;
    cout << "Computer Choice  : " << Tabs(Computer) << endl;
    cout << "Round Winner     : "<< CheckRoundResult(NumberOfTabs, Computer);

    if (CheckRoundResult(NumberOfTabs, Computer) == "[No Winner]") {
        system("color E0");
        result.Draw++;

    }
    else if (CheckRoundResult(NumberOfTabs, Computer) == "[Computer win]") {
        cout << '\a';
        system("color 4F");
        result.computerWin++; 
    }
    else if (CheckRoundResult(NumberOfTabs, Computer) == "[Player win]") {
        system("color A0");
        result.PlayerWin++;
    }

    cout << "\n______________________________________________\n";
    
}


void StartGame() {
    string PlayAgain;
    short RNumber = ReadHowManyRounds();
    int counter = 0;
    
    StResult result;
    
    bool GameOn = true;
    do {
        for (int i = 1; i <= RNumber; i++) {
            cout << "\nRound [" << ++counter << "] begins:\n";
            PlayRound(result);
        }
        GameOn =false;
    } while (GameOn == true);

    ShowGameOverScreen(RNumber);
    ShowFinalGameResults(result);

    cin >> PlayAgain;
    if (PlayAgain == "Y") {
        system("cls");
        system("color 07");
        StartGame();
    }
    cout << endl;



}




int main() {
    srand((unsigned)time(NULL));

	StartGame();
    

} 