#include <iostream>  
using namespace std;

enum enChoices { Stone = 1, Paper = 2, Scissors = 3 };


int RandomNumber(int From, int To) {
    int RandomNumber = rand() % (To - From + 1) + From;
    return RandomNumber;
}

void ShowGameOverScreen(int RNumber) {
    string restart;
    cout << "\n\t\t---------------------------------------------------------";
    cout << "\n\t\t\t\t+++ G a m e    O v e r +++";
    cout << "\n\t\t_________________________________________________________\n";
    
}

 
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


void ShowFinalGameResults(int& playerWin, int& computerWin, int& Draw) {
    cout << "\t\t____________________ [ Game Results ] ___________________"  << "\n" << endl;
    cout << "\t\tGame Round         : " << Draw << "\n";
    cout << "\t\tPlayer 1 won times : "  << Draw << "\n";
    cout << "\t\tComputer won times : "  << computerWin <<"\n";
    cout << "\t\tDraw times         : "  << Draw << "\n";
    cout << "\t\tFinal Winer        : " << "\n";
    cout << "\n\t\t_________________________________________________________\n";
    cout << endl;
    cout << "\t\t" << "Do you want to play again? Y/N?";
    cout << endl;

}

short ReadHowManyRounds() {
    int RoundNuber;
    cout << "How Many Rounds 1 to 10 ? \n";
    cin >> RoundNuber;
    return RoundNuber;
}

void ResetScreen(){
}

string CheckRoundResult(int NumberOfTabs, int Computer) {
    if (NumberOfTabs == Computer) {
      return "[No Winner]";
      //  system("color E0");
    }
    else if (NumberOfTabs == 1 && Computer == 2 || NumberOfTabs == 2 && Computer == 3 || NumberOfTabs == 3 && Computer == 1) {
        return "[Computer win]";
    //    system("color 4F");
    }    
    else {
    //    system("color A0");
        return "[Player win]";
    }
}

void PlayRound(int& playerWin, int& computerWin, int& Draw) {
    int NumberOfTabs, Computer;
     
    cout << "\nYour Choice: [1]: Stone, [2]: Papper, [3]: Sissors ? \n";
    cin >> NumberOfTabs;


    Computer = RandomNumber(1, 3);
    
    cout << "\nPlayer1 Choice   : " << Tabs(NumberOfTabs) << endl;
    cout << "Computer Choice  : " << Tabs(Computer) << endl;
    cout << "Round Winner     : "<< CheckRoundResult(NumberOfTabs, Computer);

    if (CheckRoundResult(NumberOfTabs, Computer) == "[No Winner]") {
        system("color E0");
        Draw++;

    }
    else if (CheckRoundResult(NumberOfTabs, Computer) == "[Computer win]") {
        system("color 4F");
        computerWin++; 
    }
    else if (CheckRoundResult(NumberOfTabs, Computer) == "[Player win]") {
        system("color A0");
        playerWin++;
    }

    cout << "\n______________________________________________\n";
    
}


void StartGame() {
    bool GameOn = true;

    short RNumber = ReadHowManyRounds();
    int counter = 0 , playerWin = 0, computerWin = 0, Draw = 0;
    

    do {
      
        
        
        for (int i = 0; i < RNumber; i++) {
            cout << "\nRound [" << ++counter << "] begins:\n";
            PlayRound( playerWin,  computerWin, Draw);
            
            
        }
        
        
        GameOn =false;

    } while (GameOn == true);

    
  
    ShowGameOverScreen(RNumber);
    cout << endl;
    ShowFinalGameResults(playerWin, computerWin, Draw);
}




int main() {
    srand((unsigned)time(NULL));

	StartGame();
    

} 