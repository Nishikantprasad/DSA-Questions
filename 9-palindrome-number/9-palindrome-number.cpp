class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        string str = to_string(x);
        int n = str.length();
        int i =0;
        int j = n-1;
        while(i<j){
           if(str[i] == str[j]){
               i++;
               j--;
           }else{
               return false;
           }
        }
        return true;
    }
};