#include <iostream>
using namespace std;

void printSS(string ques, string ans){
    if(ques.size() == 0){
        cout << ans << endl;
        return;
    }
    char first = ques[0];
    string rem = ques.substr(1);
    printSS(rem, ans + first);
    printSS(rem, ans + "");
}

int main(){
    string str;
    cin >> str;
    printSS(str, "");
}