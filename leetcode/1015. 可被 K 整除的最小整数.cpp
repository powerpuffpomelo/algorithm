// ###################################################### 版本1 ###################################################### //
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        unordered_set<int> se;
        int x = 1 % k;
        while(x && !se.count(x)){
            se.insert(x);
            x = (x * 10 + 1) % k;
        }
        return x ? -1 : se.size() + 1;
    }
};