// here you do not want to loose any opportunity to earn profit, so every upstroke is
// an opportunity to earn profit so participate in all of them.

// Transactions should not overlap means you have to sell one stock before buying other

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int prices[n];
    for(int i = 0; i < n; i++){
        cin >> prices[i];
    }
    
    int buying_date = 0;
    int selling_date = 0;
    int profit = 0;
    
    for(int i = 1; i < n; i++){
        if(prices[i] >= prices[i - 1]){
            selling_date++;
        }
        
        else{
            profit += prices[selling_date] - prices[buying_date];
            buying_date = selling_date = i;
        }
    }
    
    // at the last there will be no downstroke so you have to collect the last profit
    //  individually 
    
    profit += prices[selling_date] - prices[buying_date];
    cout << profit << endl;
    
    
}