// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int nextGreaterElement(int n) {
        if(n < 10) return -1;
        long long ans = 0;
        vector<int> vv;
        while(n){
            vv.push_back(n % 10);
            n /= 10;
        }
        reverse(vv.begin(), vv.end());
        int k = vv.size() - 1;
        while(k > 0 && vv[k - 1] >= vv[k]) k--;
        if(!k) return -1;
        int u = k - 1, temp = vv[k - 1];
        while(k < vv.size() && vv[k] > temp) k++;
        k--;
        swap(vv[u], vv[k]);
        sort(vv.begin() + u + 1, vv.end());
        for(auto x : vv) ans = ans * 10 + x;
        return ans <= INT_MAX ? ans : -1;
    }
};