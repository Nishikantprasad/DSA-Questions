class Solution {
public:
    int solve(vector<int>& nums, vector<int>& multipliers,int l ,int r, 
              int index,vector<vector<int>> & dp){
        int n = nums.size();
        int m = multipliers.size();
        //base case
        if(index >= m){
            return 0;
        }
        if(dp[index][l] != INT_MIN){
            return dp[index][l];
        }
        int x = multipliers[index];
        int left = (nums[l] * x) + solve(nums, multipliers, l+1,r, index+1,dp);
        int right = (nums[r] * x) + solve(nums, multipliers,l,r-1,index+1,dp);
        return dp[index][l] = max(left, right);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        int l =0;
        int r = n-1;
        int index = 0;
        vector<vector<int>> dp(m+1, vector<int>(m+1,INT_MIN));
        return solve(nums,multipliers, l, r, index,dp);
    }
};