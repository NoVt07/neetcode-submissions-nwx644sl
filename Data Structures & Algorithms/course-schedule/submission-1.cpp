class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prerequisite = pre[1];
            adj[prerequisite].push_back(course);
            inDegree[course]++;
        }

        queue<int> q;
        int count = 0;
        for(int i = 0; i < numCourses; i++) 
            if(inDegree[i] == 0) 
                q.push(i);

        while(!q.empty()) {
            int idx = q.front();
            q.pop();
            count++;

            for(auto c : adj[idx]) {
                inDegree[c]--;
                if(inDegree[c] == 0) 
                    q.push(c);
            }
        }
        return count == numCourses;
    }
};
