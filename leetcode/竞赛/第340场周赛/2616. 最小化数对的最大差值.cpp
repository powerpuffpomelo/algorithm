// 二分答案 + 贪心
class Solution {
public:
    bool check(int x, vector<int>& nums, int p){
        int cnt = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i + 1] - nums[i] <= x){
                cnt++;
                i++;
            }
        }
        return cnt >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = nums[n - 1] - nums[0];
        while(l < r){
            int mid = l + r >> 1;
            if(check(mid, nums, p)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};