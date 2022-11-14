// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    unordered_map<int, int> ma;
    int findMaxLength(vector<int>& nums) {
        ma[0] = -1;
        int s = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]) s++;
            else s--;
            if(!ma.count(s)) ma[s] = i;
            else ans = max(ans, i - ma[s]);
        }
        return ans;
    }
};