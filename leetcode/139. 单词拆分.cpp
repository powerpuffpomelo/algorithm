// ###################################################### 版本1 ###################################################### //
// 我的初版
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