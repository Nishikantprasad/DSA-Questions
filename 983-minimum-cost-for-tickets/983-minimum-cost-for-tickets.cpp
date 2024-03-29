class Solution {
public:
    int solveRec(int n , vector<int> days, vector<int>& costs,int index){
        if(index >= n){
            return 0;
        }
        int op1 = costs[0] + solveRec(n, days, costs,index+1);
        
        int i =0;
        for(i = index;i<n && days[i]<days[index]+7;i++);
        int op2 = costs[1] + solveRec(n,days,costs,i);
        
        for(i =index;i<n && days[i]<days[index]+30;i++);
        int op3 = costs[2] + solveRec(n,days, costs,i);
        return min(op1,min(op2,op3));
        
    }
    
    
    int solve(int n,vector<int> & days, vector<int> & costs,int index,vector<int>&dp){
        //base case
        if(index>=n){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        //1 Day pass
        int op1 = costs[0] + solve(n,days,costs,index+1,dp);
        
        //7 day pass
        int i =0;
        for(i = index; i<n && days[i]<days[index]+7;i++);
        int op2 = costs[1] + solve(n,days,costs,i,dp);
        
        //30 day pass
        for(i = index; i<n && days[i]<days[index]+30;i++);
        int op3 = costs[2] + solve(n,days,costs,i,dp);
        
        dp[index] =  min(op1,min(op2,op3));
        return dp[index];
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1,-1);
        return solve(n,days, costs,0,dp);
    }
};