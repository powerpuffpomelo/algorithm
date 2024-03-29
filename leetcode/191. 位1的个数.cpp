// ###################################################### 版本1 ###################################################### //
// 
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        for(int i = 0; i < 32; i++){
            ans += n >> i & 1;
        }
        return ans;
    }
};

// ###################################################### 版本2 ###################################################### //
// lowbit
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n){
            n -= n & -n;
            ans++;
        }
        return ans;
    }
};