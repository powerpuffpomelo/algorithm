class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(!n) return 0;
        vector<int> l(n), r(n);
        for(int i = 1, lmin = prices[0]; i < n; i++){
            l[i] = max(l[i - 1], prices[i] - lmin);
            lmin = min(lmin, prices[i]);
        }
        for(int i = n - 2, rmax = prices[n - 1]; i >= 0; i--){
            r[i] = max(r[i + 1], rmax - prices[i]);
            rmax = max(rmax, prices[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, l[i] + r[i]);
        }
        return ans;
    }
};