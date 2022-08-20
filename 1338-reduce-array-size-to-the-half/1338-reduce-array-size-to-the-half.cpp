class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        priority_queue<int> pq;
        for(auto it : arr){
            mp[it]++;
        }
        for(auto it : mp){
            pq.push(it.second);
        }
        int elem = 0;
        int setCount = 0;
        while(!pq.empty()){
            elem += pq.top();
            pq.pop();
            setCount++;
            if(elem >= n/2){
                return setCount;
            }
        }
        return 0;
    }
};