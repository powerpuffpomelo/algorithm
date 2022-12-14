// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> vec;
        for(int i = 0; i < 32; i++){
            vec.push_back(n >> i & 1);
        }
        uint32_t ans = 0;
        for(int i = 0; i < 32; i++){
            ans = (ans << 1) + vec[i];
        }
        return ans;
    }
};