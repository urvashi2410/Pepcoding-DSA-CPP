#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int prices[n];
    
    for(int i = 0; i < n; i++){
        cin >> prices[i];
    }
    
    int min_so_far = INT_MAX;
    int overall_profit = 0;
    int profit_if_sold_today = 0;
    
    for(int i = 0; i < n; i++){
        if(prices[i] < min_so_far){
            min_so_far = prices[i];
        }
        
        profit_if_sold_today = prices[i] - min_so_far;
        
        if(profit_if_sold_today > overall_profit){
            overall_profit = profit_if_sold_today;
        }
    }
    
    cout << overall_profit << endl;
}