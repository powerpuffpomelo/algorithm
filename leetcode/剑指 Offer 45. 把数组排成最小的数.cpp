// ###################################################### 版本1 ###################################################### //
// 
class Solution {
public:
    static bool cmp(string a, string b){
        return a + b < b + a;   // 既然想不出规则，就用简单判断
    }
    string minNumber(vector<int>& nums) {
        vector<string> vv;
        for(auto x : nums) vv.push_back(to_string(x));
        sort(vv.begin(), vv.end(), cmp);
        string ans;
        for(auto s : vv) ans += s;
        return ans;
    }
};