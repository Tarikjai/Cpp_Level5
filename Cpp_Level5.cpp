#include <iostream>
#include <string>
using namespace std;


string getPositiveNumber(string Message) {
    string input ="";
   
    cout << Message << endl;
    cin >> input;
    
    return input;
}




bool print(string input) {

    string word = "";
     
    int counter = 0;

  

   

            for (int i = 65; i <= 90; i++) {
               for (int j = 65; j <= 90 ; j++) {
                   for (int k = 65; k <= 90; k++) {
                       word = word + char(i);
                       word = word + char(j);
                       word = word + char(k);
                       counter++;
                       cout << "Trial [" << counter << "] : " << word << endl;

                       if (input == word) {
                       
                           cout << "Password is " << word  << endl;
                           cout << "Found afterl " << counter << " Trial(s)" << endl;
                           return true;
                       }

                       word = "";
                   }
          
               }
              
            }
            
            return false;

 
}


int main() {


   

    print(getPositiveNumber("input"));
}

//65   90