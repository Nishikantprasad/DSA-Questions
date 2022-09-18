class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() < needle.size()){
            return -1;
        }
        for(int i = 0;i<haystack.size();i++){
            int x = needle.size()-1;
            int flag =0;
            if(haystack[i] == needle[0]){
                int j =i+1;
                int k =1;
                while(x--){
                    if(haystack[j] != needle[k]){
                        flag =1;
                        break;
                    }
                    j++;
                    k++;
                }
                if(flag ==0){
                    return i;
                }
            }
            
        }
        return -1;
    }
};