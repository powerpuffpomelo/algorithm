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