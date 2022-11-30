// ###################################################### 版本4 ###################################################### //
// 
class Trie {
public:
    struct node{
        char c;
        bool isend;
        map<char, node*> children;
        node(char _c){
            c = _c;
            isend = false;
        }
    }*root;
    
    Trie() {
        root = new node(0);
    }
    
    void insert(string word) {
        auto p = root;
        for(auto c : word){
            if(p->children.count(c)) p = p->children[c];
            else{
                p = p->children[c] = new node(c);
            }
        }
        p->isend = true;
    }
    
    bool search(string word) {
        auto p = root;
        for(auto c : word){
            if(!p->children.count(c)) return false;
            p = p->children[c];
        }
        return p->isend;
    }
    
    bool startsWith(string prefix) {
        auto p = root;
        for(auto c : prefix){
            if(!p->children.count(c)) return false;
            p = p->children[c];
        }
        return true;
    }
};


// ###################################################### 版本1 ###################################################### //
// 结构体指针
class Trie {
    struct node{
        bool is_end;
        vector<node*> children;
        node(){
            is_end = false;
            children = vector<node*>(26, nullptr);
        }
    }*root;
public:
    Trie() {
        root = new node();
    }
    
    void insert(string word) {
        node* p = root;
        for(char c : word){
            int u = c - 'a';
            if(!p->children[u]) p->children[u] = new node();
            p = p->children[u];
        }
        p->is_end = true;
    }
    
    bool search(string word) {
        node* p = root;
        for(char c : word){
            int u = c - 'a';
            if(!p->children[u]) return false;
            p = p->children[u];
        }
        return p->is_end;
    }
    
    bool startsWith(string prefix) {
        node* p = root;
        for(char c : prefix){
            int u = c - 'a';
            if(!p->children[u]) return false;
            p = p->children[u];
        }
        return true;
    }
};

// ###################################################### 版本2 ###################################################### //
// 类本身作为trie树中节点
class Trie {
    bool is_end;
    vector<Trie*> children;
public:
    Trie() {
        is_end = false;
        children = vector<Trie*>(26);
    }
    
    void insert(string word) {
        Trie* p = this;
        for(char c : word){
            int u = c - 'a';
            if(!p->children[u]) p->children[u] = new Trie();
            p = p->children[u];
        }
        p->is_end = true;
    }
    
    bool search(string word) {
        Trie* p = this;
        for(char c : word){
            int u = c - 'a';
            if(!p->children[u]) return false;
            p = p->children[u];
        }
        return p->is_end;
    }
    
    bool startsWith(string prefix) {
        Trie* p = this;
        for(char c : prefix){
            int u = c - 'a';
            if(!p->children[u]) return false;
            p = p->children[u];
        }
        return true;
    }
};

// ###################################################### 版本3 ###################################################### //
// 数组
class Trie {
public:
    static const int N = 1e5 + 10;
    int trie[N][26], cnt[N], idx = 0;
    Trie() {
        memset(trie, 0, sizeof trie);   // 需要初始化全0
        memset(cnt, 0, sizeof cnt);
    }
    
    void insert(string word) {
        int p = 0;
        for(char c : word){
            int u = c - 'a';
            if(!trie[p][u]) trie[p][u] = ++idx;
            p = trie[p][u];
        }
        cnt[p] = 1;
    }
    
    bool search(string word) {
        int p = 0;
        for(char c : word){
            int u = c - 'a';
            if(!trie[p][u]) return false;
            p = trie[p][u];
        }
        return cnt[p];
    }
    
    bool startsWith(string prefix) {
        int p = 0;
        for(char c : prefix){
            int u = c - 'a';
            if(!trie[p][u]) return false;
            p = trie[p][u];
        }
        return true;
    }
};