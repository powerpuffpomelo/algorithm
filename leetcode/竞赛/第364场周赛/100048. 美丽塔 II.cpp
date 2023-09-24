// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    typedef pair<long long, long long> pii;
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long ans = 0;
        stack<pii> stkl, stkr;
        int n = maxHeights.size();
        vector<long long> vecl, vecr;
        long long temp = 0;
        stkl.push({-1, 0});
        for(int i = 0; i < n; i++){
            long long h = maxHeights[i];
            while(stkl.top().second >= h){
                pii t = stkl.top();
                stkl.pop();
                temp -= (t.first - stkl.top().first) * t.second;
            }
            temp += (i - stkl.top().first) * h;
            stkl.push({i, h});
            vecl.push_back(temp);
        }
        temp = 0;
        stkr.push({n, 0});
        for(int i = n - 1; i >= 0; i--){
            long long h = maxHeights[i];
            while(stkr.top().second >= h){
                pii t = stkr.top();
                stkr.pop();
                temp -= (stkr.top().first - t.first) * t.second;
            }
            temp += (stkr.top().first - i) * h;
            stkr.push({i, h});
            vecr.push_back(temp);
        }
        reverse(vecr.begin(), vecr.end());
        for(int i = 0; i < n; i++){
            long long temp = vecl[i] + vecr[i] - maxHeights[i];
            ans = max(ans, temp);
        }
        return ans;
    }
};