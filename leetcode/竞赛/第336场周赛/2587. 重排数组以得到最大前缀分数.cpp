// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    static bool cmp(int a, int b){
        return a > b;
    }
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        long long ans = 0, s = 0;    // 注意数据范围
        for(int i = 0; i < nums.size(); i++){
            s += nums[i];
            if(s <= 0) break;
            ans++;
        }
        return ans;
    }
};