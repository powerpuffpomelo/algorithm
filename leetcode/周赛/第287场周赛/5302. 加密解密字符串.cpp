// ###################################################### 版本1 ###################################################### //
// 我的初版
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

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */