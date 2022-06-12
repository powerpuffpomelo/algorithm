// ###################################################### 版本1 ###################################################### //
// 
class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans = 0, last = 0;
        for(auto& p : brackets){
            ans += max(0.0, min(income, p[0]) - last) * p[1] / 100;
            last = p[0];
        }
        return ans;
    }
};