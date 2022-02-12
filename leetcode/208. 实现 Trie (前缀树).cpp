class Trie {
public:
    struct node{
        bool is_end;
        node* son[26];
        node(){
            is_end = false;
            for(int i = 0; i < 26; i++) son[i] = nullptr;
        }
    }*root;
    Trie() {
        root = new node();  // 需要写
    }
    
    void insert(string word) {
        auto p = root;
        for(char c : word){
            if(!p->son[c - 'a']) p->son[c - 'a'] = new node();
            p = p->son[c - 'a'];
        }
        p->is_end = true;
    }
    
    bool search(string word) {
        auto p = root;
        for(char c : word){
            if(!p->son[c - 'a']) return false;
            p = p->son[c - 'a'];
        }
        return p->is_end;
    }
    
    bool startsWith(string prefix) {
        auto p = root;
        for(char c : prefix){
            if(!p->son[c - 'a']) return false;
            p = p->son[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */