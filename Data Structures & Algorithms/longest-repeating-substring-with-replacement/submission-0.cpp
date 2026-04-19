class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> c(26, 0);
        int max_len = 0, maxfreq = 0;
        int n = s.size();
        int left = 0;

        for(int i = 0; i < n; i++){
            int x = s[i] - 'A';
            c[x]++;
            maxfreq = max(maxfreq, c[x]);
            while(i - left + 1 - maxfreq > k){
                c[s[left]-'A']--;
                left++;
            }
            max_len = max(max_len, i - left + 1);
        }
        return max_len;
    }
};
