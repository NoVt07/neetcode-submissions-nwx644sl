class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        int n = nums.size();
        priority_queue<pair<int, int>> maxheap;

        for(int i = 0; i < k; i++){
            maxheap.push({nums[i], i});
        }
        result.push_back(maxheap.top().first);

        for(int i = k; i < n; i++){
            maxheap.push({nums[i], i});

            while(maxheap.top().second <= i - k){
                maxheap.pop();
            }
            result.push_back(maxheap.top().first);
        }
        return result;
    }
};
