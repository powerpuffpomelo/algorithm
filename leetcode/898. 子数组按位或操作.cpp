// ###################################################### 版本1 ###################################################### //
// dp，f[i]代表以第i个数结尾的子数组的按位或num数，最多32种，非常少（因为每次和前一个数或，都会让一些位变1，最多32位可以变）
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans, f, g;  // f和g是滚动数组
        for(auto x : arr){
            g.insert(x);
            for(auto y : f) g.insert(x | y);
            for(auto y : g) ans.insert(y);
            f = g, g.clear();
        }
        return ans.size();
    }
};