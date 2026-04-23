class Solution {
public:
    bool check(vector<int> piles, int k, int h){
        for(int x : piles){
            int y = (x % k == 0) ? x/k : x/k + 1;
            h -= y; 
        }
        return h >= 0;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        if(h == n){
            int max_k = 0;
            for(int x : piles){
                if(x > max_k) max_k = x;
            }
            return max_k;
        }

        int left = 1, right = 1000000000, mid = 0;
        while(left < right){
            mid = (left + right) / 2;
            cout << left << " " << right<<"\n";
            if(check(piles, mid, h)) right = mid;
            else left = mid + 1;  
        }
        return right;
    }
};
