// ###################################################### 版本1 ###################################################### //
class Solution {
public:
    bool queryString(string s, int n) {
        unordered_set<int> se;
        for(int i = 0; i < s.size(); i++){
            int x = 0;
            for(int j = i; j < s.size(); j++){
                x = x * 2 + s[j] - '0';
                if(x > n) break;
                if(x) se.insert(x);
            }
        }
        return se.size() == n;
    }
};