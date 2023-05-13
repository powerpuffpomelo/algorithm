// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int> neg;
        int ans = -1;
        for(auto x : nums){
            if(neg.count(-x)) ans = max(ans, abs(x));
            else neg.insert(x);
        }
        return ans;
    }
};