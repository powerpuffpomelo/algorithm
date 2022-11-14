// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> prodl(n, 1), prodr(n, 1), ans(n);
        for(int i = 0; i < n - 1; i++) prodl[i + 1] = prodl[i] * a[i];
        for(int i = n - 1; i > 0; i--) prodr[i - 1] = prodr[i] * a[i];
        for(int i = 0; i < n; i++) ans[i] = prodl[i] * prodr[i];
        return ans;
    }
};