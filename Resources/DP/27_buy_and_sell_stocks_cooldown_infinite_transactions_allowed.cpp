// overlapping is not allowed means sell krna pdega agla buy krne se pehle.

// cool down mtlb ek sell krne k baad ek din ka break lena pdega agle din nhi buy kr skte 

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int prices[n];
    for(int i = 0; i < n; i++){
        cin >> prices[i];
    }
    
    int old_buy_state_profit = -prices[0];
    int old_sold_state_profit = 0;
    int old_cool_state_profit = 0;
    
    for(int i = 1; i < n; i++){
        int new_buy_state_profit = 0;
        int new_sold_state_profit = 0;
        int new_cool_state_profit = 0;
        
        // ya to purane cool pr buy krlo ya fir pehla buy rkhlo jo max ho vo rkhlo
        if(old_cool_state_profit - prices[i] > old_buy_state_profit){
            new_buy_state_profit = old_cool_state_profit - prices[i];
        }
        else{
            new_buy_state_profit = old_buy_state_profit;
        }
        
        // purani sold state rkhlo ya aaj sold krke rkhlo jo max ho vo rkhlo
        
        if(old_buy_state_profit + prices[i] > old_sold_state_profit){
            new_sold_state_profit = old_buy_state_profit + prices[i];
        }
        else{
            new_sold_state_profit = old_sold_state_profit;
        }
        
        // last sold state profit or cool state me se max lelo
        
        if(old_sold_state_profit > old_cool_state_profit){
            new_cool_state_profit = old_sold_state_profit;
        }
        else{
            new_cool_state_profit = old_cool_state_profit;
        }
        
        old_buy_state_profit = new_buy_state_profit;
        old_sold_state_profit = new_sold_state_profit;
        old_cool_state_profit = new_cool_state_profit;
    }
    
    cout << old_sold_state_profit << endl;
}