// bought state mtlb you are having one extra share and sold state mtlb you have closed 
// all the shares. So hum bdiya bought state or bdiya sold state me rehne ki baat kr rhe hn .
// new buy state purane sold state pr bnti h
// new khareedne se pehle purana bechna pdega opr bechne ki fees lgegi "fees" k equal

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int prices[n];
    for(int i = 0; i < n; i++){
        cin >> prices[i];
    }
    
    int fee;
    cin >> fee;
    
    int old_buy_state_profit = -prices[0];
    int old_sold_state_profit = 0;
    
    for(int i = 0; i < n; i++){
        int new_buy_state_profit = 0;
        int new_sold_state_profit = 0;
        
        // agar after selling ab buy krne pr km ka loan h to abhi buy krlo otherwise
        // pehle wali hi buy state shi h
        if(old_sold_state_profit - prices[i] > old_buy_state_profit){
            new_buy_state_profit = old_sold_state_profit - prices[i];
        }
        else{
            new_buy_state_profit =  old_buy_state_profit;
        }
        
        if(old_buy_state_profit + prices[i] - fee > old_sold_state_profit){
            new_sold_state_profit = old_buy_state_profit + prices[i] - fee;
        }
        else{
            new_sold_state_profit = old_sold_state_profit;
        }
        
        old_buy_state_profit = new_buy_state_profit;
        old_sold_state_profit = new_sold_state_profit;
    }
    
    cout << old_sold_state_profit << endl;
}