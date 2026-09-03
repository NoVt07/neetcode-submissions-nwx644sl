class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        
        for (int i = 0; i < s.length(); i++) {
            // Tâm là 1 ký tự (độ dài chuỗi lẻ)
            count += countPalindromes(s, i, i);
            // Tâm là 2 ký tự (độ dài chuỗi chẵn)
            count += countPalindromes(s, i, i + 1);
        }
        
        return count;
    }
    
private:
    int countPalindromes(const string& s, int left, int right) {
        int res = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            res++;
            left--;
            right++;
        }
        return res;
    }
};