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
