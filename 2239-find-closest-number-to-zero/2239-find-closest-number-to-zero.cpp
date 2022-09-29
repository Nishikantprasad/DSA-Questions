class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int mini = nums[0];
        for(int i =1;i<nums.size();i++){
            if(abs(nums[i])< abs(mini)){
               mini = nums[i] ;
             }
            if(nums[i] == abs(mini)){
                mini = abs(mini);
            }
        }
        return mini;
    }
};