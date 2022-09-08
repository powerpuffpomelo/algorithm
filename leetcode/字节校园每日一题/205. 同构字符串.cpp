// ###################################################### 版本1 ###################################################### //
// 
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> ma1, ma2;
        for(int i = 0; i < s.size(); i++){
            if(!ma1.count(s[i]) && !ma2.count(t[i])) ma1[s[i]] = t[i], ma2[t[i]] = s[i];
            else if(ma1.count(s[i]) && ma1[s[i]] != t[i] || ma2.count(t[i]) && ma2[t[i]] != s[i]) return false;
        }
        return true;
    }
};