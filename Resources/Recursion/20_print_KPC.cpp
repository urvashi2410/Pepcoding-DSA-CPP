#include <iostream>
using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printKPC(string ques, string asf){
    if(ques.size() == 0){
        cout << asf << endl;
        return;
    }
    char first = ques[0];
    string rem = ques.substr(1);
    string possibleCodes = codes[first - '0'];
    for(int i = 0; i < possibleCodes.size(); i++){
        printKPC(rem, asf + possibleCodes[i]);
    }
}

int main(){
    string str;
    cin >> str;
    printKPC(str, "");
}