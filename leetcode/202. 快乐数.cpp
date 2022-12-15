// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    unordered_set<int> se;
    bool isHappy(int n) {
        while(n != 1){
            se.insert(n);
            int x = 0;
            while(n){
                x += (n % 10) * (n % 10);
                n /= 10;
            }
            if(se.count(x)) return false;
            n = x;
        }
        return true;
    }
};