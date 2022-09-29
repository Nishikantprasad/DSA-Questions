class Solution {
public:
    string truncateSentence(string s, int k) {
        int countSpaces = 0;
        for(int i =0;i<s.length();i++){
            if(s[i] == ' '){
                countSpaces++;
            }
            if(countSpaces == k){
                s.erase(s.begin()+i,s.end());
            }
        }
       
        return s;
    }
};