class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum =0;
        int ans =0;
        unordered_map<int,int> mp;
        mp[sum] = 1;
        for(int i =0;i<nums.size();i++){
            sum = sum +nums[i];
            int  temp = sum-k;
            if(mp.find(temp) != mp.end()){
                ans = ans + mp[temp];
            }
            mp[sum]++;
        }
        return ans;
    }
};