class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string ans = "";
        for(int i =0;i<word1.size();i++){
            ans += word1[i];
        }
        string ans2 = "";
        for(int i =0;i<word2.size();i++){
            ans2 += word2[i];
        }
        if(ans != ans2){
            return false;
        }
        return true;
    }
};