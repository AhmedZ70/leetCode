class Solution {
public:
    int findParent (int node, vector<int>& parent){
        if (parent[node] != node){
            parent[node] = findParent(parent[node], parent);
        }
        return parent[node];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size(); 
        vector<int> parent(n+1); 
        for (int i = 0; i <= n; i++){
            parent[i] = i; 
        }
        for (auto & edge : edges){
            int a = edge[0]; 
            int b = edge[1]; 
            int parentA = findParent(a, parent);
            int parentB = findParent(b, parent);

            if (parentA == parentB){
                return edge; 
            }
            parent[parentA] = parentB;
        }
        return {};
    }
};