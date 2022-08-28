class Solution {
public:
    int solveMem(vector<int>& obstacles,int currlane,int currpos,vector<vector<int>> &dp){
        int n = obstacles.size()-1;
        //base case
        if(currpos == n){
            return 0;
        }
        //Step 3:
        if(dp[currlane][currpos] != -1){
            return dp[currlane][currpos];
        }
        
        if(obstacles[currpos+1] != currlane){
            return solveMem(obstacles, currlane, currpos+1,dp);
        } 
        else{
            int ans = INT_MAX;
            for(int i = 1;i<=3;i++){
                if(currlane != i && obstacles[currpos] != i){
                    ans = min(ans, 1+solveMem(obstacles, i,currpos,dp));
                }
            }
            //Step 2:
            dp[currlane][currpos] = ans;
            return dp[currlane][currpos];
        }
    }
    
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        //Step 1:
        vector<vector<int>> dp(4,vector<int>(n,-1));
        return solveMem(obstacles, 2,0,dp);
        
    }
};