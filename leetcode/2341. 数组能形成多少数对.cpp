// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> ma;
        for(auto x : nums) ma[x]++;
        vector<int> ans(2);
        for(auto [k, v] : ma){
            ans[0] += (v / 2);
            if(v % 2) ans[1]++;
        }
        return ans;
    }
};