#include <iostream>  
using namespace std;

enum enChoices { Stone = 1, Paper = 2, Scissors = 3 };


struct stGameResults { 
    int GameRounds =0 ;
    int Player1wontimes = 0;
    int ComputerWontimes = 0;
    int DrawTimes = 0;
};

struct stChoices {
    int PlayerChoice;
    int ComputerChoice ;
    string RoundWinner;
   };



int RandomNumber(int From, int To) {
    int RandomNumber = rand() % (To - From + 1) + From;
    return RandomNumber;
}

void ShowGameOverScreen() {
    string restart;
    cout << "-------------------------------------------------------\n";
    cout << "\n\t\t+++ G a m e    O v e r +++\n";
    cout << "\n-------------------------------------------------------\n";
   
    cout << "\n-------------------------------------------------------\n";
    cout << "Do you want to play again? Y/N?";
   

    
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


void ShowFinalGameResults(stGameResults GameResults) {


    cout << "\nGame Rounds      : "  << GameResults.GameRounds <<  "\n";
    cout << "Player 1 won times : "  << GameResults.Player1wontimes << "\n";
    cout << "Computer won times : "  << GameResults.ComputerWontimes <<"\n";
    cout << "Draw times         : "  << GameResults.DrawTimes << "\n";
    cout << "Final Winer        :  " << "\n";


}

short ReadHowManyRounds() {
    int RoundNuber;
    cout << "How Many Rounds 1 to 10 ? \n";
    cin >> RoundNuber;
    return RoundNuber;
}

void ResetScreen(){
}

void CheckRoundResult(int NumberOfTabs, int Computer) {
    if (NumberOfTabs == Computer) {
        cout << "Round Winner     : [No Winner]";
        system("color E0");
    }
    else if (NumberOfTabs == 1 && Computer == 2 || NumberOfTabs == 2 && Computer == 3 || NumberOfTabs == 3 && Computer == 1) {
        cout << "Round Winner     : [Computer win]";
        system("color 4F");
    }    
    else {
        system("color A0");
        cout << "Round Winner     : [Player win]";
    }
}

void PlayRound() {
    int NumberOfTabs, Computer;
    

    cout << "\nYour Choice: [1]: Stone, [2]: Papper, [3]: Sissors ? \n";
    cin >> NumberOfTabs;
    Computer = RandomNumber(1, 3);
    
    cout << "\nPlayer1 Choice   : " << Tabs(NumberOfTabs) << endl;
    cout << "Computer Choice  : " << Tabs(Computer) << endl;
     CheckRoundResult(NumberOfTabs, Computer)  ;
    cout << "\n______________________________________________\n";
    
}


void StartGame() {
    bool GameOn = true;

    short RNumber = ReadHowManyRounds();
    int counter = 0;
    

    do {
      
        
        
        for (int i = 0; i < RNumber; i++) {
            cout << "\nRound [" << ++counter << "] begins:\n";
            PlayRound();

            
        }
        

        GameOn =false;

    } while (GameOn == true);

    
  
    ShowGameOverScreen();
       

}




int main() {
    srand((unsigned)time(NULL));

	StartGame();
    

} 