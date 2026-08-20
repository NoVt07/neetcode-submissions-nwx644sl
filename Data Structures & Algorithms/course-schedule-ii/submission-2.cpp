class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        for(const auto& pre : prerequisites) {
            int course = pre[0];
            int prerequisite = pre[1];
            adj[prerequisite].push_back(course);
            inDegree[course]++;
        }

        queue<int> q;
        vector<int> res;
        for(int i = 0; i < numCourses; i++)
            if(inDegree[i] == 0) {
                q.push(i);
                res.push_back(i);
            }
        
        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            for(int neighbor : adj[cur]) {
                inDegree[neighbor]--;
                if(inDegree[neighbor] == 0) {
                    q.push(neighbor);
                    res.push_back(neighbor);
                }
            }
        }
        return res.size() == numCourses ? res : vector<int>{};
        
    }
};
