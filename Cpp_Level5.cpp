#include <iostream>
#include <string>
using namespace std;


string ReadPassword(string Message) {
    string Text = "";
    cout << Message << endl;
    getline(cin, Text);
    return Text;
}

 
string EncryptionFunction(string Text, short  EncryptionKey) {

    for (int i  = 0; i < Text.length(); i++ ){

        Text[i] = char(Text[i] + 65) + EncryptionKey;
    }
    return Text;
}
   
string DecryptionFunction(string Text, short  EncryptionKey) {

    for (int i = 0; i < Text.length(); i++) {

        Text[i] = char(Text[i]-65) -  EncryptionKey;
    }
    return Text;

}




int main() {
    short EncryptionKey = 5;
    string Text = ReadPassword("Please enter a text: ");

    cout << "Text Before Encryption : " << Text << endl;
    cout << "Text After Encryption : " << EncryptionFunction(Text, EncryptionKey) << endl;
    cout << "Text After Decryption : " << DecryptionFunction(EncryptionFunction(Text, EncryptionKey), EncryptionKey) << endl;
}