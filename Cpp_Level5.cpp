#include <iostream>
#include <string>
using namespace std;


string getPositiveNumber(string Message) {
    string input ="";
   
    cout << Message << endl;
    cin >> input;
    
    return input;
}


string EncryptText(string input, int Key) {
    for (char i = 0;i <= input.length(); i++) {

         input[i] = input[i] + Key;
    }
    return input;
}


string DecryptText(string input, int Key) {
    for (char i = 0;i <= input.length(); i++) {

        input[i] -= Key;
    }
    return input;
}



int main() {

    string input = getPositiveNumber("Insert text: ");
    string EncryptedText = EncryptText(input, 2);
    string DecryptedText = DecryptText(EncryptedText, 2);

    cout << "Text Before Encryption : " << input << endl;
    cout << "Text After Encryption : " << EncryptedText << endl;
    cout << "Text After Decryption : " << DecryptedText << endl;

}

//65   90