// ###################################################### 版本1 ###################################################### //
// 双指针
class Solution {
public:
    static const int mod = 1e9 + 7, N = 1e5 + 10;
    int p[N];
    void init(int n){  // 2的幂次，预先打表存储
        p[0] = 1;
        for(int i = 1; i < n; i++){
            p[i] = (p[i - 1] << 1) % mod;
        }
    }
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        init(n);
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0, j = n - 1; i <= j;){
            if(nums[i] + nums[j] > target){
                j--;
            }else{
                ans = (ans + p[j - i]) % mod;
                i++;
            }
        }
        return ans;
    }
};