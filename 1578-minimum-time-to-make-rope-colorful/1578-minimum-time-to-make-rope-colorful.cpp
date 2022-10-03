class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int ans =0;
        for(int i =0;i<n-1;i++){
            if(colors[i] == colors[i+1]){
                int maxi = INT_MIN;
                int sum =0;
                while(colors[i] == colors[i+1]){
                    maxi = max(maxi , neededTime[i]);
                    sum += neededTime[i];
                    i++;
                }
                maxi = max(maxi , neededTime[i]);
                sum += neededTime[i];
                ans += sum - maxi;
            }
        }
        return ans;
        
    }
};