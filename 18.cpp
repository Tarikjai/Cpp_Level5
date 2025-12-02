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

    for (int i = 0; i < Text.length(); i++) {

        Text[i] = char(Text[i] + EncryptionKey);
    }
    return Text;
}

string DecryptionFunction(string Text, short  EncryptionKey) {

    for (int i = 0; i < Text.length(); i++) {

        Text[i] = char(Text[i] - EncryptionKey);
    }
    return Text;

}




int main() {
    short EncryptionKey = 2;
    string Text = ReadPassword("Please enter a text: ");
    string TextAfterEncryption = EncryptionFunction(Text, EncryptionKey);
    string TextAfterDecryption = DecryptionFunction(TextAfterEncryption, EncryptionKey);

    cout << "Text Before Encryption : " << Text << endl;
    cout << "Text After Encryption : " << TextAfterEncryption << endl;
    cout << "Text After Decryption : " << TextAfterDecryption << endl;
}