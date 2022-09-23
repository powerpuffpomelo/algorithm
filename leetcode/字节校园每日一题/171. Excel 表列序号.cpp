// ###################################################### 版本1 ###################################################### //
// 
class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long ans = 0, p = 26;
        for(auto c :columnTitle){
            ans = ans * p + c - 'A' + 1;
        }
        return ans;
    }
};