// ###################################################### 版本1 ###################################################### //
// 
class Solution {
public:
    int divide(int x, int y) {
        typedef long long LL;
        vector<LL> exp;
        bool is_minus = false;
        if(x < 0 && y > 0 || x > 0 && y < 0) is_minus = true;
        LL a = abs((LL)x), b = abs((LL)y);
        for(LL i = b; i <= a; i += i) exp.push_back(i);
        LL ans = 0;
        for(int i = exp.size() - 1; i >= 0; i--){
            if(a >= exp[i]){
                a -= exp[i];
                ans += (LL)1 << i;
            }
        }
        if(is_minus) ans = -ans;
        if(ans > INT_MAX) ans = INT_MAX;
        if(ans < INT_MIN) ans = INT_MIN;
        return ans;
    }
};