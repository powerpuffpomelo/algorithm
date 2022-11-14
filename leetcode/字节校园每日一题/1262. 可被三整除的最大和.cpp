// ###################################################### 版本2 ###################################################### //
// 超优雅的解法！remainder[i]维护余数是i的最大和
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int remainder[3] = {0};
        for(int i = 0; i < nums.size(); i++){
            int a = remainder[0] + nums[i];
            int b = remainder[1] + nums[i];
            int c = remainder[2] + nums[i];
            remainder[a % 3] = max(remainder[a % 3], a);
            remainder[b % 3] = max(remainder[b % 3], b);
            remainder[c % 3] = max(remainder[c % 3], c);
        }
        return remainder[0];
    }
};

// ###################################################### 版本1 ###################################################### //
// 常规解法，求sum，然后需要减的话就减
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        const int INF = 1e9;
        int sum = 0;
        int f1 = INF, s1 = INF;  // f1 s1分别代表模3余1的最小值、次小值
        int f2 = INF, s2 = INF;
        for(auto x : nums){
            sum += x;
            if(x % 3 == 1){
                if(x <= f1) s1 = f1, f1 = x;
                else if(x < s1) s1 = x;
            }else if(x % 3 == 2){
                if(x <= f2) s2 = f2, f2 = x;
                else if(x < s2) s2 = x;
            }
        }
        if(sum % 3 == 0) return sum;
        else if(sum % 3 == 1) return max(sum - f1, sum - f2 - s2);
        else return max(sum - f2, sum - f1 - s1);
    }
};