// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    unordered_map<char, int> ma;
    unordered_map<char, int> prio;

    void init(){
        ma['I'] = 1, ma['V'] = 5, ma['X'] = 10, ma['L'] = 50, ma['C'] = 100, ma['D'] = 500, ma['M'] = 1000;
        prio['I'] = 1, prio['V'] = 2, prio['X'] = 3, prio['L'] = 4, prio['C'] = 5, prio['D'] = 6, prio['M'] = 7;
    }

    int romanToInt(string s) {
        init();
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(i < s.size() - 1 && prio[s[i]] < prio[s[i + 1]]){
                ans += ma[s[i + 1]] - ma[s[i]];
                i++;
            }
            else ans += ma[s[i]];
        }
        return ans;
    }
};