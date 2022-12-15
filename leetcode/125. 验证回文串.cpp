// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(auto c : s){
            if(c >= 'A' && c <= 'Z') str += c - 'A' + 'a';
            else if(c >= 'a' && c <= 'z' || c >= '0' && c <= '9') str += c;
        }
        string s2 = str;
        reverse(str.begin(), str.end());
        return str == s2;
    }
};