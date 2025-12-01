#include <iostream>
#include <string>
using namespace std;


string ReadPassword(string Message) {
    string input = "";
    cout << Message << endl;
    cin >> input;
    return input;
}



bool GuessPassword(string input) {
    int counter = 0;
    string word = "";
    cout << endl;

    cout << "Output: " << endl;



    for (int i = 65; i <= 90; i++) {
        for (int j = 65; j <= 90; j++) {
            for (int k = 65; k <= 90; k++) {

                counter++;

                word = word + char(i);
                word = word + char(j);
                word = word + char(k);



                cout << "Trial [" << counter << "] : " << word << endl;




                if (word == input) {
                    cout << endl;
                    cout << "Password is " << word << endl;
                    cout << "Found after " << counter << " Trial(s)" << endl;
                    cout << endl;
                    return true;
                }
                word = "";
            }
        }

    }
    return false;

}




int main() {

    GuessPassword(ReadPassword("Please enter a 3-Letter password (all capital): "));
}
