class Solution {

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) return false;

        vector<int> parent(n);
        for(int i = 0; i < n; i++)
            parent[i] = i;

        for(const auto& edge : edges){
            int u = edge[0];
            int v = edge[1];

            int rootU = find(u, parent);
            int rootV = find(v, parent);

            if(rootU == rootV) return false;

            parent[rootU] = rootV;
        }
        return true;
    }

private:
    int find(int i, vector<int>& parent) {
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i], parent);
    }
};
