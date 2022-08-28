class Solution {
public:
    int solveMem(vector<vector<char>> & matrix, int n ,int m , 
                 vector<vector<int>> &dp,int &maxi,int i, int j){
        if(i >= n || j >= m){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int right = solveMem(matrix, n,m,dp,maxi,i,j+1);
        int diagonal = solveMem(matrix, n,m,dp,maxi,i+1,j+1);
        int down = solveMem(matrix, n,m,dp,maxi,i+1,j);
        
        if(matrix[i][j] == '1'){
            dp[i][j] =  1 + min(right , min(diagonal,down));
            maxi = max(maxi,dp[i][j]);
            return dp[i][j];
        }
        else{
            return dp[i][j] =0;
        }

    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxi =0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        solveMem(matrix,n,m,dp,maxi,0,0);
        return maxi*maxi;
    }
};