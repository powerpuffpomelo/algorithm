// ###################################################### 版本2 ###################################################### //
// 逆向思维，脑筋急转弯
class Encrypter {
public:
    unordered_map<char, string> k2v;
    unordered_map<string, int> cnt;

    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for(int i = 0; i < keys.size(); i++) k2v[keys[i]] = values[i];
        for(auto s : dictionary){
            string t = encrypt(s);
            if(t != "") cnt[t]++;
        }
    }
    
    string encrypt(string word1) {
        string ret;
        for(char c : word1){
            if(k2v.count(c)) ret += k2v[c];
            else return "";
        }
        return ret;
    }
    
    int decrypt(string word2) {
        return cnt[word2];
    }
};

// ###################################################### 版本3 ###################################################### //
// dfs，trie
class Encrypter {
public:
    unordered_map<char, string> k2v;
    unordered_map<string, vector<char>> v2k;

    struct node{
        bool is_end;
        vector<node*> children;
        node(){
            is_end = false;
            children.resize(26);
        }
    }*root;

    void insert(string str){
        auto p = root;
        for(char c : str){
            int u = c - 'a';
            if(!p->children[u]) p->children[u] = new node();
            p = p->children[u];
        }
        p->is_end = true;
    }

    void dfs(string& word, int i, node* p, int& ans){
        if(i == word.size()){
            if(p->is_end) ans++;
            return;
        }
        vector<char> vv = v2k[word.substr(i, 2)];
        for(char c : vv){
            int u = c - 'a';
            if(p->children[u]) dfs(word, i + 2, p->children[u], ans);
        }
    }

    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for(int i = 0; i < keys.size(); i++){
            k2v[keys[i]] = values[i];
            v2k[values[i]].push_back(keys[i]);
        } 
        root = new node();
        for(auto s : dictionary) insert(s);
    }
    
    string encrypt(string word1) {
        string ret;
        for(char c : word1){
            if(k2v.count(c)) ret += k2v[c];
            else return "";
        }
        return ret;
    }
    int decrypt(string word2) {
        auto p = root;
        int ans = 0;
        dfs(word2, 0, p, ans);
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版, trie
class Encrypter {
public:
    struct node{
        bool is_end;
        vector<node*> children;
        node(){
            is_end = false;
            children.resize(26, nullptr);
        }
    }*root;
    
    void insert(string str){
        auto p = root;
        for(char c : str){
            int u = c - 'a';
            if(!p->children[u]) p->children[u] = new node();
            p = p->children[u];
        }
        p->is_end = true;
    }
    
    //unordered_set<string> se;
    unordered_map<char, int> pos;
    unordered_map<string, vector<int>> pos_val;
    vector<char> keys_cpy;
    vector<string> values_cpy;
    
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for(int i = 0; i < keys.size(); i++) pos[keys[i]] = i;
        for(int i = 0; i < values.size(); i++) pos_val[values[i]].push_back(i);
        keys_cpy = keys;
        values_cpy = values;
        root = new node();
        for(string str : dictionary){
            insert(str);
        }
    }
    
    string encrypt(string word1) {
        string ans;
        for(auto c : word1){
            ans += values_cpy[pos[c]];
        }
        return ans;
    }
    
    int decrypt(string word2) {
        vector<node*> q, q_next;
        q.push_back(root);
        for(int i = 0; i < word2.size(); i += 2){
            string t = word2.substr(i, 2);
            // 当前位置可能的字符列表
            for(int p : pos_val[t]){
                int u = keys_cpy[p] - 'a';
                //cout << u << endl;
                for(auto no : q){
                    if(no->children[u]) q_next.push_back(no->children[u]);
                }
            }
            q = q_next;
            q_next = vector<node*>();
        }
        int ans = 0;
        for(auto p : q){
            if(p->is_end) ans++;
        }
        return ans;
    }
};