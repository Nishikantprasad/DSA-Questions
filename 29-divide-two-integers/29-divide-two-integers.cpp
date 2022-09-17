class Solution {
public:
    int divide(long long int dividend,long long int divisor) {
        long long int res;
        res = dividend/divisor;
        if(res<INT_MIN){
            return INT_MIN;
        }
        else if(res> INT_MAX){
            return INT_MAX;
        }
        else{
            return res;
        }
    }
};