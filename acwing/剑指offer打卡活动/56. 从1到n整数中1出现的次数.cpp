// ###################################################### 版本2 ###################################################### //
// 简洁一点的写法
class Solution {
public:
    int numberOf1Between1AndN_Solution(int n) {
        vector<int> num;
        while(n){
            num.push_back(n % 10);
            n /= 10;
        }
        int ans = 0;
        for(int i = 0; i < num.size(); i++){
            int left = 0, right = 0, t = 1;
            for(int j = num.size() - 1; j > i; j--) left = left * 10 + num[j];
            for(int j = i - 1; j >= 0; j--) right = right * 10 + num[j], t *= 10;
            ans += left * t;
            if(num[i] == 1) ans += right + 1;
            else if(num[i] > 1) ans += t;
        }
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int numberOf1Between1AndN_Solution(int n) {
        int ans = 0, n_copy = n;
        vector<int> num;
        while(n_copy){
            num.push_back(n_copy % 10);
            n_copy /= 10;
        }
        for(int k = 0; k < num.size(); k++){
            int x = pow(10, k);
            if(num[k] > 1){
                int tt = (n / (x * 10) + 1) * x;
                ans += tt;
            }else if(num[k] == 1){
                int tt = (n / (x * 10)) * x + n % x + 1;
                ans += tt;
            }else{
                int tt = (n / (x * 10)) * x;
                ans += tt;
            }
        }
        return ans;
    }
};