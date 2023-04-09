class Solution {
public:
    bool prime(int x){
        for(int i = 2; i <= x / i; i++){
            if(x % i == 0) return false;
        }
        return x >= 2;  // 特判：1不是质数
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int a = nums[i][i], b = nums[i][n - 1 - i];
            if(prime(a)) ans = max(ans, a);
            if(prime(b)) ans = max(ans, b);
        }
        return ans;
    }
};