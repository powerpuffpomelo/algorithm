// ###################################################### 版本1 ###################################################### //
// 我的初版，trie树
class Solution {
    struct node{
        bool is_end;
        vector<node*> children;
        node(){
            is_end = false;
            children = vector<node*>(26);
        }
    }*root;
public:
    void insert(string word){
        node* p = root;
        for(char c : word){
            int u = c - 'a';
            if(!p->children[u]) p->children[u] = new node();
            p = p->children[u];
        }
        p->is_end = true;
    }

    void build_trie(vector<string>& wordDict){
        root = new node();
        for(string word : wordDict) insert(word);
    }

    bool query(string str){
        node* p = root;
        for(char c : str){
            int u = c - 'a';
            if(!p->children[u]) return false;
            p = p->children[u];
        }
        return p->is_end;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        build_trie(wordDict);
        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        for(int i = 1; i <= s.size(); i++){
            for(int j = i - 1; j >= 0; j--){
                if(dp[j] && query(s.substr(j, i - j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

// ###################################################### 版本2 ###################################################### //
// 字符串哈希
class Solution {
    typedef unsigned long long ulld;
    const int P = 131;
    unordered_set<ulld> hashh;
    vector<bool> dp;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(string str : wordDict){
            ulld x = 0;
            for(char c : str){
                x = x * P + c;
            }
            hashh.insert(x);
        }
        s = ' '+ s;
        int n = s.size();
        dp = vector<bool>(n);
        dp[0] = true;
        for(int i = 0; i < n; i++){
            if(dp[i]){
                ulld x = 0;
                for(int j = i + 1; j < n; j++){
                    x = x * P + s[j];
                    if(hashh.count(x)) dp[j] = true;
                }
            }
        }
        return dp[n - 1];
    }
};