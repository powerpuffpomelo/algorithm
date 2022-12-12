// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    bool checkValidString(string s) {
        int l = 0, r = 0;
        for(auto c : s){
            if(c == '(') l++, r++;
            else if(c == ')') l = max(0, l - 1), r--;
            else l = max(0, l - 1), r++;
            if(r < 0) return false;
        }
        return !l;
    }
};