class Solution {
public:
    bool check(vector<int>& base,vector<int> &newBox){
        if(newBox[0]<=base[0] && newBox[1]<= base[1] && newBox[2]<=base[2]){
            return true;
        }
        else{
            return false;
        }
    }
    
    int solve(vector<vector<int>>& cuboids, int curr ,int prev,vector<vector<int>> &dp){
        if(curr == cuboids.size()){
            return 0;
        }
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }
        
        int include =INT_MIN;
        if(prev == -1 || check(cuboids[curr],cuboids[prev])){
            include = cuboids[curr][2] + solve(cuboids, curr+1,curr, dp);
        }
        int exclude = 0 + solve(cuboids, curr+1, prev, dp);
        dp[curr][prev+1] = max(include, exclude);
        return dp[curr][prev+1];
    }
    
    int maxHeight(vector<vector<int>>& cuboids) {
        //Step1 : sort all dimensions for all cuboid
        for(auto &a: cuboids){
            sort(a.begin(),a.end());
        }
        //Step2: sort dimensions on the basis of width or length
        sort(cuboids.begin(),cuboids.end());
        
        int n =cuboids.size();
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return solve(cuboids, 0,-1,dp);
    }
};