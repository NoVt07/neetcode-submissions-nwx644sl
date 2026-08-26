class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        
        int prev2 = 1; // Số cách đến bậc i - 2
        int prev1 = 2; // Số cách đến bậc i - 1
        
        for (int i = 3; i <= n; i++) {
            int current = prev1 + prev2; // Số cách đến bậc hiện tại
            
            // Cập nhật lại 2 biến để chuẩn bị cho vòng lặp tiếp theo (dịch tới 1 bước)
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1; // prev1 lúc này chính là bậc n
    }
};