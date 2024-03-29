class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        //  for(int i=0;i<nums.size();i++){
        //     for(int j = i+1;j<nums.size();j++){
        //         if(nums[i]+nums[j] == target){
        //             ans.push_back(i);
        //             ans.push_back(j);
        //         }
        //     }
        // }
        // return ans;
        
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i =0;i<n;i++){
            if(mp.find(target-nums[i]) != mp.end()){
                ans.push_back(i);
                ans.push_back(mp[target-nums[i]]);
            }
            else{
                mp[nums[i]] = i;
            }
        }
        return ans;
    }
};