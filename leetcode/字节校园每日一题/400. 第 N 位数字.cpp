// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int findNthDigit(int n) {
        long long num = 9, len = 1;
        while(n > num * len){
            n -= num * len;
            len++;
            num *= 10;
        }
        long long p = n / len;
        long long x = pow(10, len - 1) + p - 1;
        if(n % len == 0) return x % 10;
        else return to_string(x + 1)[n % len - 1] - '0';
    }
};