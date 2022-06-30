// ###################################################### 版本1 ###################################################### //
// 我的初版，贪心
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int l = 0, r = 0;
        string ans;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') l++;
            else if(s[i] == ')') r++;
            if(l < r) r--;
            else ans += s[i];
        }
        if(l > r){
            string tmp;
            for(int i = ans.size() - 1; i >= 0; i--){
                if(ans[i] == '(' && l > r) l--;
                else tmp += ans[i];
            }
            reverse(tmp.begin(), tmp.end());
            ans = tmp;
        }
        return ans;
    }
};