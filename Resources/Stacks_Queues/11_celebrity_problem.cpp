#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int arr[n][n];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    
    stack<int> st;
    
    // putting all the candidates in the stack
    for(int i = 0; i < n; i++){
        st.push(i);
    }
    
    // jb tk stack me min 2 log hn tb tk dekhte rho ki kon kisko janta h or kon nhi
    while(st.size() >= 2){
        int i = st.top();
        st.pop();
        int j = st.top();
        st.pop();
        
        // if i knows j means i is not celebrity
        if(arr[i][j] == 1){
            st.push(j);
        }
        // if i doesn't know means j means j is not a celebrity
        else{
            st.push(i);
        }
    }
    
    int potential = st.top();
    st.pop();
    bool flag = true;
    
    for(int i = 0; i < n; i++){
        if(i != potential){
            // checking rows and columns of potential person expect his own cell
            
            if(arr[i][potential] == 0 || arr[potential][i] == 1){
                
                // agar ith bnda nhi jaanta potential ko ya fir potential jaanta h ith ko 
                // mtlb potential is not celebrity
                flag = false;
                break;
            }
        }
    }
    
    if(flag){
        cout << potential << endl;
    }
    else{
        cout << "none" << endl;
    }
}