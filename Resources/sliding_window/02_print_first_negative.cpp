#include <bits/stdc++.h>
using namespace std;

vector<int> printFirstNegative(int *arr, int n, int k){
    queue<int>q;
    vector<int>ans;

    int i = 0;
    int j = 0;

    while(j < n){
        if(arr[j] < 0){
            q.push(arr[j]);
        }

        if(j - i + 1 == k){
            if(q.empty()){
                ans.push_back(0);
            }
            else{
                int front = q.front();
                ans.push_back(front);
                if(front == arr[i]){
                    q.pop();
                }
            }
            i++;
        }
        j++;
    }
    return ans;
}

int main(){
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    vector<int> v = printFirstNegative(arr, n, k);
    for(int i : v) {
        cout<<i<<" ";
    }
    return 0;
}