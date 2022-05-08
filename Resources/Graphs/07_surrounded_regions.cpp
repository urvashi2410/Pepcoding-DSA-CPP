class Solution {
public:
    void convert(vector<vector<char>>&board){
        int n = board.size();
        int m = board[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'B'){
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
    
    bool isvalid(vector<vector<char>>&board, int n, int m, int i, int j){
        if(i >= 0 && i < n && j >= 0 && j < m && board[i][j] == 'O'){
            return true;
        }
        return false;
    }
    
    void dfs(vector<vector<char>>&board, int n, int m, int i, int j){
        board[i][j] = 'B';
        if(isvalid(board, n, m, i+1, j)){
            dfs(board, n, m, i+1, j);
        }
        
        if(isvalid(board, n, m, i-1, j)){
            dfs(board, n, m, i-1, j);
        }
        
        if(isvalid(board, n, m, i, j+1)){
            dfs(board, n, m, i, j+1);
        }
        
        if(isvalid(board, n, m, i, j-1)){
            dfs(board, n, m, i, j-1);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int i, j;
        
        for(int i = 0; i < n; i++){
            j = 0;
            if(board[i][j] == 'O'){
                dfs(board, n, m, i, j);
            }
            j = m-1;
            if(board[i][j] == 'O'){
                dfs(board, n, m, i, j);
            }
        }
        
        for(int j = 0; j < m; j++){
            i = 0;
            if(board[i][j] == 'O'){
                dfs(board, n, m, i, j);
            }
            i = n-1;
            if(board[i][j] == 'O'){
                dfs(board, n, m, i, j);
            }
        }
        convert(board);
    }
};