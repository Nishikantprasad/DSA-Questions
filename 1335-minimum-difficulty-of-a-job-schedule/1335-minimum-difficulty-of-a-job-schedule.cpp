class Solution {
public:
    int solve(vector<int>& jobd, int d, int index, int n,vector<vector<int>> &dp){
        //base case
        if(d ==1){
            return *max_element(jobd.begin()+index,jobd.end());
        }
        if(dp[index][d] != -1){
            return dp[index][d];
        }
        int currDifficulty = INT_MIN;
        int ans = INT_MAX;
        for(int i = index;i<=n-d;i++){
            currDifficulty = max(currDifficulty, jobd[i]);
            ans = min(ans, currDifficulty + solve(jobd, d-1, i+1,n,dp));
        }
        dp[index][d] = ans ;
        return dp[index][d];
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d){
            return -1;
        }
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(jobDifficulty , d,0,n,dp);
    }
};