class Solution {
public:
    int n, m;
    vector<vector<int>>cor;
    vector<vector<char>>vis;
    char pac = 0x01, aln = 0x10, both = 0x11, none=0x00;
    void DFS(vector<vector<int>>&nums, int i, int j, char ocean){
        if(i<0 || j<0|| i>=n || j>=m || (vis[i][j] & ocean) == ocean){
            return;
        }
        vis[i][j] |= ocean;
        
        if(vis[i][j] == both){
            cor.push_back({i, j});
        }
        
        int x[4] = {1, -1, 0, 0};
        int y[4] = {0, 0, 1, -1};
        
        for(int p=0; p<4; p++){
            int xx = i+x[p];
            int yy = j+y[p];
            if(xx<n && xx>=0 && yy<m && yy>=0 && nums[xx][yy] < nums[i][j]){
                continue;
            }
            DFS(nums, xx, yy, ocean);
              
        }
       
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
         n = heights.size();
         m = heights[0].size();
        vis = vector<vector<char>>(n, vector<char>(m, none));
       
        for(int i=0; i<n; i++){
            DFS(heights, i, 0,pac); 
            DFS(heights, i, m-1,aln);
        }
        
        for(int j=0; j<m; j++){
            DFS(heights, 0, j, pac); 
            DFS(heights, n-1, j, aln); 
        }
        
        return cor;
    }
};