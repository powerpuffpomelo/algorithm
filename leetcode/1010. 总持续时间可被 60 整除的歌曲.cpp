// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size(), ans = 0;
        map<int, int> mp;
        for(int i = 0; i < n; i++){
            int x = time[i] % 60;
            ans += mp[(60 - x) % 60];
            mp[x]++;
        }
        return ans;
    }
};