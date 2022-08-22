class Solution {
public:
    bool isPowerOfFour(int n) {
        for(int i = 0;i<=19;i++){
            long long ans = pow(4,i);
            if(ans ==n){
                return true;
            }
        }
        return false;
    }
};