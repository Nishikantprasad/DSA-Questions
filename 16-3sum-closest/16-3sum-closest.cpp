class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        //sort vector because we use two pointers to find the closest sum
        int sum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i+1;
            int right = nums.size() - 1;
            while (left < right) {
                int current_sum = nums[i] + nums[left] + nums[right];
                if (current_sum > target) right--;
                else if (current_sum == target) return current_sum;
                else if (current_sum < target) left++;
                if (abs(current_sum - target) < abs(sum - target)) sum = current_sum;
            }
        }
        return sum;
    }
};