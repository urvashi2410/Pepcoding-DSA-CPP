#include<bits/stdc++.h>
using namespace std;

int power(int a, int b){
    if(b == 0){
        return 1;
    }

    else if(b == 1){
        return a;
    }

    return a*power(a, b-1);
}

int power1(int a, int b){
    if(b == 0){
        return 1;
    }

    int smallAns = power1(a, b/2);
    int ans = smallAns*smallAns;
    if(b & 1){
        return ans*a;
    }
    return ans;
}

int main(){
    int a;
    cin >> a;
    int b;
    cin >> b;

    cout << power1(a, b);
}