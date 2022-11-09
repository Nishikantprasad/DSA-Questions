class Solution {
public:
    void twoSumSorted(int i , int j , vector<int>& nums,int target,vector<vector<int>>& res){
        int a = nums[i-1];
        while(i<j){
            if(nums[i] +nums[j]>target){
                j--;
            }
            else if(nums[i]+nums[j]<target){
                i++;
            }
            else{
                vector<int>ans;
                ans.push_back(a);
                ans.push_back(nums[i]);
                ans.push_back(nums[j]);
                
                res.push_back(ans);
                //duplicate b
                while(i<j && nums[i] == nums[i+1]){
                    i++;
                }
                while(i<j &&nums[j] == nums[j-1]){
                    j--;
                }
                
                
                i++;
                j--;
            }
        }
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        // [-4,-1,-1,0,1,2]
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i =0;i<n;i++){
            //b+c = 0-a
            if(i ==0 || nums[i-1] != nums[i]){
                twoSumSorted(i+1, n-1,nums,0-nums[i],res);
            }
        }
        return res;
    }
};