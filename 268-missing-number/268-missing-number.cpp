class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //vector<int> ans;
        for(int i =0;i<nums.size();i++){
            if(nums[i]!=i){
                return i;
            }
        }
        return nums[nums.size()-1] +1;
    }
};