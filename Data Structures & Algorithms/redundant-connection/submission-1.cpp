class Solution {
private:
    int find(int i, vector<int>& parent) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i], parent);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        for(int i = 0; i < n; i++) parent[i] = i;
        for(const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            int rootU = find(u, parent);
            int rootV = find(v, parent);

            if(rootU == rootV) return edge;
            parent[rootV] = rootU;
        }
        return vector<int> {};
    }
};
