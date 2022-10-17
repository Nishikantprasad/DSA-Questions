class Solution {
public:
    bool checkIfPangram(string sentence) {
        int n= sentence.size();
        unordered_map<int,int> mp;
        for(int i =0;i<n;i++){
            mp[sentence[i]]++;
        }
        if(mp.size() == 26){
            return true;
        }
        return false;
    }
};