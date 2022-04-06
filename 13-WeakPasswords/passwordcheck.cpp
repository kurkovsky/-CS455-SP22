#include <cctype>
#include <iostream>
#include <string>
using namespace std;

void checkPassword(string &input) {
    bool capfirst = false;
    bool minlen12 = false;
    bool hasspecial = false;
    bool hasnumber = false;
    bool maxlen32 = false;
    bool haslower = false;
    bool hasillegal = false;
    //bool hasupper = false;
    string specialChars = "~!@#$%^&*()_+";
    int pwdLength = input.length();

    if(pwdLength >= 12) minlen12 = true; 
    //minlen12 = (pwdLength >= 12);
    if(pwdLength <= 32) maxlen32 = true;
    if(isupper(input[0])) capfirst = true;

    for(int i=0; i<pwdLength; i++) {
        if(specialChars.find_first_of(input[i]) != string::npos) hasspecial = true;
        else if(!isalnum(input[i])) hasillegal = true;

        if(islower(input[i])) haslower = true;
        if(isdigit(input[i])) hasnumber = true; 
        //if(isupper(input[i])) hasu   
    }

    cout << "Your password " << input ;
    if(minlen12) cout << " has at least 12 character;";
    if(maxlen32) cout << " has under 32 characters;";
    if(capfirst) cout << " has first uppercase char;";
    if(hasspecial) cout << " has special chars;";
    if(haslower) cout << " has lowercase chars;";
    if(hasnumber) cout << " has numbers;";
    if(hasillegal) cout << " has illegal chars;"; 
    cout << endl;
}

int main(){
    string password;
    cout << "Please enter a password: ";
    cin >> password;
    checkPassword(password);
    return 0;
}