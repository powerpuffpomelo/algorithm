// ###################################################### 版本1 ###################################################### //
// f[i][j]表示，有多少个i开头的字符串将首字母换成j之后是有效的
class Solution {
public:
    unordered_set<string> se;
    long long distinctNames(vector<string>& ideas) {
        int f[26][26] = {0};
        for(auto s : ideas) se.insert(s);
        for(auto s : ideas){
            int a = s[0] - 'a';
            for(int i = 0; i < 26; i++){
                s[0] = i + 'a';
                if(!se.count(s)) f[a][i]++;
            }
        }
        long long ans = 0;
        for(auto s : ideas){
            int a = s[0] - 'a';
            for(int i = 0; i < 26; i++){
                s[0] = i + 'a';
                if(!se.count(s)) ans += f[i][a];
            }
        }
        return ans;
    }
};