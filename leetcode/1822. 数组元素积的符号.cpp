// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool pos = true;
        for(auto x : nums){
            if(x == 0) return 0;
            if(x < 0) pos = !pos;
        }
        if(pos) return 1;
        return -1;
    }
};