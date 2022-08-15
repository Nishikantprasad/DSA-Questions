class Solution {
public:
    int solve(vector<int>& nums, int target, vector<int> &dp){
        if(target ==0){
            return 1;
        }
        //step3:
        if(dp[target] != -1){
            return dp[target];
        }
        
        //step 2:
        dp[target] =0;
        for(int i : nums){
            if(target >=i ){
                dp[target ] = dp[target] + solve(nums, target-i,dp);
            }
        }
        return dp[target];
        
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        //step1
        vector<int> dp(target+1, -1);
        return solve(nums,target, dp);
    }
};