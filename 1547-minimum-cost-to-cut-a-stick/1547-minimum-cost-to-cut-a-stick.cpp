class Solution {
public:
    long solve(int i , int j ,vector<int>& cuts,vector<vector<int>>& dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        long mini = INT_MAX;
        for(int index = i;index<=j;index++){
            long cost = cuts[j+1]-cuts[i-1]+ solve(i, index-1, cuts, dp) + solve(index+1, j,cuts,dp);
            mini = min(mini, cost);
        }
        dp[i][j] = mini;
        return dp[i][j];
    }
    
    int minCost(int n, vector<int>& cuts) {
        int size = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(size+1,vector<int>(size+1,-1));
        return solve(1,size,cuts,dp);
        
    }
};