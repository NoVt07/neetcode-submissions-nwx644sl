class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        int minPrice = prices[0];

        for(int price : prices){
            if(price < minPrice) minPrice = price;
            else ans = max(ans, price - minPrice);
        }
        return ans;
    }
};
