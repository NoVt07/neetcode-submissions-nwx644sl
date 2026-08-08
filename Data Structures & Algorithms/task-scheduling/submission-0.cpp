class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        int maxfreq = 0;
        for(auto c : tasks) {
            freq[c - 'A']++;
            if(freq[c - 'A'] > maxfreq) maxfreq = freq[c - 'A'];
        }
        int count = 0;
        for(auto c : freq) {
            if(maxfreq == c) count++;
        }

        int s = (maxfreq - 1) * (n + 1) + count;
        return max(s, (int)tasks.size());
    }
};
