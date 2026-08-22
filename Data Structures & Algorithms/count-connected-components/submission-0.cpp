class Solution {
private:
    int find(int i, vector<int>& parent) {
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i], parent);
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        int count = n;
        for(int i = 0; i < n; i++)
            parent[i] = i;
        
        for(const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            int rootU = find(u, parent);
            int rootV = find(v, parent);

            if(rootU != rootV) {
                parent[rootV] = rootU;
                count--;
            } 
        }

        return count;
    }
};
