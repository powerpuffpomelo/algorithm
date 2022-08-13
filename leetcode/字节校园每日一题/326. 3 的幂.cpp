// ###################################################### 版本3 ###################################################### //
// 数论  整型范围内3的最大次幂 3^19
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};

// ###################################################### 版本2 ###################################################### //
// 打表
class Solution {
public:
    set<long long> se;
    bool isPowerOfThree(int n) {
        long long x = 1;
        while(x < INT_MAX){
            se.insert(x);
            x *= 3;
        }
        return se.count(n);
    }
};

// ###################################################### 版本1 ###################################################### //
// 递归
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 1) return true;
        if(n > 1){
            int t = n / 3;
            if(t * 3 == n) return isPowerOfThree(t);
        }
        return false;
    }
};