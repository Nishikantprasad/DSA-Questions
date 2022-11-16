class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        int n = nums.size();
        unordered_map<double,int> mp;
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = n-1;
        while(i<j){
            double avg = (nums[i] + nums[j] )/2.0;
            mp[avg]++;
            i++;
            j--;
        }
        return mp.size();
    }
};