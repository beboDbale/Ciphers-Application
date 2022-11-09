#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <set>

using namespace std;
map<char, string> baconianCipher = {
        {'A', "aaaaa"},
        {'B', "aaaab"},
        {'C', "aaaba"},
        {'D', "aaabb"},
        {'E', "aabaa"},
        {'F', "aabab"},
        {'G', "aabba"},
        {'H', "aabbb"},
        {'I', "abaaa"},
        {'J', "abaab"},
        {'K', "ababa"},
        {'L', "ababb"},
        {'M', "abbaa"},
        {'N', "abbab"},
        {'O', "abbba"},
        {'P', "abbbb"},
        {'Q', "baaaa"},
        {'R', "baaab"},
        {'S', "baaba"},
        {'T', "baabb"},
        {'U', "babaa"},
        {'V', "babab"},
        {'W', "babba"},
        {'X', "babbb"},
        {'Y', "bbaaa"},
        {'Z', "bbaab"}
};

map<char, string> morseCode = {{'a', ".-"},
                               {'b', "-..."},
                               {'c', "-.-."},
                               {'d', "-.."},
                               {'e', "."},
                               {'f', "..-."},
                               {'g', "--."},
                               {'h', "...."},
                               {'i', ".."},
                               {'j', ".---"},
                               {'k', "-.-"},
                               {'l', ".-.."},
                               {'m', "--"},
                               {'n', "-."},
                               {'o', "---"},
                               {'p', ".--."},
                               {'q', "--.-"},
                               {'r', ".-."},
                               {'s', "..."},
                               {'t', "-"},
                               {'u', "..-"},
                               {'v', "...-"},
                               {'w', ".--"},
                               {'x', "-..-"},
                               {'y', "-.--"},
                               {'z', "--.."},
                               {' ', " "},
                               {'0', "-----"},
                               {'1', ".----"},
                               {'2', "..---"},
                               {'3', "...--"},
                               {'4', "....-"},
                               {'5', "....."},
                               {'6', "-...."},
                               {'7', "--..."},
                               {'8', "---.."},
                               {'9', "----."}
};

char table_Cipher6[5][5] = {
        {'A', 'B', 'C', 'D', 'E'},
        {'F', 'G', 'H', 'I', 'K'},
        {'L', 'M', 'N', 'O', 'P'},
        {'Q', 'R', 'S', 'T', 'U'},
        {'V', 'W', 'X', 'Y', 'Z'}};

char arr1[] = {}, arr2[] = {}, arr3[] = {};


int input();

void Affine();

void Affine_Cipher();

void Affine_Decipher();

void Caesar();

void Caesar_Cipher_Decipher(string &text, int &key);

void Atbash();

void Atbash_Cipher_Decipher(string &text);

void Baconian();

void Baconian_Cipher(string &text);

void Baconian_Decipher(string &text);

void polybiusSquare();

void polybiusSquareCipher(string &text);

void PolybiuseSquare_Decipher(string &text);

void Morse();

void Morse_Cipher(string &text);

void Morse_Decipher(string &text);

void XOR();

void XOR_Cipher(string &text, char &key);

void XOR_Decipher(string &text, char &key);

void Railfence();

void Railfence_Cipher(string &text);

void Railfence_Decipher(string &text);

int main() {
    set<string> options = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
    cout << "WELCOME TO FCAI CIPHERS APPLICATION.\n"
            "Choose one of these Ciphers to encrypt or decrypt your message.\n"
            "0- Affine Cipher\n1- Caesar Cipher\n2- Atbash Cipher\n3- Vignere Cipher\n4- Baconian Cipher\n"
            "5- Simple Substitution Cipher\n6- Polybius Square Cipher\n7- Morse Code\n8- XOR Cipher\n9- Rail-fence Cipher\n"
            "10- Exit\n>> ";
    string cipher;
    cin >> cipher;
    while (options.count(cipher) == false) {
        cout << "Invalid input. Please select a number from 0 to 10: " << endl;
        cin.clear();
        cin.sync();
        cin >> cipher;
    }
    if (cipher == "0") {
        Affine();
    } else if (cipher == "1") {
        Caesar();
    } else if (cipher == "2") {
        Atbash();
    } else if (cipher == "3") {
        cout << 3 << endl;
    } else if (cipher == "4") {
        Baconian();
    } else if (cipher == "5") {
        cout << 5 << endl;
    } else if (cipher == "6") {
        polybiusSquare();
    } else if (cipher == "7") {
        Morse();
    } else if (cipher == "8") {
        XOR();
    } else if (cipher == "9") {
        Railfence();
    } else {
        cout << "Thanks For Using FCAI Ciphers Application" << endl;
        exit(1);
    }
}


int input() {
    cout << "What do you want to do? enter a number from 1 to 3: " << endl;
    cout << "1- Cipher a message" << endl;
    cout << "2- Decipher a message" << endl;
    cout << "3- End" << endl;
    cout << ">> ";
    int command;
    cin >> command;
    while (command != 1 && command != 2 && command != 3) {
        cout << "Invalid. Please enter a number from 1 to 3: " << endl;
        cin.clear();
        cin.sync();
        cin >> command;
    }
    return command;
}

void Affine() {
    int command = input();
    if (command == 1) {
        Affine_Cipher();
        cout << endl;
    } else if (command == 2) {
        Affine_Decipher();
        cout << endl;
    } else {
        cout << "Thanks For Using FCAI Ciphers Application" << endl;
        exit(0);
    }
}

void Affine_Cipher() {
    int a, b;
    char message[] = {};
    cout << "please enter slope a then slope b for (ax+b) eq." << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
//to calculate the equivalent of each digit and print it
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] != ' ') {
            message[i] = (message[i]) - 65;
            int x = (int) message[i];
            message[i] = ((a * x) + b) % 26;
            cout << (char) (message[i] + 65);
        } else if (message[i] == ' ')
            cout << (char) message[i];
    }
}

void Affine_Decipher() {
    int b, c;
    char message[] = {};
    cout << "please enter slope b then slope c for c(y-b) eq." << endl;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
//to calculate the equivalant of each digit and print it
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] != ' ') {
            message[i] = (message[i]) - 65;
            int y = (int) message[i];
            message[i] = ((c * (y - b) % 26 + 26) % 26) + 97;
            cout << message[i];
        } else if (message[i] = ' ') {
            cout << (char) message[i];
        }
    }
}

void Caesar() {
    int command = input();
    string message;
    int shift;
    if (command == 1) {
        cout << "Enter the number of shifts he wants to the right or left (+ve or –ve): " << endl;
        cin >> shift;
        cout << "Enter message you want to encrypt: " << endl;
        cin.clear();
        cin.sync();
        getline(cin, message);
        Caesar_Cipher_Decipher(message, shift);
    } else if (command == 2) {
        cout << "Enter the number of shifts he wants to the right or left (+ve or –ve): " << endl;
        cin >> shift;
        cout << "Enter message you want to decrypt: " << endl;
        cin.clear();
        cin.sync();
        getline(cin, message);
        shift = shift * -1;
        Caesar_Cipher_Decipher(message, shift);
    } else {
        cout << "Thanks For Using FCAI Ciphers Application" << endl;
        exit(0);
    }
}

void Caesar_Cipher_Decipher(string &text, int &key) {
    for (int i = 0; i < text.size(); i++) {
        text[i] = toupper(text[i]);
        if (text[i] == ' ' || !isalpha(text[i])) { continue; }
        if (key >= 0) {
            key %= 26;
            text[i] = text[i] + key;
            if (text[i] > 90) {
                text[i] = text[i] - 26;
            }
        } else if (key < 0) {
            key %= 26;
            key += 26;
            text[i] = text[i] + key;
            if (text[i] > 90) {
                text[i] = text[i] - 26;
            }
        }
    }
    cout << text;
}

void Atbash() {
    string message;
    int command = input();
    if (command == 1 || command == 2) {
        if (command == 1) {
            cout << "Please enter the message to encrypt: " << endl;
            cin.clear();
            cin.sync();
            getline(cin, message);
            Atbash_Cipher_Decipher(message);
        } else {
            cout << "Please enter the message to decrypt: " << endl;
            cin.clear();
            cin.sync();
            getline(cin, message);
            Atbash_Cipher_Decipher(message);
        }
    } else {
        cout << "Thanks For Using FCAI Ciphers Application" << endl;
        exit(0);
    }
}

void Atbash_Cipher_Decipher(string &text) {
    int uppercase_characters[26] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74,
                                    75, 76, 77, 78, 79, 80, 81, 82, 83,
                                    84, 85, 86, 87, 88, 89, 90
    };
    int lowercase_characters[26] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106,
                                    107,108, 109, 110, 111, 112, 113, 114, 115,
                                    116, 117, 118, 119, 120, 121, 122
    };
    int charCode;
    for (int i = 0; i < text.size(); i++) {
        charCode = int(text[i]);
        for (int j = 0; j < 26; j++) {
            if (charCode == uppercase_characters[j]) {
                text[i] = char(uppercase_characters[25 - j]);
            } else if (charCode == lowercase_characters[j]) {
                text[i] = char(lowercase_characters[25 - j]);
            }
        }
    }
    cout << text << endl;
}

void Baconian() {
    int command = input();
    string message;
    if (command == 1) {
        cout << "Please enter the message to encrypt: " << endl;
        cin.clear();
        cin.sync();
        getline(cin, message);
        Baconian_Cipher(message);
    } else if (command == 2) {
        cout << "Please enter the message to decrypt: " << endl;
        cin.clear();
        cin.sync();
        getline(cin, message);
        Baconian_Decipher(message);
    } else {
        cout << "Thanks For Using FCAI Ciphers Application" << endl;
        exit(0);
    }
}

void Baconian_Cipher(string &text) {
    string cipher = "";
    for (int i = 0; i < text.size(); i++) {
        text[i] = toupper(text[i]);
        if (!isalpha(text[i])) {
            cipher += text[i];
        } else { cipher += baconianCipher[text[i]]; }
    }
    cout << cipher << endl;
}

void Baconian_Decipher(string &text) {
    string decipher = "";
    string part;
    int i = 0;
    while (true) {
        if (i < text.size() - 4) {
            part = text.substr(i, 5);
            if (part[0] != ' ') {
                for (char letter = 65; letter <= 90; letter++) {
                    if (baconianCipher[letter] == part) {
                        decipher += letter;
                        i += 5;
                    }
                }
            } else {
                decipher += ' ';
                i += 1;
            }
        } else break;
    }
    cout << decipher << endl;
}

void polybiusSquare() {
    int command = input();
    string message;
    if (command == 1) {
        cout << "Please enter the message to encrypt: " << endl;
        cin.clear();
        cin.sync();
        getline(cin, message);
        //  convert message to upper case
        transform(message.begin(), message.end(), message.begin(), ::toupper);
        polybiusSquareCipher(message);
    } else if (command == 2) {
        cout << "Please enter the message to decrypt: " << endl;
        cin.clear();
        cin.sync();
        getline(cin, message);
        PolybiuseSquare_Decipher(message);
    } else {
        cout << "Thanks For Using FCAI Ciphers Application" << endl;
        exit(0);
    }
}

void polybiusSquareCipher(string &text) {
    string cipher;
    for (int k = 0; k < text.size(); k++) {
        //to add spaces
        if (text[k] == ' ') { cipher += " "; }
        //first loop for rows and second for columns
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (text[k] == table_Cipher6[i][j]) {
                    //add the letters to the cipher message
                    cipher += to_string(i + 1) + to_string(j + 1);
                }

            }
        }
    }
}

void PolybiuseSquare_Decipher(string &text) {
    string decipher;
    for (int k = 0; k < text.size(); k++) {
        //to add spaces
        if (text[k] == ' ') { decipher += " "; }
        else {
            //to add the letters in the table
            int x = text[k] - '0';
            int y = (text[k + 1] - '0');
            decipher.push_back(table_Cipher6[x - 1][y - 1]);
            k++;
        }
    }
    //  convert message to lower case
    transform(text.begin(), text.end(), text.begin(), ::toupper);
}

void Morse() {
    int command = input();
    string message;
    if (command == 1) {
        cout << "Please enter the message to encrypt: " << endl;
        cin.clear();
        cin.sync();
        getline(cin, message);
        transform(message.begin(), message.end(), message.begin(), ::tolower);
        // convert message to small letters
        Morse_Cipher(message);
    } else if (command == 2) {
        cout << "Please enter the message to decrypt: " << endl;
        cin.clear();
        cin.sync();
        getline(cin, message);
        Morse_Decipher(message);
    } else {
        cout << "Thanks For Using FCAI Ciphers Application" << endl;
        exit(0);
    }
}

void Morse_Cipher(string &text) {
    // to loop through all letters ( if i won't change in it)
    for (char letter: text) {
        cout << morseCode[letter] << " ";
    }
}

void Morse_Decipher(string &text) {
    string token;
    istringstream scin("");
    scin.str(text);
    scin >> token;
    while (scin) {
        for (char letter = 97; letter <= 122; letter++) {
            if (morseCode[letter] == token) {
                cout << letter;
            }
        }
        scin >> token;
    }
    cout << endl;
}

void XOR() {
    int command = input();
    string message;
    char secret_key;
    if (command == 1) {
        cout << "Enter the secret key: " << endl;
        cin >> secret_key;
        cout << "Enter message you want to encrypt: " << endl;
        cin.clear();
        cin.sync();
        getline(cin, message);
        secret_key = tolower(secret_key);
        transform(message.begin(), message.end(), message.begin(),
                  ::toupper); // convert string into uppercase letters
        XOR_Cipher(message, secret_key);
    } else if (command == 2) {
        cout << "Enter the secret key: " << endl;
        cin >> secret_key;
        cout << "Enter message you want to decrypt: " << endl;
        cin.clear();
        cin.sync();
        getline(cin, message);
        secret_key = tolower(secret_key);
        XOR_Decipher(message, secret_key);
    } else {
        cout << "Thanks For Using FCAI Ciphers Application" << endl;
        exit(0);
    }
}

void XOR_Cipher(string &text, char &key) {
    for (int i = 0; i < text.size(); i++) {
        text[i] = text[i] ^ key;
        cout << text[i];
    }
    cout << "      ( hexadecimal ";
    for (int i = 0; i < text.size(); i++) {
        cout << hex << (int) text[i];
    }
    cout << " )" << endl;
}

void XOR_Decipher(string &text, char &key) {
    string hexa_extract, hexa_decipher;
    for (int i = 0; i < text.size(); i += 2) {
        hexa_extract = text.substr(i, 2);
        hexa_decipher += (char) stoi(hexa_extract, nullptr, 16);
    }
    for (int i = 0; i < hexa_decipher.size(); i++) {
        hexa_decipher[i] = hexa_decipher[i] ^ key;
        cout << hexa_decipher[i];
    }
}

void Railfence() {
    int command = input();
    string message, encrypted_message;
    int key = 3, length;
    if (command == 1) {
        cout << "enter the message please without spaces" << endl;
        cin.clear();
        cin.sync();
        getline(cin, message);
        // to remove spaces in message
        auto Nospace = remove(message.begin(), message.end(), ' ');
        message.erase(Nospace, message.end());
        //cout<< message <<endl;
        for (int i = 0; i < message.length(); i++) {
            message[i] = tolower(message[i]);
        }
        Railfence_Cipher(message);
    } else if (command == 2) {
        cout << "enter the message please without spaces" << endl;
        cin.clear();
        cin.sync();
        getline(cin, message);
        // to remove spaces in message
        auto Nospace = remove(message.begin(), message.end(), ' ');
        message.erase(Nospace, message.end());
        //cout<< message <<endl;
        for (int i = 0; i < message.length(); i++) {
            message[i] = tolower(message[i]);
        }
        Railfence_Decipher(message);
    } else {
        cout << "Thanks For Using FCAI Ciphers Application" << endl;
        exit(0);
    }
}

void Railfence_Cipher(string &text) {
    for (int i = 0; i < text.length(); i++) {
        if (i % 4 == 0 || i == 0) {
            arr1[i] = text[i];
        } else if (i % 4 != 0) {
            arr1[i] = '.';
        }
        if (arr1[i] != '.') {
            cout << arr1[i];
        }
    }
    for (int i = 0; i < text.length(); i++) {
        if (i % 2 == 0) {
            arr2[i] = '.';
        } else if (i % 2 != 0) {
            arr2[i] = text[i];
        }
        if (arr2[i] != '.') {
            cout << arr2[i];
        }
    }
    for (int i = 0; i < text.length(); i++) {
        if ((i - 2) % 4 == 0) {
            arr3[i] = text[i];
        } else if ((i - 2) % 4 != 0) {
            arr3[i] = '.';
        }
        if (arr3[i] != '.') {
            cout << arr3[i];
        }
    }
}

void Railfence_Decipher(string &text) {
    //to create a 2d vector
    vector<vector<char>> mytable(3, vector<char>(text.size()));
    int j = 0;
    int check = 0;
    for (int i = 0; i < text.length(); i++) {
        //set the cell equal null charcter
        mytable[j][i] = '0';
        //if row = key -1
        if (j == 2) {
            //the condition is satisfied
            check = 1;
        } else if (j == 0)
            check = 0;
        if (check == 0) {
            //go to the next row
            j++;
        }
            //gp to previous row
        else j--;
    }
    //  i is for rows and j is for columns
    int temp = 0;
    // if rows < key
    for (int i = 0; i < 3; i++) {
        //if coulumns < the length of the message
        for (j = 0; j < text.size(); j++) {
            // if specific cell in the vector is equal null character
            if (mytable[i][j] == '0')
                mytable[i][j] = text[temp++];
        }
    }
    check = 0;
    j = 0;
    for (int i = 0; i < text.size(); i++) {
        cout << mytable[j][i];
        if (j == 2) {
            check = 1;
        } else if (j == 0)
            check = 0;
        if (check == 0) {
            j++;
        } else j--;
    }
    cout << '\n';
}
