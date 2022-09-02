class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int i, count=0;
        for(i =n-1; i>=0; i--){
            if(s[i] != ' '){
                break;
            }
        }
        
        for(;i>=0;i--){
            if(s[i] == ' '){
                break;
            }
            count++;
        }
        return count;
    }
};