// ###################################################### 版本1 ###################################################### //
// 
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int, int> ma;
        for(auto x : nums) ma[x]++;
        int s = ma.size();  // 需要实现存储，不然判断ma[0]的时候，若一开始没有ma[0]则自动加上0这个键
        if(ma[0]) s -= 1;
        return s;
    }
};