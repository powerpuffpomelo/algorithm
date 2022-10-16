// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        string str = to_string(x);
        reverse(str.begin(), str.end());
        if(str == to_string(x)) return true;
        return false;
    }
};