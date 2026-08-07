class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int, vector<int>>> maxHeap;

        for(int i = 0; i < points.size() ; i++) {
            int x = points[i][0];
            int y = points[i][1];

            int dis = x * x + y * y;
            maxHeap.push({dis , points[i]});
            if(maxHeap.size() > k) maxHeap.pop();
        }

        while(!maxHeap.empty()){
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return res;
    }
};
