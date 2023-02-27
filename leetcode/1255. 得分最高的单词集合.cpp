// ###################################################### 版本1 ###################################################### //
// 我的初版 dfs
class Solution {
public:
    int ans = 0;
    int n;
    bool check(vector<int>& a, vector<int>& b){
        for(int i = 0; i < 26; i++){
            if(a[i] > b[i]) return false;
        }
        return true;
    }
    void dfs(int u, int s, vector<vector<int>>& wvec, vector<int>& lvec, vector<int>& svec){
        if(u == n){
            ans = max(ans, s);
            return;
        }
        vector<int> temp = wvec[u];
        dfs(u + 1, s, wvec, lvec, svec);
        if(check(temp, lvec)){
            for(int i = 0; i < 26; i++){
                lvec[i] -= temp[i];
            }
            dfs(u + 1, s + svec[u], wvec, lvec, svec);
            for(int i = 0; i < 26; i++){
                lvec[i] += temp[i];
            }
        }
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        this->n = words.size();
        vector<vector<int>> wvec;
        vector<int> lvec(26);
        vector<int> svec;
        for(auto c : letters) lvec[c - 'a']++;
        for(auto s : words){
            vector<int> temp(26);
            int x = 0;
            for(auto c : s){
                temp[c - 'a']++;
                x += score[c - 'a'];
            } 
            svec.push_back(x);
            wvec.push_back(temp);
        }
        dfs(0, 0, wvec, lvec, svec);
        return ans;
    }
};