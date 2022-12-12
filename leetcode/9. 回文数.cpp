// ###################################################### 版本2 ###################################################### //
// 边生成边判断，只生成一半防止溢出
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || x && x % 10 == 0) return false;
        int s = 0;
        while(s <= x){
            s = s * 10 + x % 10;
            if(s == x || s == x / 10) return true;  // 分奇偶
            x /= 10;
        }
        return false;
    }
};

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