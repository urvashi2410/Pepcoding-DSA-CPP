#include <bits/stdc++.h>
using namespace std;

void displayBoard(vector<vector<int>> chess){
    for(int i = 0; i < chess.size(); i++){
        for(int j = 0; j < chess[0].size(); j++){
            cout << chess[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printKnightsTour(vector<vector<int>> &chess, int r, int c, int nextMove){
    if(r < 0 || c < 0 || r >= chess.size() || c >= chess.size() || chess[r][c] > 0){
        return;
    }
    else if (nextMove == chess.size() * chess.size()){
        chess[r][c] = nextMove;
        displayBoard(chess);
        chess[r][c] = 0;
        return;
    }
    
    chess[r][c] = nextMove;
    printKnightsTour(chess, r-2, c+1, nextMove + 1);
    printKnightsTour(chess, r-1, c+2, nextMove + 1);
    printKnightsTour(chess, r+1, c+2, nextMove + 1);
    printKnightsTour(chess, r+2, c+1, nextMove + 1);
    printKnightsTour(chess, r+2, c-1, nextMove + 1);
    printKnightsTour(chess, r+1, c-2, nextMove + 1);
    printKnightsTour(chess, r-1, c-2, nextMove + 1);
    printKnightsTour(chess, r-2, c-1, nextMove + 1);
    
    chess[r][c] = 0;
}


int main() {
	int n;
	int r, c;
	cin >> n >> r >> c;
	
	vector<vector<int>> chess(n, vector<int>(n));
	printKnightsTour(chess, r, c, 1);
	return 0;
}
