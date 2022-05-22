class Solution {
public:
    bool canPlace(vector<vector<char>> &board,int i,int j,char num){
         int row = i - i%3, column = j - j%3;
        for(int x=0; x<9; x++) if(board[x][j] == num) return false;
        for(int y=0; y<9; y++) if(board[i][y] == num) return false;
        for(int x=0; x<3; x++)
        for(int y=0; y<3; y++)
            if(board[row+x][column+y] == num) return false;
        return true;
    }
    
    bool solve(vector<vector<char>> &board,int i,int j){
   
        if(i == 9) return true;
        if(j == 9) return solve(board,i+1,0);
        if(board[i][j] != '.') return solve(board,i,j+1);
        for(int num='1';num<='9';num++){
            if(canPlace(board,i,j,num)){
                board[i][j] = num;
                if(solve(board,i,j+1)) return true;
                board[i][j] = '.';
            }
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};