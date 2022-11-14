// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int minDeletions(string s) {
        map<char, int> cnt;
        for(auto c : s) cnt[c]++;
        vector<int> vv;
        for(auto [k, v] : cnt) vv.push_back(v);
        sort(vv.rbegin(), vv.rend());
        int mmax = vv[0];
        int ans = 0;
        for(int i = 1; i < vv.size(); i++){
            mmax = max(0, min(mmax - 1, vv[i]));
            ans += vv[i] - mmax;
        }
        return ans;
    }
};