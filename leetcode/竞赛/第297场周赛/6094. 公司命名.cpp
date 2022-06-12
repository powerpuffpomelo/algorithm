// ###################################################### 版本2 ###################################################### //
// 优化
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> use;
        for(auto s : ideas) use.insert(s);
        vector<vector<int>> cnt(26, vector<int>(26));
        for(auto s : ideas){
            int a = s[0] - 'a';
            for(int i = 0; i < 26; i++){
                s[0] = i + 'a';
                if(!use.count(s)) cnt[a][i]++;
            }
        }
        long long ans = 0;
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                ans += cnt[i][j] * cnt[j][i];
            }
        }
        return ans;
    }
};

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