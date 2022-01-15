#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int prices[n];
    for(int i = 0; i < n; i++){
        cin >> prices[i];
    }
    
    int min_so_far = prices[0];
    int* max_profit_if_sold_upto_today = new int[n];
    for(int i = 1; i < n; i++){
        if(prices[i] < min_so_far){
            min_so_far = prices[i];
        }
        
        if(prices[i] - min_so_far > max_profit_if_sold_upto_today[i - 1]){
           max_profit_if_sold_upto_today[i] = prices[i] - min_so_far; 
        }
        else{
            max_profit_if_sold_upto_today[i] = max_profit_if_sold_upto_today[i - 1];
        }
    }
    
    
    int max_after_today = prices[n - 1];
    int* max_profit_if_buy_today_or_after_today = new int[n];
    for(int i = n - 2; i >= 0; i--){
        if(prices[i] > max_after_today){
            max_after_today = prices[i];
        }
        
        if(max_after_today - prices[i] > max_profit_if_buy_today_or_after_today[i + 1]){
            max_profit_if_buy_today_or_after_today[i] = max_after_today - prices[i];
        }
        else{
            max_profit_if_buy_today_or_after_today[i] = max_profit_if_buy_today_or_after_today[i + 1];
        }
        
        int overall_profit = 0;
        for(int i = 0; i < n; i++){
            if(max_profit_if_sold_upto_today[i] + max_profit_if_buy_today_or_after_today[i] > overall_profit){
                overall_profit = max_profit_if_sold_upto_today[i] + max_profit_if_buy_today_or_after_today[i];
            }
        }
        
        cout << overall_profit << endl;
    }
}
