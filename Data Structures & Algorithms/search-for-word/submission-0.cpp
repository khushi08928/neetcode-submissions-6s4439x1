class Solution {
private:
    bool foundpath(vector<vector<char>>& board,string word,int row,int col,int ind){
        int n=board.size();
        int m=board[0].size();
        if(ind==word.size()) return true;
        if(row<0 || col<0 || row>=n || col>=m || board[row][col]!=word[ind]) return false;
        char temp=board[row][col];
        board[row][col]='1';
        bool found=foundpath(board,word,row+1,col,ind+1) ||//down
                   foundpath(board,word,row-1,col,ind+1) ||//up
                   foundpath(board,word,row,col+1,ind+1) ||//right
                   foundpath(board,word,row,col-1,ind+1); //left
        board[row][col]=temp; //backtrack step
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(foundpath(board,word,i,j,0)) return true;
            }
        }
        return false;
    }
};
