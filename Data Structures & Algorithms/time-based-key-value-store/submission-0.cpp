class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(store.find(key) == store.end()) return "";

        const vector<pair<int, string>>& data = store[key];

        int left = 0;
        int right = data.size() - 1;
        string res = "";

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(data[mid].first <= timestamp) {
                res = data[mid].second;
                left = mid + 1;
            }
            else right = mid - 1;
        }
        return res;
    }
};
