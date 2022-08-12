class Solution {
public:
    int getint(char ch){
        if(ch == 'I'){
            return 1;
        }
        if(ch =='V'){
            return 5;
        }
        if(ch == 'X'){
            return 10;
        }
        if(ch == 'L'){
            return 50;
        }
        if(ch =='C'){
            return 100;
        }
        if(ch == 'D'){
            return 500;
        }
        return 1000;

    }
    int romanToInt(string s) {
        int n = s.length();
        int sum = getint(s[n-1]);
        for(int i =n-2;i>=0;i--){
            if((getint(s[i])) < (getint(s[i+1]))){
                sum = sum - getint(s[i]);
            }
            else{
                sum += getint(s[i]);
            }
        }
        return sum;
    }
};