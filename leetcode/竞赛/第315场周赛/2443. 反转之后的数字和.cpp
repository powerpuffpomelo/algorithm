// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int x = 0; x <= num; x++){
            string str = to_string(x);
            reverse(str.begin(), str.end());
            if(x + stoi(str) == num) return true;
        }
        return false;
    }
};