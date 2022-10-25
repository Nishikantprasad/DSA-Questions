class Solution {
public:
    int countPaths(int m , int n , int i ,int j , vector<vector<int>> &dp){
        //base case
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(i>=m || j>=n){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        dp[i][j] = countPaths(m,n,i+1,j,dp) + countPaths(m,n,i,j+1,dp);
        return dp[i][j];
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        int i = 0;
        int j =0;
        return countPaths(m, n, i, j , dp);
    }
};