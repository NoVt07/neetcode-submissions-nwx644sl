class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        
        // Xây dựng danh sách kề và mảng in-degree
        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prerequisite = pre[1];
            adj[prerequisite].push_back(course); // Cạnh: pre -> course
            inDegree[course]++;
        }
        
        queue<int> q;
        // Đưa các khóa học không có điều kiện tiên quyết vào Queue
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        int count = 0; // Đếm số khóa học có thể hoàn thành
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            count++;
            
            // Giảm in-degree của các khóa học bị phụ thuộc
            for (int neighbor : adj[current]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        return count == numCourses;
    }
};