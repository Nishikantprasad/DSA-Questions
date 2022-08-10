class Solution {
public:
    bool solve(vector<vector<char>>& board, string word, int i, int j ,int index,
               vector<vector<bool>>&visited){
        if(index == word.length()-1){
            return true;
        }
        visited[i][j]= true ;
        if(i>0 && !visited[i-1][j] && board[i-1][j]==word[index+1] && 
           solve(board,word,i-1,j,index+1,visited)){
            return true;
        }
        if(j>0 && !visited[i][j-1] && board[i][j-1]==word[index+1] && 
           solve(board,word,i,j-1,index+1,visited)){
            return true;
        }
        if(i<board.size()-1 && !visited[i+1][j] && board[i+1][j]==word[index+1] && 
           solve(board,word,i+1,j,index+1,visited)){
            return true;
        }
        if(j<board[0].size()-1 && !visited[i][j+1] && board[i][j+1]==word[index+1] && 
           solve(board,word,i,j+1,index+1,visited)){
            return true;
        }        
        visited[i][j] = false;
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for(int i=0;i<row;i++){
            for(int j =0;j<col;j++){
                if(board[i][j] == word[0]){
                    if(solve(board,word,i,j,0,visited)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};