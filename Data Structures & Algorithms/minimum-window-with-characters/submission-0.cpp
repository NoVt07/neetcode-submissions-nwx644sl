class Solution {
public:
    string minWindow(string s, string t){
        vector<int> need(128, 0);
        for(char c : t) need[c]++;

        int left = 0, right = 0;
        int required = t.length();
    
        int minlen = INT_MAX;
        int minStart = 0;

        while(right < s.length()){
            char c = s[right];
            if(need[c] > 0){
                required--;
            }
            need[c]--;
            right++;
            while(required == 0){
                if(right - left < minlen){
                    minlen = right - left;
                    minStart = left;
                }
                char leftChar = s[left];
                need[leftChar]++;
                if(need[leftChar] > 0){
                    required++;
                }
                left++;
            }
        }
        return minlen == INT_MAX ? "" : s.substr(minStart, minlen);
    }
};
