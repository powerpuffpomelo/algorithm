// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int pmin = -1, pmax = -1, l = -1;   // pmin, pmax 代表最右侧的最小/最大元素位置；l 代表合法序列开始位置的前一个位置
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < minK || nums[i] > maxK){  // 若遇到不合法元素，则直接把l移动到当前位置
                l = i;
            }else{
                if(nums[i] == minK) pmin = i;
                if(nums[i] == maxK) pmax = i;   // 注意minK和maxK可能相等
                ans += max(min(pmin, pmax) - l, 0);   // pmin、pmax中最小的那个，决定了子序列的左端点位置的上界
            }
        }
        return ans;
    }
};