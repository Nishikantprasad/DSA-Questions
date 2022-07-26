class Solution {
public:
    int solve(vector<int>&cost, int n){
        //base case
        if(n==0){
            return cost[0];
        }
        if(n ==1){
            return cost[1];
        }
        int ans = min(solve(cost,n-1) , solve(cost,n-2)) + cost[n];
        return ans;
    }
    
    int solve2(int n,vector<int>&cost,vector<int>& dp){
        //base case
        if(n==0){
            return cost[0];
        }
        if(n == 1){
            return cost[1];
        }
        //Step 3:
        if(dp[n] != -1){
            return dp[n];
        }
        
        //Step 2:
        dp[n] = min(solve2(n-1, cost, dp),solve2(n-2, cost, dp))+ cost[n];
        return dp[n];
    }
    
    
    int minCostClimbingStairs(vector<int>& cost) {
        // int n = cost.size();
        // int ans;
        // ans = min(solve(cost,n-1),solve(cost,n-2));
        // return ans;
        
        int n = cost.size();
        //Step 1:
        vector<int> dp(n+1,-1);
        int ans = min(solve2(n-1,cost,dp),solve2(n-2,cost,dp));
        return ans;
    }
};