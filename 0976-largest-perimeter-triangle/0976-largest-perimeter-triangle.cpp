class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        // [3,2,3,4]
        sort(nums.begin(),nums.end());
        int n = nums.size();
        // if(n<3){
        //     return 0;
        // }
        int ans =0;
        int ele = n-1;
        for(int i =n-2;i>0;i--){
            if(nums[i] +  nums[i-1] > nums[ele]){
                ans = nums[i] + nums[i-1] + nums[ele];
                return ans ;
            }
            else{
                ele--;
            }
        }
        return 0;
    }
};