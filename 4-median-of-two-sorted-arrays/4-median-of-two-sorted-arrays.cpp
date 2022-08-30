class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        double * nums3 = new double[n+m];
        int i=0,j=0,k=0;
        while(i<n && j<m){
            if(nums1[i] < nums2[j]){
                nums3[k] = nums1[i];
                i++;
                k++;
            }
            else{
                nums3[k] = nums2[j];
                k++;
                j++;
            }}
            while(i<n){
                nums3[k] = nums1[i];
                k++;
                i++;
            }
            while(j<m){
                nums3[k] = nums2[j];
                k++;
                j++;
            }
        double ans;
        int size = n+m;
        if(size % 2 == 0){
            ans = (nums3[size/2-1] + nums3[size/2])/2;
        }
        else{
             ans = nums3[size/2];
        }
        return ans;
    }
};