// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        long long ans = 0;
        int n = nums.size();
        vector<int> nums1, nums2, target1, target2;
        for(int i = 0; i < n; i++){
            if(nums[i] % 2) nums1.push_back(nums[i]);
            else nums2.push_back(nums[i]);
            if(target[i] % 2) target1.push_back(target[i]);
            else target2.push_back(target[i]);
        }
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        sort(target1.begin(), target1.end());
        sort(target2.begin(), target2.end());
        for(int i = 0; i < nums1.size(); i++){
            ans += abs(nums1[i] - target1[i]) / 2;
        }
        for(int i = 0; i < nums2.size(); i++){
            ans += abs(nums2[i] - target2[i]) / 2;
        }
        ans /= 2;
        return ans;
    }
};