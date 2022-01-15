#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;
    
    int dp[str.size()];
    
    for(int i = 0; i < str.size(); i++){
        dp[i] = 0;
    }
    dp[0] = 1;
    
    for(int i = 1; i < str.size(); i++){
        if(str.at(i - 1) == '0' && str.at(i) == '0'){
            dp[i] = 0;
        }
        
        else if(str.at(i - 1) == '0' && str.at(i) != '0'){
            dp[i] = dp[i - 1];
        }
        
        else if(str.at(i - 1) != '0' && str.at(i) == '0'){
            if(str.at(i - 1) == '1' || str.at(i - 1) == '2'){
                dp[i] = (i >= 2 ? dp[i - 2] : 1);
            }
            else{
                dp[i] = 0;
            }
        }
        
        else{
            if(stoi(str.substr(i - 1, 1)) <= 26){
                dp[i] = dp[i - 1] + (i >= 2 ? dp[i - 2] : 1);
            }
            else{
                dp[i] = dp[i - 1];
            }
        }
    }
    
    cout << dp[str.size() - 1] << endl;
}