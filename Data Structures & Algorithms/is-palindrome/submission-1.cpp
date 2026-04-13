class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right){
            while(!isalnum(s[left])) left++;
            while(!isalnum(s[right])) right--;
            if(left >= right) return true; 
            char x = tolower(s[left]), y = tolower(s[right]);
            if(x != y) return false;
            left++;
            right--;
        }
        return true;
    }
};
