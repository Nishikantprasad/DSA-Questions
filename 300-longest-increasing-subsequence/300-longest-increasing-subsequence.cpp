class Solution {
public:
    int solve(vector<int> &nums, int curr,int prev,vector<vector<int>> &dp){
        if(curr == nums.size()){
            return 0;
        }
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }
        
        int exclude = 0 + solve(nums, curr+1,prev,dp);
        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1 + solve(nums, curr+1,curr, dp);
        }
        
        
        return dp[curr][prev+1] = max(include,exclude);
    }
    
    //*****  DP with BINARY SEARCH Concept -IMP ******
    int solveOptimal(vector<int> &nums, int n){
        if(n==0){
            return 0;
        }
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i =1;i<n;i++){
            if(nums[i] > ans.back()){  // ans.back() - gives you last elem in the ans array
                ans.push_back(nums[i]);
            }
            else{
                //find Index of just bada element in ans 
                int index = lower_bound(ans.begin(),ans.end(),nums[i])- ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return solve(nums,0,-1,dp);
        return solveOptimal(nums, n);
    }
};