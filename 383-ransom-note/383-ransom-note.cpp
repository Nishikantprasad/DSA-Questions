class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char ,int> mp;
        for(int i =0;i<ransomNote.length();i++){
            mp[ransomNote[i]]++;
        }
        unordered_map<char ,int> mp2 ;
        for(int i =0;i<magazine.length();i++){
            mp2[magazine[i]]++;
        }
        for(auto x : mp){
            if(mp2[x.first] < x.second){
                return false;
            }
        }
        return true;
        
    }
};