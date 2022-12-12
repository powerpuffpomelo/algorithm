// ###################################################### 版本1 ###################################################### //
// 
class Solution {
public:
    bool canWinNim(int n) {
        if(n % 4) return true;
        return false;
    }
};