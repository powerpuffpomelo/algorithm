// ###################################################### 版本1 ###################################################### //
// dp + 二分
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(n), g;   // dp[i]代表以第i个信封为结尾的最大序列长度，g[i]代表长度为i的信封序列的最外层套娃的最小宽度
        g.push_back(0);
        int ans = 0;
        for(int i = 0, j = 0; i < n; i++){
            if(envelopes[i][0] != envelopes[j][0]){
                while(j < i){
                    if(dp[j] == g.size()){
                        g.push_back(envelopes[j][1]);
                    }else{
                        g[dp[j]] = min(g[dp[j]], envelopes[j][1]);
                    }
                    j++;
                }
            }
            int l = 0, r = g.size();
            while(l < r){
                int mid = l + r >> 1;
                if(g[mid] >= envelopes[i][1]) r = mid;
                else l = mid + 1;
            }
            dp[i] = l;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};