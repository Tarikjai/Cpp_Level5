#include <iostream>
#include <string>
using namespace std;


string getPositiveNumber(string Message) {
    string input = "";
    cout << Message << endl;
    cin >> input;
    return input;
}

 

void printInvertedPattern(string input) {
    int counter = 0;
    string word = "";
    cout << endl;

    cout << "Output: " << endl;

  

        for (int i = 65; i <= 90; i++) {
            for (int j = 65; j <= 90; j++) {
                for (int k = 65; k <= 90; k++) {

                    word = word + char(i);
                    word = word + char(j);
                    word = word + char(k);

                    counter++;

                    /*if (word != input) {
                        cout << "Trial [" << counter << "] : " << word << endl;
                        word = "";
                    }*/

                    if (word == input) {
                        cout << "Trial [" << counter << "] : " << word << endl;
                        cout << "Password is " << word << endl;
                        cout << "Found after " << counter << " Trial(s)" << endl;
                        cout << endl;
                    }
                }
                
            }
        }
        /*if (word == input) {
            cout << "Trial [" << counter << "] : " << word << endl;
            cout << "Password is " << word << endl;
            cout << "Found after " << counter << " Trial(s)" << endl;
            cout << endl;
        }*/
}
   
        




 
 


int main() {
    
    printInvertedPattern(getPositiveNumber("Please enter a password: "));
}
