class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        if(nums.size()==0 || k==0)return ans;
        
        unordered_map<int,int> m;
        for(int i = 0;i<nums.size();i++)m[nums[i]]++;
        
        priority_queue<pair<int,int>> pq;
        
        for(auto [a,b] : m){
            // pair<int,int> p = make_pair(i.second,i.first);
            // pq.push(p);
            pq.push({b,a});
        }
        
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
               
        return ans;
    }
};