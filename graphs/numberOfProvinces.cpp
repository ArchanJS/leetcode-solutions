class Solution {
private:
    void dfs(int node, vector<int> adj[], vector<bool> &vis){
        vis[node]=1;
        //traverse all its neighbours
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(), res=0;
        
        //making adjacency list out of matrix
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                res++;
                dfs(i,adj,vis);
            }
        }
        
        return res;
    }
};