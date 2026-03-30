class Solution {

private:
    bool issafe(vector<string>& board,int n,int row,int col){
        //horizontally check
        for(int j=0;j<n;j++){
            if(board[row][j]=='Q'){
                return false;
            }
        }
        //vertically check 
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }
        //left diagonal
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        //right diagonal
        for(int i=row,j=col;i>=0 && j>=0;i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    void getposibleposition(vector<string>& board,int n,int row,vector<vector<string>>& ans){
        if(row==n){
            ans.push_back({board});
            return;
        }
        for(int j=0;j<n;j++){
            if(issafe(board,n,row,j)){
                board[row][j]='Q';
                getposibleposition(board,n,row+1,ans);
                board[row][j]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        vector<vector<string>>ans;
        getposibleposition(board,n,0,ans);
        return ans;
    }
};
