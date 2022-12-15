class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i = 0, minp = INT_MAX; i < prices.size(); i++){
            ans = max(ans, prices[i] - minp);
            minp = min(minp, prices[i]);
        }
        return ans;
    }
};