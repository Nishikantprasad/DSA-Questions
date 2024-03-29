class Solution {
public:
    int solve(int dice, int faces, int target,  vector<vector<int>> &dp){
        if(target < 0){
            return 0;
        }
        if(dice ==0 && target != 0){
            return 0;
        }
        if(target ==0 && dice !=0){
            return 0;
        }
        // 0 target hai or 0 dice hai to 1 way hoga fekne ka
        if(target ==0 && dice ==0){
            return 1;
        }
        if(dp[dice][target] != -1){
            return dp[dice][target];
        }
        long long ans =0;
        for(int i =1;i<=faces;i++){
            ans += solve(dice-1,faces, target-i,dp);
        }
        return dp[dice][target] = ans % 1000000007;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return solve(n,k,target,dp);
    }
};