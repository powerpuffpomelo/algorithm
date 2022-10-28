// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<long long> lefts(n), rights(n);
        vector<pair<int, int>> nc;
        for(int i = 0; i < n; i++){
            nc.push_back({nums[i], cost[i]});
        }
        sort(nc.begin(), nc.end());
        for(int i = 0; i < n; i++){
            lefts[i] = nc[i].second;
            if(i) lefts[i] += lefts[i - 1];
        }
        for(int i = n - 1; i >= 0; i--){
            rights[i] = nc[i].second;
            if(i < n - 1) rights[i] += rights[i + 1];
        }
        long long x = nc[0].first;
        long long ans = LLONG_MAX, temp = 0;
        for(int i = 1; i < n; i++){
            temp += (nc[i].first - x) * nc[i].second;
        }
        ans = min(ans, temp);
        for(int i = 1; i < n; i++){
            temp += lefts[i - 1] * (nc[i].first - x);
            temp -= rights[i] * (nc[i].first - x);
            ans = min(ans, temp);
            x = nc[i].first;
        }
        return ans;
    }
};