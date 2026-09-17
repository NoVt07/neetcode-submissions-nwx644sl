class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (int i = 31; i >= 0; --i) {
            uint32_t bit = (n >> i) & 1U;
            if(bit & 1 == 1) count++;
        }
        return count;
    }
};
